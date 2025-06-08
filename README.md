A memory game in which you must find several pair/even cards with several themes choice.

This is the first release of memory++ game, a memory game with pair cards to pick. If you just want to play the game, you can download the following file: "Memory++_x86_64_binaries.7z" , then unzip it in a directory of your choice and run game.exe

Or you can download the source, but you'll need theses dependencies: CMake , the SDL2 library and its sub modules SDL2 image, SDL2 ttf and SDL2 mixer.
How to compile the sources:
Download the sources, unzip it in a directory of your choice, then in the main directory run cmake with for example (on linux):

'cmake -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -S./ -B../build

Then go to the build directory that follows the '-B' argument with cd ../build and run 'make all'
Choose a directory that will be the one of this game (named 'AppDir' next to make things simple). Copy the built executable ('game' or 'game.exe') in AppDir. Then download originalMemory++UnixFiles.tar.gz if you need LineFeed endlines (if you use an unixoid operating system for example) or download originalMemory++WindowsFiles.7z that contains CRLF endlines (for windows of course). Extract the selected archive in AppDir. Eventually you should have the following arborescence:

AppDir (The directory of your choice)
|-data (CRLF or LF endlines files)
|-fonts
|-textures
|game or game.exe (the file to run in order to play the game).

![main menu](/assets/mainMenuScreenShot.png)
![game with POVRay theme](/assets/povrayThemeGame1.png)
