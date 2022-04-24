#pragma once

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

const int BoardSize = 11;
const int CircleSize = 35;
const int FontSize = 100;

const int X_TextAdd = 620;
const int Y_TextAdd = 200;

const int X_CircleDistance = 80;
const int Y_CircleDistance = 75;
const int CircleLeftOddDistance = 60;
const int CircleLeftEvenDistance = 20;

const std::vector<std::string> Texts = { "Circle The Cat", "Level: ", "Steps: " };
