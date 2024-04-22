#pragma once

#include <SFML/Graphics.hpp>

#include "Screen.h"

namespace sfSnake
{
class MenuScreenEX : public Screen
{
public:
	MenuScreenEX();

	void handleInput(sf::RenderWindow& window) override;
	void update(sf::Time delta) override;
	void render(sf::RenderWindow& window) override;
    
    static int back_choose,cell_choose,snake_choose;

private:
	sf::Font font_;
	sf::Text snakeText_,backText_,cellText_;
};
}

