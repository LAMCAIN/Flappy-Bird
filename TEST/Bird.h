#pragma once
#include<SFML/Graphics.hpp>
#include "Globals.h"
#include <vector>
#include <cstdlib>
#include <ctime>
class Bird
{
public:
	sf::RectangleShape shape;
	float velocity_y;
	Bird();
	void update(sf::Time&); // hàm theo thời gian
	void flapBird(sf::Time&); 
	void setShoulFly(bool);
	void flap();
};


