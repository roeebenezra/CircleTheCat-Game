#pragma once

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;

const int BoardSize = 11;
const int CircleSize = 25;
const int FontSize = 80;

const int X_TextAdd = 450;
const int Y_TextAdd = 150;

const int X_CircleDistance = 60;
const int Y_CircleDistance = 55;
const int CircleLeftOddDistance = 60;
const int CircleLeftEvenDistance = 20;

const std::vector<std::string> Texts = { "Circle The Cat", "Level: ", "Steps: " };
