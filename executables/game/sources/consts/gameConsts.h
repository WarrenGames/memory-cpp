#ifndef MEMORY_CPP_GAME_CONSTS_H
#define MEMORY_CPP_GAME_CONSTS_H

#include <cstdlib>

constexpr int Margin = 64;
constexpr int IntersticeCards = 4;
constexpr int CardsByRow = 14;

constexpr std::size_t EasyPairNumber = 21;	// * 2 = 42  = 3 * 14
constexpr std::size_t MediumPairNumber = 42;  // * 2 =  84 = 6 * 14
constexpr std::size_t HardPairNumber = 63; // * 2 = 126 = 9 * 14

//To know how to display a card (back side, image side, or not displaying at all)
enum : unsigned { CardHidden, CardReveal, CardPairFound };

//the current step
enum : unsigned {WaitCard1_Choice, WaitCard2_Choice, TestIfCardsTwin, GameWon};

//Is it the chosen card 1 or the second
enum : std::size_t { Card1 , Card2, CardMax };

//to know which hint text to display
enum : std::size_t { WhatA_Pity, WellDone, GameFinished, PushSpace, DisplayMax };

constexpr char ThemesDirectory[] = "data/themes";
constexpr char CardBackThemeFile[] = "back.txt";
constexpr char VignettesThemeFile[] = "vignettes.txt";

#endif //MEMORY_CPP_GAME_CONSTS_H