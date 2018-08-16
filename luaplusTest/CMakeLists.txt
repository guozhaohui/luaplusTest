cmake_minimum_required(VERSION 3.0)
project (luaplusTest)

set (LUAPLUS_TEST_SRCS
		luaplusTest.cpp
)

link_directories(../luaplus)
add_executable(luaplusTest  ${LUAPLUS_TEST_SRCS})
target_include_directories(luaplusTest PRIVATE ../luaplus/lua52/src)
target_include_directories(luaplusTest PRIVATE ../luaplus/)
target_link_libraries(luaplusTest lualib)
