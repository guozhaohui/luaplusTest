cmake_minimum_required(VERSION 3.0)
project (luaplus)

set (LUAPLUS_SRCS
		LuaAutoBlock.h
		LuaCall.h
		LuaCall.inl
		LuaFunction.h
		LuaHelper.h
		LuaHelper_Object.h
		LuaHelper_StackObject.h
		LuaLink.h
		LuaObject.h
		LuaObject.inl
		LuaPlus.cpp
		LuaPlus.h
		LuaPlusAddons.c
		LuaPlusCD.h
		LuaPlusConfig.h
		LuaPlusInternal.h
		LuaStackObject.h
		LuaStackObject.inl
		LuaStackTableIterator.h
		LuaStackTableIterator.inl
		LuaState.h
		LuaState.inl
		LuaStateOutFile.h
		LuaStateOutString.h
		LuaState_DumpObject.cpp
		LuaTableIterator.h
)

##################################################################
set (LUA52_SRCS
		lua52/src/lapi.c
		lua52/src/lapi.h
		lua52/src/lauxlib.c
		lua52/src/lauxlib.h
		lua52/src/lbaselib.c
		lua52/src/lbitlib.c
		lua52/src/lcode.c
		lua52/src/lcode.h
		lua52/src/lcorolib.c
		lua52/src/lctype.c
		lua52/src/lctype.h
		lua52/src/ldblib.c
		lua52/src/ldebug.c
		lua52/src/ldebug.h
		lua52/src/ldo.c
		lua52/src/ldo.h
		lua52/src/ldump.c
		lua52/src/lfunc.c
		lua52/src/lfunc.h
		lua52/src/lgc.c
		lua52/src/lgc.h
		lua52/src/linit.c
		lua52/src/liolib.c
		lua52/src/llex.c
		lua52/src/llex.h
		lua52/src/llimits.h
		lua52/src/lmathlib.c
		lua52/src/lmem.c
		lua52/src/lmem.h
		lua52/src/loadlib.c
		lua52/src/lobject.c
		lua52/src/lobject.h
		lua52/src/lopcodes.c
		lua52/src/lopcodes.h
		lua52/src/loslib.c
		lua52/src/lparser.c
		lua52/src/lparser.h
		lua52/src/lstate.c
		lua52/src/lstate.h
		lua52/src/lstring.c
		lua52/src/lstring.h
		lua52/src/lstrlib.c
		lua52/src/ltable.c
		lua52/src/ltable.h
		lua52/src/ltablib.c
		lua52/src/ltm.c
		lua52/src/ltm.h
		#lua52/src/lua.c
		lua52/src/lua.h
		lua52/src/lua.hpp
		#lua52/src/luac.c
		lua52/src/luaconf.h
		lua52/src/lualib.h
		lua52/src/lundump.c
		lua52/src/lundump.h
		lua52/src/lvm.c
		lua52/src/lvm.h
		lua52/src/lzio.c
		lua52/src/lzio.h
)

##################################################################
set (LUA52_LUAPLUS_SRCS
		lua52-luaplus/src/lapi.c
		lua52-luaplus/src/lapi.h
		lua52-luaplus/src/lauxlib.c
		lua52-luaplus/src/lauxlib.h
		lua52-luaplus/src/lbaselib.c
		lua52-luaplus/src/lbitlib.c
		lua52-luaplus/src/lcode.c
		lua52-luaplus/src/lcode.h
		lua52-luaplus/src/lcorolib.c
		lua52-luaplus/src/lctype.c
		lua52-luaplus/src/lctype.h
		lua52-luaplus/src/ldblib.c
		lua52-luaplus/src/ldebug.c
		lua52-luaplus/src/ldebug.h
		lua52-luaplus/src/ldo.c
		lua52-luaplus/src/ldo.h
		lua52-luaplus/src/ldump.c
		lua52-luaplus/src/lfunc.c
		lua52-luaplus/src/lfunc.h
		lua52-luaplus/src/lgc.c
		lua52-luaplus/src/lgc.h
		lua52-luaplus/src/linit.c
		lua52-luaplus/src/liolib.c
		lua52-luaplus/src/llex.c
		lua52-luaplus/src/llex.h
		lua52-luaplus/src/llimits.h
		lua52-luaplus/src/lmathlib.c
		lua52-luaplus/src/lmem.c
		lua52-luaplus/src/lmem.h
		lua52-luaplus/src/loadlib.c
		lua52-luaplus/src/lobject.c
		lua52-luaplus/src/lobject.h
		lua52-luaplus/src/lopcodes.c
		lua52-luaplus/src/lopcodes.h
		lua52-luaplus/src/loslib.c
		lua52-luaplus/src/lparser.c
		lua52-luaplus/src/lparser.h
		lua52-luaplus/src/lstate.c
		lua52-luaplus/src/lstate.h
		lua52-luaplus/src/lstring.c
		lua52-luaplus/src/lstring.h
		lua52-luaplus/src/lstrlib.c
		lua52-luaplus/src/ltable.c
		lua52-luaplus/src/ltable.h
		lua52-luaplus/src/ltablib.c
		lua52-luaplus/src/ltm.c
		lua52-luaplus/src/ltm.h
		#lua52-luaplus/src/lua.c
		lua52-luaplus/src/lua.h
		lua52-luaplus/src/lua.hpp
		#lua52-luaplus/src/luac.c
		lua52-luaplus/src/luaconf.h
		lua52-luaplus/src/lualib.h
		lua52-luaplus/src/lundump.c
		lua52-luaplus/src/lundump.h
		lua52-luaplus/src/lvm.c
		lua52-luaplus/src/lvm.h
		lua52-luaplus/src/lzio.c
		lua52-luaplus/src/lzio.h
)

add_library ( lualib STATIC ${LUA52_SRCS} ${LUAPLUS_SRCS})
#add_library ( lualib SHARED ${LUA52_SRCS} ${LUAPLUS_SRCS})
target_include_directories(lualib PRIVATE ./lua52/src)

add_library ( lualib-plus STATIC ${LUA52_LUAPLUS_SRCS} ${LUAPLUS_SRCS})
#add_library ( lualib-plus SHARED ${LUA52_LUAPLUS_SRCS} ${LUAPLUS_SRCS})
target_include_directories(lualib-plus PRIVATE ./lua52-luaplus/src)

add_executable(lua  ${LUA52_LUAPLUS_SRCS} ${LUAPLUS_SRCS} lua52-luaplus/src/lua.c)
target_include_directories(lua PRIVATE ./lua52-luaplus/src)

