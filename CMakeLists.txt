cmake_minimum_required(VERSION 3.28)

project(cmakemfc)

set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/__cmake/")
include(__cmake/cotire.cmake)
include(__cmake/internal_utils.cmake)
include(__cmake/global.cmake)
#include(__cmake/soui3-demo.cmake)


option(USE_UNICODE "Use Unicode" ON)

# When other libraries are using a shared version of runtime libraries,
# Google Test also has to use one.
option(SHARED_CRT "Use shared crt runtime library." ON)

# When other libraries are using a shared version of runtime libraries,
# Google Test also has to use one.
option(WCHAR_AS_DEFAULT "Use wchar_t as internal type" ON)
#
#
option(ENABLE_SOUI_CORE_LIB "Enable compile 'core' as static lib" OFF)
#
#
option(ENABLE_SOUI_COM_LIB "Enable compile 'components' as static lib" OFF)
#
#
option(XP_TOOLSET "" ON)

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 1) #https://cmake.org/cmake/help/latest/variable/CMAKE_MFC_FLAG.html

set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")

config_compiler_and_linker()

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB_RECURSE CURRENT_HEADERS *.h *.hpp)
file(GLOB_RECURSE CURRENT_SRCS  *.cpp)
file(GLOB_RECURSE CURRENT_SOUIS  ${PROJECT_SOURCE_DIR}/*.xml ${PROJECT_SOURCE_DIR}/*.idx ${PROJECT_SOURCE_DIR}/*.ico)
file(GLOB_RECURSE CURRENT_RC ${PROJECT_SOURCE_DIR}/*.rc ${PROJECT_SOURCE_DIR}/*.rc2)

source_group("Header Files" FILES ${CURRENT_HEADERS})
source_group("Source Files" FILES ${CURRENT_SRCS} mfcdemo.idl)
source_group("SoUI Resouece" FILES ${CURRENT_SOUIS})
source_group("Resource Files" FILES ${CURRENT_RC})

if (CMAKE_CL_64)
    link_directories(${PROJECT_SOURCE_DIR}/bin64)
else ()
    link_directories(${PROJECT_SOURCE_DIR}/bin)
endif ()
add_executable(cmakemfc WIN32 ${CURRENT_HEADERS} ${CURRENT_SRCS} ${CURRENT_SOUIS} ${CURRENT_RC} mfcdemo.idl)

set_target_properties(cmakemfc PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
#add_dependencies(cmakemfc soui-sys-resource ${COM_LIBS})
#target_link_libraries(cmakemfc soui3 utilities mhook smiley)
set_target_properties (cmakemfc PROPERTIES
    FOLDER cmakemfc
)
cotire(cmakemfc)
