#ifndef MEMORY_CPP_GAME_GLOBAL_GAME_CONTEXT_H
#define MEMORY_CPP_GAME_GLOBAL_GAME_CONTEXT_H

#include <cstdlib>

struct Essentials;
struct GameOptions;
class GlobalGameObject;
class ReplayButton;

namespace game{

void newGameContext(Essentials& essentials, const GameOptions& gameOptions);

void quitGameWithInputs(Essentials& essentials, bool& quitGame);

void drawEverything(Essentials& essentials, GlobalGameObject& gameObject);

void quitGameInCaseOfSuccess(const GlobalGameObject& gameObject, bool& quitGame);

}

namespace sum{

void drawGameSum(Essentials& essentials, const GlobalGameObject& gameObject);

void drawEverything(Essentials& essentials, const GlobalGameObject& gameObject, const ReplayButton& replayButton);

void replayGame(const ReplayButton& replayButton, bool& quitSum);

}

#endif //MEMORY_CPP_GAME_GLOBAL_GAME_CONTEXT_H