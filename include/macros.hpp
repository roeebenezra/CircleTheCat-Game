#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int BoardSize = 11;
const int CircleSize = 30;
const int FontSize = 100;

const int X_TextAdd = 550;
const int Y_TextAdd = 100;

const int X_CircleDistance = 75;
const int Y_CircleDistance = 70;
const int CircleLeftOddDistance = 70;
const int CircleLeftEvenDistance = 35;

//const int dRow[]     = { 0, 1, 1, 0, -1, -1 };
//const int dColOdd[]  = { -1, -1, 0, 1, 0, -1 };
//const int dColEven[] = { -1, -1, 0, 1, 0, -1 };
const int dRow[]     = { 1, 0, 1, 0, -1, -1 };
const int dColOdd[]  = { 0, -1, 1, 1, 0, 1 };
const int dColEven[] = { -1, -1, 0, 1, -1, 0 };
const int amountOfDir = 6;

using BoardVector = vector<std::vector<CircleShape>>;
const Vector2i StartPos = {5, 5};        //cat start point

enum TEXTS {
    TITLE, LEVEL, STEPS, UNDO
};
