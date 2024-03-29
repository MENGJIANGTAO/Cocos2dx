#include "GameScene.h"
#include "MenuScene.h"
#include "Tools.h"
#include "global.h"
#include "GameOver.h"
#include "VisibleRect.h"

#define MUSCI_BG "adventure.mp3"

using namespace CocosDenshion;
USING_NS_CC;

#define FIX_POS(_pos, _min, _max) \
    if (_pos < _min)        \
    _pos = _min;        \
else if (_pos > _max)   \
    _pos = _max;        \

Scene *GameScene::createScene() {
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init() {
    if (!Layer::init()) {
        return false;
    }

    Size size = Director::sharedDirector()->getWinSize();

    dead = false;
    g_score = 0;
    
    joystick1 = Sprite::create("joystick1.png");
    joystick1->setOpacity(191);
    joystick1->setAnchorPoint(ccp(0, 0));
    joystick1->setPosition(ccp(0, 0));
    radius = joystick1->getContentSize().width / 2;
    center = ccp(radius, radius);
    this->addChild(joystick1);

    joystick = Sprite::create("joystick2.png");
    joystick->setPosition(ccp(center.x, center.y));
    this->addChild(joystick, 2);

    MenuItemFont::setFontSize(22);
    MenuItemFont::setFontName("American Typewriter");
    std::string str = "";

    str = "System";
    // add system menu
    MenuItemFont *systemMenu = MenuItemFont::create(str.c_str(), this, menu_selector(GameScene::menuReturnCallBack));
    Menu *menu = Menu::create(systemMenu, NULL);
    menu->setPosition(ccp(0, 0));
    systemMenu->setAnchorPoint(ccp(1, 0));
    systemMenu->setPosition(ccp(size.width, 0));
    this->addChild(menu, 1);

    Texture2D *texture = TextureCache::sharedTextureCache()->addImage("plane.png");
    plane = Sprite::createWithTexture(texture);
    plane->setPosition(ccp(size.width / 2, size.height / 2));
    this->addChild(plane, 0);

    this->schedule(schedule_selector(GameScene::flying));
    this->schedule(schedule_selector(GameScene::createBullet));
    this->schedule(schedule_selector(GameScene::checkBullet));
    this->schedule(SEL_SCHEDULE(&GameScene::saveTime),1);
    
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic(MUSCI_BG);
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
    SimpleAudioEngine::getInstance()->playBackgroundMusic(MUSCI_BG, true);
    
    return true;
}

void GameScene::onEnter() {
    Layer::onEnter();
    if(!g_touchControl)
    {
        joystick->setVisible(g_touchControl);
        joystick1->setVisible(g_touchControl);
    }
    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    Device::setAccelerometerEnabled(true);
    auto listener2 = EventListenerAcceleration::create(CC_CALLBACK_2(GameScene::onAcceleration, this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
}

void GameScene::onExit() {
    Layer::onExit();
    Device::setAccelerometerEnabled(false);
}

bool GameScene::onTouchBegan(Touch* touch, Event* event) {
//    log("touch");
    Point location = touch->getLocationInView();
    Point convertedLocation = Director::sharedDirector()->convertToGL(location);
    if (g_touchControl) {
        Rect rect = joystick->boundingBox();
        if (rect.containsPoint(convertedLocation)) {
            isFlying = true;
        }
    }
    return true;
}


void GameScene::onTouchMoved(Touch* touch, Event* event) {
//    log("moved");
    Point location = touch->getLocationInView();
    Point convertedLocation = Director::sharedDirector()->convertToGL(location);

    bool inRange = pow(center.x - convertedLocation.x, 2) + pow(center.y - convertedLocation.y, 2) < pow(radius, 2);
    if (isFlying && inRange && g_touchControl) {
        CCPoint position = plane->getPosition();
        joystick->setPosition(convertedLocation);

        float radius1 = radius * 2 / 6;
        float side = radius * 2 / 3;

        if (triangleContainPoint(center.x, center.y, center.x - radius1, center.y + radius1, center.x + radius1, center.y + radius1, convertedLocation.x, convertedLocation.y)
                || Rect(center.x - radius1, center.y + radius1, side, side).containsPoint(convertedLocation)) {
            speedX = 0;
            speedY = 1;
        }
        else if (triangleContainPoint(center.x, center.y, center.x - radius1, center.y - radius1, center.x + radius1, center.y - radius1, convertedLocation.x, convertedLocation.y)
                || Rect(center.x - radius1, center.y - radius1 - side, side, side).containsPoint(convertedLocation)) {
            speedX = 0;
            speedY = -1;
        }
        else if (triangleContainPoint(center.x, center.y, center.x - radius1, center.y + radius1, center.x - radius1, center.y - radius1, convertedLocation.x, convertedLocation.y)
                || Rect(center.x - radius1 - side, center.y - radius1, side, side).containsPoint(convertedLocation)) {
            speedX = -1;
            speedY = 0;
        }
        else if (triangleContainPoint(center.x, center.y, center.x + radius1, center.y + radius1, center.x + radius1, center.y - radius1, convertedLocation.x, convertedLocation.y)
                || Rect(center.x + radius1 + side, center.y - radius1, side, side).containsPoint(convertedLocation)) {
            speedX = 1;
            speedY = 0;
        }
        else if (convertedLocation.x - center.x > 0 && convertedLocation.y - center.y > 0) {
            speedX = 0.7f;
            speedY = 0.7f;
        }
        else if (convertedLocation.x - center.x < 0 && convertedLocation.y - center.y > 0) {
            speedX = -0.7f;
            speedY = 0.7f;
        }
        else if (convertedLocation.x - center.x < 0 && convertedLocation.y - center.y < 0) {
            speedX = -0.7f;
            speedY = -0.7f;
        }
        else if (convertedLocation.x - center.x > 0 && convertedLocation.y - center.y < 0) {
            speedX = 0.7f;
            speedY = -0.7f;
        }
    }
}

void GameScene::onTouchEnded(Touch* touch, Event* event) {
    isFlying = false;
    joystick->setPosition(center);
    speedX = speedY = 0;
}

void GameScene::onAcceleration(Acceleration* acc, Event* event) {
    if (!g_touchControl) {
        auto ballSize = plane->getContentSize();

        auto pos = plane->getPosition();

        pos.x += acc->x * 9.81f;
        pos.y += acc->y * 9.81f;

        FIX_POS(pos.x, (VisibleRect::left().x + ballSize.width / 2.0), (VisibleRect::right().x - ballSize.width / 2.0));
        FIX_POS(pos.y, (VisibleRect::bottom().y + ballSize.height / 2.0), (VisibleRect::top().y - ballSize.height / 2.0));
        plane->setPosition(pos);
    }
}

void GameScene::menuReturnCallBack(cocos2d::Ref* ref) {
    SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
    Scene *scene = MenuScene::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFlipX::create(1.2f, scene));
}

void GameScene::createBullet(float dt) {
    if (bullets.size() > g_bulletNumber) {
        return;
    }

    Texture2D *texture = TextureCache::sharedTextureCache()->addImage("bullet.png");
    Sprite *bullet = Sprite::createWithTexture(texture);
    this->addChild(bullet, 0);
    bullets.push_back(bullet);
    log("new bullet");
    float x, y;
    int speedX, speedY;
    Size size = Director::sharedDirector()->getWinSize();
    int entrance = abs(rand() % 4);

    switch (entrance) {
        case 0:
            x = abs(rand() % (int) size.width);
            y = size.height - bullet->boundingBox().size.height;
            speedX = rand() % 3;
            speedY = (abs(rand() % 3 + 1))*-1;
            break;
        case 1:
            x = abs(rand() % (int) size.width);
            y = bullet->boundingBox().size.height;
            speedX = rand() % 3;
            speedY = abs(rand() % 3 + 1);
            break;
        case 2:
            x = bullet->boundingBox().size.width;
            y = abs(rand() % (int) size.height);
            speedX = abs(rand() % 3 + 1);
            speedY = rand() % 3;
            break;
        case 3:
            x = size.width - bullet->boundingBox().size.width;
            y = abs(rand() % (int) size.height);
            speedX = abs(rand() % 3 + 1)*-1;
            speedY = rand() % 3;
            break;
    }
    ActionInterval *action = MoveBy::create(0.1f, ccp(speedX, speedY));
    int fllow = abs(rand() % 2);
    if(fllow == 0)
    {
        bullet->setPosition(ccp(x, y));
    }
    else
    {
        x = abs(rand() % (int)plane->getPosition().x);
        y = abs(rand() % (int)plane->getPosition().y);
        bullet->setPosition(ccp(x,y));
    }
    bullet->runAction(RepeatForever::create(action));
}

void GameScene::checkBullet(float dt) {
    if (!plane->isVisible()) {
        return;
    }
    Size size = Director::sharedDirector()->getWinSize();
    Rect screen = Rect(0, 0, size.width, size.height);
    Rect planeBox = plane->boundingBox();

    for (std::vector<cocos2d::Sprite*>::iterator bitr = bullets.begin(); bitr != bullets.end();) {
        Sprite *bullet = *bitr;
        Point position = bullet->getPosition();
        //        Rect bulletBox = bullet->boundingBox();
        //        sp1->boundingBox().containsPoint(touch->getStartLocation())
        if (planeBox.containsPoint(position)) {
            this->unschedule(SEL_SCHEDULE(&GameScene::saveTime));
            dead = true;
            this->removeChild(bullet, true);
            bitr = bullets.erase(bitr);

            plane->setVisible(false);

            Texture2D *texture = TextureCache::sharedTextureCache()->addImage("explosion.png");
            Animation *animatin = Animation::create();
            animatin->setDelayPerUnit(0.2f);
            for (int i = 0; i < 4; i++) {
                animatin->addSpriteFrameWithTexture(texture, Rect(i * 32, 0, 32, 32));
            }
            Animate *animate = Animate::create(animatin);
            FiniteTimeAction *animateOver = CCCallFunc::create(this, callfunc_selector(GameScene::explosionEndDid));
            FiniteTimeAction *seq = Sequence::create(animate, animateOver, NULL);

            explosion = Sprite::createWithTexture(texture, Rect(0, 0, 32, 32));
            this->addChild(explosion);
            explosion->setPosition(plane->getPosition());
            explosion->runAction(seq);
              
            //sound
            if(g_playSound)
            {
//                CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("explosion.wav");
                log("play sound");
//                CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("explosion.wav");
                SimpleAudioEngine::getInstance()->playBackgroundMusic("explosion.WAV", false);
            }
            break;
        } else if (!screen.containsPoint(position)) {
            this->removeChild(bullet, true);
            bitr = bullets.erase(bitr);
            log("bullet dead!");
        } else {
            bitr++;
//            log("everything going on.");
        }
    }
}

void GameScene::flying(float dt) {
    if (isFlying && (speedX != 0 || speedY != 0)) {
        Point position = ccp(plane->getPosition().x + speedX, plane->getPosition().y + speedY);
        Size size = Director::sharedDirector()->getWinSize();
        Rect rect = Rect(0, 0, size.width, size.height);
        if (rect.containsPoint(position));
        {
            plane->setPosition(position);
        }
    }
}

void GameScene::saveTime(long dt) {
    if (!dead) {
        g_gameTime += dt;
        g_score++;
    }
}

void GameScene::explosionEndDid() {
    log("Game Over");
    explosion->setVisible(false);
    Scene *scene  = GameOver::createScene();
    Director::sharedDirector()->replaceScene(CCTransitionFadeUp::create(1.5f,scene));
}