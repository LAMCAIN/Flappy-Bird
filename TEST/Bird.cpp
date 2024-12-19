#include<SFML/Graphics.hpp>
#include "Globals.h"
#include"Game.h"
#include"Bird.h"
#include "Pipe.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Bird::Bird() // tạo hình cho Bird
{
	shape.setSize(sf::Vector2f(BIRD_SIZE, BIRD_SIZE)); // tạo khuôn cho Bird (hình vuông)
	shape.setFillColor(sf::Color::Red); // Đổ màu cho Bird (màu đỏ)
	shape.setPosition(100, WIN_HEIGHT / 2); // Xác định vị trí của Bird khi bắt đầu trò chơi
	velocity_y = 0.0f; // vận tốc ban đầu của Bird theo trục y
}

void Bird::flapBird(sf::Time & dt) // tạo khả năng di chuyển cho Bird
{
	velocity_y = flap_stregth; // vận tốc bằng với flap_strength
	shape.move(0, -flap_stregth * dt.asSeconds()); 
}

void Bird::update(sf::Time& dt)
{
	velocity_y += gravity; // vận tốc theo thời gian
	shape.move(0, velocity_y);

	if (shape.getPosition().y < 0) // Kiếm soát Bird không vượt ra khỏi phạm vi màn hình
	{
		shape.setPosition(100, 0);
	}

	if (shape.getPosition().y > 600) // Kiếm soát Bird không vượt ra khỏi phạm vi màn hình
	{
		shape.setPosition(100, 0);
	}
}
