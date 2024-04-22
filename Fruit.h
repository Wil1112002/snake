#ifndef FRUIT_H
#define FRUIT_H

#include <SFML/Graphics.hpp>

namespace sfSnake
{
class Fruit
{
public:
	Fruit(sf::Vector2f position = sf::Vector2f(0, 0));
    
    sf::Color Set_Color();//return color for fruit

	void render(sf::RenderWindow& window);

	sf::FloatRect getBounds() const;
    
    int Score();

private:
	sf::CircleShape shape_;
	sf::Color color_;
    int score_;
	static const float Radius;
};
}

#endif