#pragma once

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//screen consts
const int BoardSize = 11;
const int CircleSize = 30;
const int FontSize = 100;

//text const
const int X_TextAdd = 550;
const int Y_TextAdd = 100;

//circles consts
const int X_CircleDistance = 75;
const int Y_CircleDistance = 70;
const int CircleLeftOddDistance = 70;
const int CircleLeftEvenDistance = 35;

//bfs directions
const int dRow[]     = { 1, 0, 1, 0, -1, -1 };
const int dColOdd[]  = { 0, -1, 1, 1, 0, 1 };
const int dColEven[] = { -1, -1, 0, 1, -1, 0 };
const int amountOfDir = 6;

using BoardVector = vector<std::vector<CircleShape>>;

const Vector2i StartPos = {5, 5};    //cat start point

enum TEXTS {
    TITLE, LEVEL, STEPS, UNDO
};

const IntRect catRectSprite(362, 62, 60, 60);   //default Rect of sprite
