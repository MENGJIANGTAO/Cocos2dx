#include "fileUnit.h"

USING_NS_CC;

Scene *fileUnit::createScene()
{
	auto scene = Scene::create();
	auto layer = fileUnit::create();
	scene->addChild(layer);
	return scene;
}

bool fileUnit::init()
{
	if (!Layer::init())
	{
		return false;
	}
	visibleSize = Director::getInstance()->getVisibleSize();

	char temp[100] = { 0 };
	std::string fileName = FileUtils::sharedFileUtils()->getWritablePath() + "test.txt";
	FILE* fp = fopen(fileName.c_str(), "wb+");
	if (fp)
	{
		for (int i = 0; i < 5; i++)
		{
			sprintf(temp, "number%d:%d", i,10 + i);
			fwrite(temp, 1, strlen(temp), fp);
		}
		fclose(fp);
	}

	if (fileName.length()>0)
	{
		fp = fopen(fileName.c_str(), "rb");
	}


	char str[100] = { 0 };
	if (fp)
	{
		for (size_t i = 0; i < 5; i++)
		{
			int size = fread(str, 1, strlen(temp), fp);
			if (size > 0)
			{

				LabelBMFont *label = LabelBMFont::create("x", "fonts/myfont.fnt");

				label->setPosition(visibleSize.width / 2, visibleSize.height * 0.8 - i*30);
				addChild(label);
				label->setString(str);
			}
		}
	}
	fclose(fp);

	//createFile();
	//readFile();
}

void fileUnit::createFile()
{
	//fp = fopen(fileName.c_str(), "wb+");
	//if (fp)
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		sprintf(temp, "number%d:%d", 100 + i);
	//		fwrite(temp,1,strlen(temp),fp);
	//	}
	//	fclose(fp);
	//}
}

void fileUnit::readFile()
{
	//if (fileName.length()>0)
	//{
	//	fp = fopen(fileName.c_str(), "rb");
	//}
	//if (fp)
	//{
	//	for (size_t i = 0; i < 5; i++)
	//	{
	//		int size = fread(str, 1, strlen(temp), fp);
	//		if (size > 0)
	//		{
	//			label->setString(str);
	//		}
	//	}
	//}
	//fclose(fp);
}