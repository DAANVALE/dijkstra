#pragma once
#ifndef VISUALBOX_H
#define VISUALBOX_H

#include "SFML/Graphics.hpp"

#include "StateMachine.cpp"

class VisualBox
{
protected:
	sf::RectangleShape _box;
	stateBox state = stateBox::empty;
public:
	VisualBox();
	~VisualBox() {}
	void setType(stateBox state);
	void setPos(sf::Vector2f position);

	sf::RectangleShape getBox() { return _box; }
};

#endif //VISUALBOX_H