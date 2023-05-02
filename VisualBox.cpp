#include "VisualBox.h"

VisualBox::VisualBox() {
	_box.setSize({19,19});
	setType(state);
}

void VisualBox::setType(stateBox state) {
	switch (state)
	{
	case stateBox::empty:
		_box.setFillColor(sf::Color(0xD2D2D2FF));
		break;
	case stateBox::search:
		break;
	case stateBox::last_searched:
		break;
	case stateBox::path:
		break;
	case stateBox::block:
		_box.setFillColor(sf::Color(0x212121FF));
		break;
	case stateBox::start:
		_box.setFillColor(sf::Color(0x11FF22FF));
		break;
	case stateBox::end:
		_box.setFillColor(sf::Color(0xFF0000FF));
		break;
	default:
		break;
	}
}

void VisualBox::setPos(sf::Vector2f position) {
	_box.setPosition(position);
}