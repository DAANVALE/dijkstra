#pragma once

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "SFML/Graphics.hpp"

#include "Box.h"

class Grid
{
private:
	Box **box;
	int itn_i = 0, itn_j = 0, itn_x = 0, itn_y = 0;
	int size = 200;
	int numbox = size / 20;

	sf::Vector2f startPos, finishPos;

	stateBox toDraw = stateBox::block;

public:
	Grid();
	Grid(int size);
	~Grid() { //delete box; 
	}

	void setSize(int size);

	void Run();

	void setConfig();
	void onClick(sf::RenderWindow& window);
	void onClick_stateDraw();
	void type_stateDraw(sf::Vector2i);
};

#endif // !GRID_H