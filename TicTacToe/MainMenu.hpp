#pragma once
#include <iostream>
#include "Screen.h"

class MainMenu : public Screen
{
public:
	MainMenu();
	virtual int run(sf::RenderWindow &app);
private:
	bool m_playing;
};
