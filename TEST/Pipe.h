#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Bird.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Pipe
{
public:
	sf::RectangleShape Pipeup; // ống dưới
	sf::RectangleShape Pipedown; // ống trên
	float pipe_speed; // tốc dộ ống
	bool passed; // toán tử
	Pipe();
	void update();
	bool isOffScreen();
	bool isPassed(Bird&);
	bool checkCollision(Bird&);
	std::string toString(int);
};

