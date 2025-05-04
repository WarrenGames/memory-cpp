cmake_minimum_required( VERSION 3.13 )

project( game LANGUAGES CXX )

set( HEADERS
	sources/mainMenu/mainMenuContext.h
	sources/mainMenu/buttons/optionsButton.h
	sources/mainMenu/buttons/skillButtons.h
	sources/mainMenu/mainMenuElements.h
	sources/mainMenu/mainMenuConsts.h
	sources/mainMenu/vignettesAnimation/vignettesGraphics.h
	sources/mainMenu/vignettesAnimation/vignetteInfos.h
	sources/mainMenu/vignettesAnimation/vignettesAnimation.h
	sources/mainMenu/themeSelection/themeSelectionButtons.h
	sources/mainMenu/themeSelection/themesInterface.h
	sources/game/textures/commentsTexts.h
	sources/game/textures/gameTextures.h
	sources/game/textures/cardsPickingTexts.h
	sources/game/textures/vignettesTextures.h
	sources/game/global/globalGameObject.h
	sources/game/global/gameContext.h
	sources/game/numeric/vignetteClickFinder.h
	sources/game/numeric/vignettesRandomSelector.h
	sources/game/numeric/numericData.h
	sources/game/replayMenu/replayButton.h
	sources/consts/filesConsts.h
	sources/consts/gameConsts.h
	sources/consts/fontsSizes.h
	sources/consts/colors.h
	sources/consts/themesConsts.h
	sources/consts/globalConsts.h
	sources/optionsMenu/optionsMenuContext.h
	sources/optionsMenu/languageChoice.h
	sources/optionsMenu/languagesList.h
	sources/crossLevel/essentials.h
	sources/crossLevel/gameOptions.h
	sources/crossLevel/inputs.h
	sources/filesSetup/getFilesPaths.h
	sources/filesSetup/setupFiles.h
	sources/startGame/initializeRenderer.h
	sources/startGame/initializeLogFiles.h
	sources/startGame/initializePrefPath.h
	sources/startGame/initializeSDL2.h
)

set( SOURCES
	sources/mainMenu/buttons/skillButtons.cpp
	sources/mainMenu/buttons/optionsButton.cpp
	sources/mainMenu/mainMenuElements.cpp
	sources/mainMenu/vignettesAnimation/vignetteInfos.cpp
	sources/mainMenu/vignettesAnimation/vignettesAnimation.cpp
	sources/mainMenu/vignettesAnimation/vignettesGraphics.cpp
	sources/mainMenu/themeSelection/themeSelectionButtons.cpp
	sources/mainMenu/themeSelection/themesInterface.cpp
	sources/mainMenu/mainMenuContext.cpp
	sources/game/textures/commentsTexts.cpp
	sources/game/textures/vignettesTextures.cpp
	sources/game/textures/gameTextures.cpp
	sources/game/textures/cardsPickingTexts.cpp
	sources/game/global/globalGameObject.cpp
	sources/game/global/gameContext.cpp
	sources/game/numeric/numericData.cpp
	sources/game/numeric/vignetteClickFinder.cpp
	sources/game/numeric/vignettesRandomSelector.cpp
	sources/game/replayMenu/replayButton.cpp
	sources/optionsMenu/languageChoice.cpp
	sources/optionsMenu/languagesList.cpp
	sources/optionsMenu/optionsMenuContext.cpp
	sources/crossLevel/gameOptions.cpp
	sources/crossLevel/inputs.cpp
	sources/crossLevel/essentials.cpp
	sources/filesSetup/setupFiles.cpp
	sources/filesSetup/getFilesPaths.cpp
	sources/startGame/main.cpp
	sources/startGame/initializeLogFiles.cpp
	sources/startGame/initializePrefPath.cpp
	sources/startGame/initializeSDL2.cpp
	sources/startGame/initializeRenderer.cpp
)

add_executable(	
	${PROJECT_NAME} 
	WIN32
	${SOURCES} 
	${HEADERS} 
	${INC_DIRS}
)

source_group( TREE ${CMAKE_CURRENT_SOURCE_DIR}
	FILES ${HEADERS} ${SOURCES}
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE ${SDL2_INCLUDE_DIRS}
	PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS}
	PRIVATE ${SDL2_TTF_INCLUDE_DIRS}
	PRIVATE sources
	PRIVATE ../../libraries/genericLib/sources
	PRIVATE ../../libraries/sdl2_wrapper/sources
)

target_link_libraries(	
	${PROJECT_NAME}
	PRIVATE sdl2_wrapper
	PRIVATE genericLib
	PRIVATE ${SDL2_LIBRARIES} 
	PRIVATE ${SDL2_IMAGE_LIBRARIES} 
	PRIVATE ${SDL2_TTF_LIBRARIES} 
)


set_target_properties(
	${PROJECT_NAME} 
	PROPERTIES 
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED YES 
	CXX_EXTENSIONS NO 
	LINKER_LANGUAGE CXX
)
