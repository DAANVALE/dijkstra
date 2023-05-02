#include "Grid.h"

Grid::Grid() {
	setSize(200);
	Run();
}

Grid::Grid(int size) {
	setSize(size);
	Run();
}

void Grid::setSize(int size) {
	this->size = size;
	this->numbox = size / 20;
}

void Grid::Run() {
	sf::RenderWindow grid_window(sf::VideoMode(size, size), "sfml works!");

	setConfig();

	while (grid_window.isOpen()) {

		sf::Event evnt;

		while (grid_window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed)
				grid_window.close();
		}

		grid_window.clear();
		//inicia la aventura

		box[5][5].setType(stateBox::start);
		box[8][8].setType(stateBox::end);

		onClick(grid_window);
		for (itn_i = 0; itn_i < numbox; itn_i++) {
			for (itn_j = 0; itn_j < numbox; itn_j++) {
				grid_window.draw(box[itn_i][itn_j].getBox());
			}
		}

		//hasta aca acaba :)
		grid_window.display();
	}
}

void Grid::setConfig() {
	//Lo usamos para crear el gridbox dinamico 

	box = new Box*[numbox];
	for (itn_i = 0; itn_i < numbox; itn_i++) {
		box[itn_i] = new Box[numbox];
	}

	//lo usamos para darle posiciones al elemento box y inicializar las en vacias
	for (itn_i = 0; itn_i < numbox; itn_i++) {
		for (itn_j = 0; itn_j < numbox; itn_j++) {
			box[itn_i][itn_j].setPos({ (float)itn_i * 20, (float)itn_j * 20 });
			box[itn_i][itn_j].setType(stateBox::empty);
		}
	}
}

void Grid::onClick(sf::RenderWindow &window) {

	sf::Vector2i vector = sf::Mouse::getPosition(window);

	onClick_stateDraw();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (vector.x >= 0 && vector.x <= window.getSize().x && vector.y >= 0 && vector.y <= window.getSize().y) {
			itn_x = vector.x / 20; itn_y = vector.y / 20;
			if (box[itn_x][itn_y].geType() == stateBox::empty) {
				box[itn_x][itn_y].setType(toDraw);
			}
		}
	}
}

void Grid::onClick_stateDraw() {

}