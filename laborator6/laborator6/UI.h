#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;
public:
	UI(const Controller &ctrl) : ctrl(ctrl) {}

	void start();
private:
	int startMenu();
	int adminMenu();
	void addUI();
	void deleteUI();
	void updateUI();
};