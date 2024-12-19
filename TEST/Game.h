#pragma once 
#include<SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipe.h"
class Game
{
public:
	Game(sf::RenderWindow& window); 
	sf::RenderWindow& window;
	void startGame(); //Hàm bắt đầu Game
private:
	sf::Texture bg_texture, ground_texture; // ảnh nền 
	sf::Sprite bg_sprite, ground_sprite1, ground_sprite2;
	const int move_speed = 278;
	Bird bird; 
	Pipe pipe;
	bool is_enter_pressed, run_game;
	void draw(); // Vẽ
	void moveGround(sf::Time&); 
	void doProcessing(sf::Time&);
	sf::Font font; // font chữ
	sf::Text scoreText; // Điểm số
	sf::Text restart_text;
	bool gameStarted;
	bool gameOver;
};

