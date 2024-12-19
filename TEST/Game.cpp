#include<SFML/Graphics.hpp>
#include "Globals.h"
#include"Game.h"
#include"Bird.h"
#include "Pipe.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

Bird bird;
std::vector<Pipe> pipes;
int score = 0;
int frameCounter = 0;

Game::Game(sf::RenderWindow& window) : window(window),
run_game(true),
is_enter_pressed(false) // gán giá trị false
{
	window.setFramerateLimit(60); // cố định FPS game
	bg_texture.loadFromFile("flap/bg.png"); // tải ảnh nền
	bg_sprite.setTexture(bg_texture);
	bg_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR); // cố định kích thước
	bg_sprite.setPosition(0.f, -250.f ); // cố định vị trí ảnh

	ground_texture.loadFromFile("flap/ground.png"); // tải ảnh sàn
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);

	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR); // cố định kích thước
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);

	ground_sprite1.setPosition(0, 610); // cố định vị trí
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 610);


	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) 
	{
		std::cerr << "Error loading font!" << std::endl;
	}
	font.loadFromFile("flap/arial.ttf");
	scoreText.setFont(font);
	scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(580, 610);
	scoreText.setString("Score: " + to_string(score));
}

void Game::startGame() // giải thích hàm startGame
{
	sf::Clock clock;
	while (window.isOpen()) // vòng lặp khi bắt đầu trò chơi
	{
		sf::Time dt = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{
				is_enter_pressed = true;
				bird.flapBird(dt); // Cho chim "vỗ cánh" khi nhấn phím Space
			}
		}

		doProcessing(dt);
		bird.update(dt);
		moveGround(dt);
		draw();
		for (auto& pipe : pipes)
		{
			pipe.update();
			if (pipe.checkCollision(bird)) // Kiểm tra va chạm
			{
				cout << "Game Over! Final Score: " << score;
				return;
			}
		};
		// Xóa các ống không còn hiển thị trên màn hình
		pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [](Pipe& pipe) { return pipe.isOffScreen(); }), pipes.end());
		window.display();
	}
}


void Game::draw() // giải thích hàm vẽ
 {
	window.draw(bg_sprite); // vẽ background
	window.draw(ground_sprite1); // vẽ phần nền 1
	window.draw(ground_sprite2); // vẽ phàn nền 2
	window.draw(bird.shape); // vẽ chim
	for (auto& pipe : pipes) // duyệt qua tất cả các ống 
	{
		window.draw(pipe.Pipeup); // vẽ ống dưới
		window.draw(pipe.Pipedown); // vẽ ống trên
		pipe.update(); // cập nhật ống
		if (pipe.isPassed(bird)) // kiểm tra va chạm
		{
			score++; // nếu vượt qua thì cộng điểm
			pipe.passed = true;
		}
	}
	if (!run_game) // nếu game kết thúc
	{
		window.draw(restart_text); // viết thông báo restart
	}
}

void Game::moveGround(sf::Time& dt) // giải thích hàm moveGround
{
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0.f);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0.f);

	if (ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width < 0)
	{
		ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width, 610);
	}


	if (ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width < 0)
	{
		ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, 610);
	}
}

void Game::doProcessing(sf::Time& dt) // giải thích hàm doProcessing
{
	if (is_enter_pressed)
	{
		moveGround(dt);

		if (frameCounter % SPAWN_FREQUENCY == 0) 
		{
			pipes.push_back(Pipe());
		}
		frameCounter++;
	}
}


