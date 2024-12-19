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

int main() // hàm chính
{
	sf::RenderWindow win(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "Flappy Bird"); // tạo cửa sổ Game
	Game game(win); // tạo hàm game mang tính chất của class Game
	game.startGame();
	return 0;
}