#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>
#include "MenuScreen.h"
#include "Game.h"

using namespace sfSnake;

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 10.f);

std::shared_ptr<Screen> Game::Screen = std::make_shared<MenuScreen>();
std::string Game::back_loc[3]={"Images/white_back.png","Images/black_back.png","Images/brown_back.png"};
std::string Game::cell_loc[3]={"Images/white_cells.png","Images/black_cells.png","Images/brown_cells.png"};
std::string Game::snakebody_loc[3]={"Images/pink_node.png","Images/yellow_node.png","Images/green_node.png"};
std::string Game::snakehead_loc[3]={"Images/pink_head.png","Images/yellow_head.png","Images/green_head.png"};

Game::Game()
: window_(sf::VideoMode(Game::Width, Game::Height), "sfSnake")
{
	bgMusic_.openFromFile("Music/bg_music.wav");
	bgMusic_.setLoop(true);
	bgMusic_.play();
}

sf::Vector2i Game::window_pos()
{
    return window_.getPosition();
}

void Game::handleInput()
{
	sf::Event event;

	while (window_.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window_.close();
	}

	Game::Screen->handleInput(window_);
}

void Game::update(sf::Time delta)
{
	Game::Screen->update(delta);
}

void Game::render()
{
	window_.clear();
	Game::Screen->render(window_);
	window_.display();
}

void Game::run()
{
	std::srand(std::time(NULL));
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window_.isOpen())
	{
		sf::Time delta = clock.restart();
		timeSinceLastUpdate += delta;

		while (timeSinceLastUpdate > Game::TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			handleInput();
			update(TimePerFrame);
		}

		render();
	}
}