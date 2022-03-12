#pragma once
#include "Controller.h"

class UI
{
private:
	void showMenu();
	Controller* ctrl;

public:
	UI();
	~UI();

	void run();
};

