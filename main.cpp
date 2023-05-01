#include <iostream>

#include "SFML/Graphics.hpp"

#include "Box.h"

int main(void) {

	int size = 200;
	try {
		std::cin >> size;
	}
	catch (std::exception e) {
		std::cout << e.what();
		size = 200;
	}

	sf::RenderWindow window(sf::VideoMode(size,size), "cool right?");
	sf::Event _event;
	
	window.setFramerateLimit(120);

	int numBox = size / 20;
	int iterator = 0;
	Box** box = new Box*[numBox];

	int i,j;
	for (i = 0; i < numBox; i++) {
		box[i] = new Box[numBox];
	}

	for (i = 0; i < numBox; i++) {
		for (j = 0; j < numBox; j++) {
			box[i][j].setPos({ (float)(i * 20), (float)(j * 20)});
		}
	}

	std::vector<Box**> vec;
	vec.insert(vec.begin() + iterator, box);

	while (window.isOpen())
	{
		while (window.pollEvent(_event)) {
			if (_event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		for (i = 0; i < numBox; i++) {
			for (j = 0; j < numBox; j++) {
				window.draw(box[i][j].getBox());
			}
		}

		window.display();
	}

	vec.clear();
	delete box;
	return 0;
}