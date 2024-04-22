#include <SFML/Graphics.hpp>
#include <memory>

#include "GameScreen.h"
#include "MenuScreenEX.h"
#include "Game.h"

#define sf_Color_Brown sf::Color(90,57,18)

using namespace sfSnake;
int MenuScreenEX::back_choose=0,MenuScreenEX::cell_choose=0,MenuScreenEX::snake_choose=0;
MenuScreenEX::MenuScreenEX()
{
    back_choose=0;
    cell_choose=0;
    snake_choose=0;
    
	font_.loadFromFile("Fonts/game_over.ttf");
    
	backText_.setFont(font_);
	backText_.setString(
		"\n\nChoose BackGrond: \n[Q] white     [W] black     [E] brown     \n\n");
    backText_.setColor(sf::Color::White);
    backText_.setCharacterSize(24);
    backText_.setStyle(sf::Text::Bold);
    backText_.setOutlineThickness(0.8);
    backText_.setOutlineColor(sf::Color::White);

	cellText_.setFont(font_);
	cellText_.setString("\n\nChoose Grids' Color: \n[A] white     [S] black     [D] brown     [F] none     \n\n");
    cellText_.setColor(sf::Color::White);
    cellText_.setCharacterSize(24);
    cellText_.setStyle(sf::Text::Bold);
    cellText_.setOutlineThickness(0.8);
    cellText_.setOutlineColor(sf::Color::White);
    
    snakeText_.setFont(font_);
    snakeText_.setString("\n\nChoose Snake Skin: \n[Z] pink     [X] yellow     [C] blue     \n\nPress [space] to continue\n\n");
	snakeText_.setColor(sf::Color::Magenta);
	snakeText_.setCharacterSize(24);
	snakeText_.setStyle(sf::Text::Bold);
    snakeText_.setOutlineThickness(0.8);
    snakeText_.setOutlineColor(sf::Color::White);

	sf::FloatRect backtextBounds = backText_.getLocalBounds();
	backText_.setOrigin(backtextBounds.left + backtextBounds.width / 2,
		backtextBounds.top + backtextBounds.height / 2);
	backText_.setPosition(Game::Width / 2, Game::Height / 4);

	sf::FloatRect celltextBounds = cellText_.getLocalBounds();
    cellText_.setOrigin(celltextBounds.left + celltextBounds.width / 2,
        celltextBounds.top + celltextBounds.height / 2);
    cellText_.setPosition(Game::Width / 2, Game::Height * 2 / 4);
    
    sf::FloatRect snaketextBounds = snakeText_.getLocalBounds();
    snakeText_.setOrigin(snaketextBounds.left + snaketextBounds.width / 2,
        snaketextBounds.top + snaketextBounds.height / 2);
    snakeText_.setPosition(Game::Width / 2, Game::Height * 3 / 4);
}

void MenuScreenEX::handleInput(sf::RenderWindow& window)//根据按键作出对应的选择，并且做好文字颜色反馈
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		Game::Screen = std::make_shared<GameScreen>();
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		window.close();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        back_choose=0;
        backText_.setColor(sf::Color::White);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        back_choose=1;
        backText_.setColor(sf::Color::Black);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
    {
        back_choose=2;
        backText_.setColor(sf_Color_Brown);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        cell_choose=0;
        cellText_.setColor(sf::Color::White);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        cell_choose=1;
        cellText_.setColor(sf::Color::Black);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        cell_choose=2;
        cellText_.setColor(sf_Color_Brown);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
    {
        cell_choose=back_choose;
        cellText_.setColor(sf::Color::Transparent);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        snake_choose=0;
        snakeText_.setColor(sf::Color::Magenta);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
    {
        snake_choose=1;
        snakeText_.setColor(sf::Color::Yellow);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
    {
        snake_choose=2;
        snakeText_.setColor(sf::Color::Blue);
    }
    
}

void MenuScreenEX::update(sf::Time delta)
{
	
}

void MenuScreenEX::render(sf::RenderWindow& window)//重新绘制文字，持续反馈
{
	window.draw(backText_);
    window.draw(cellText_);
	window.draw(snakeText_);
}
