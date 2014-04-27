#include <cstdlib>
#include <iostream>
extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
using namespace std;
int main(int argc, char *argv[]){
	lua_State *L;
	L = lua_open();
	luaL_openlibs(L);
	luaL_dofile(L, "test.lua");
	system("PAUSE");
	return 0;
}