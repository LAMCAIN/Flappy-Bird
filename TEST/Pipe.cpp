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

Pipe::Pipe()
{
	passed = false; // gán giá trị không đúng cho passed
	pipe_speed = pipe_velocity; // vận tốc của ống

	// Tạo shape cho Pipedown
	Pipedown.setSize(sf::Vector2f(PIPE_WIDTH, rand() % (WIN_HEIGHT - PIPE_GAP)));
	Pipedown.setFillColor(sf::Color::Green);
	Pipedown.setPosition(WIN_WIDTH, 0);

	// Tạo shape cho Pipeup
	Pipeup.setSize(sf::Vector2f(PIPE_WIDTH, WIN_HEIGHT - Pipedown.getSize().y - PIPE_GAP));
	Pipeup.setFillColor(sf::Color::Green);
	Pipeup.setPosition(WIN_WIDTH, Pipedown.getSize().y + PIPE_GAP - 155);
}

void Pipe::update() // hàm ống di chuyển
{
	Pipedown.move(pipe_speed, 0);
	Pipeup.move(pipe_speed, 0);
}

bool Pipe::isOffScreen() 
{
	return Pipedown.getPosition().x + PIPE_WIDTH < 0;
}

bool Pipe::checkCollision(Bird& bird) // hàm kiêm tra va chạm
{
	return bird.shape.getGlobalBounds().intersects(Pipedown.getGlobalBounds()) ||
		bird.shape.getGlobalBounds().intersects(Pipeup.getGlobalBounds());
}

bool Pipe::isPassed(Bird& bird) 
{
	return !passed && bird.shape.getPosition().x > Pipedown.getPosition().x + PIPE_WIDTH;
}