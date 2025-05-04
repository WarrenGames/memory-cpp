cmake_minimum_required(VERSION 3.13)

project( MemoryC++ LANGUAGES CXX )

set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmakeModules)

if( UNIX )
	include(GNUInstallDirs)
endif( UNIX )

if(WIN32)
    set( SDL2_DIR "" )
endif(WIN32)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_subdirectory(executables/game)
add_subdirectory(libraries/genericLib)
add_subdirectory(libraries/sdl2_wrapper)
