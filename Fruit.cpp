#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

#include "Fruit.h"

using namespace sfSnake;

const float Fruit::Radius = 5.f;

int Fruit::Score(){return score_;}

sf::Color Fruit::Set_Color(){
	if(!(rand()%4)){
		color_ = (rand()%2? sf::Color::Black : sf::Color(165,42,42)); //Brown color code in RGB is (165,42,42)
		score_ = 0;
	}
	else if(rand()%3){
		color_ = (rand()%2? sf::Color::Red : sf::Color::Blue);
		score_ = (color_ == sf::Color::Red?3:2);
	}
	else{
		color_ = sf::Color::Green;
		score_ = 1;
	}
	return color_;
}

Fruit::Fruit(sf::Vector2f position)
{
	shape_.setPosition(position);
	shape_.setRadius(Fruit::Radius);
	shape_.setFillColor(Set_Color());
	shape_.setOutlineColor(sf::Color::White);
    shape_.setOutlineThickness(-1.f);
}

void Fruit::render(sf::RenderWindow& window)
{
	window.draw(shape_);
}

sf::FloatRect Fruit::getBounds() const
{
	return shape_.getGlobalBounds();
}



