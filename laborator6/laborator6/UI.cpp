#include "Controller.h"
#include "UI.h"

int UI::startMenu()
{
	int command;
	cout << "Enter one of the following\n0.Exit\n1.Administrator mode\n2.User mode\n";
	cin >> command;
	return command;
}

int UI::adminMenu()
{
	int command;
	cout << "0. Exit\n"
		<< "1. Print movies\n"
		<< "2. Add new movie\n"
		<< "3. Delete movie at index\n"
		<< "4. Update movie at index\n"
		<< "Enter command: ";
	cin >> command;
	return command;
}

void UI::addUI()
{
	cout << "Enter title: ";
	string b{ "" };
	getline(cin, b);
	cout << "Enter genre: ";
	string n{ "" };
	getline(cin, n);
	cout << "Enter year: ";
	int a = 0;
	cin >> a;
	cin.ignore();
	cout << "Enter likes: ";
	int f = 0;
	cin >> f;
	cin.ignore();
	cout << "Enter trailer: ";
	string p{ "" };
	getline(cin, p);

	this->ctrl.add(b, n, a, f, p);
}

void UI::deleteUI()
{
	int index = 0;
	cout << "Enter index: ";
	cin >> index;
	this->ctrl.remove(--index);
	cin.ignore();
}

void UI::updateUI()
{
	cout << "Enter title: ";
	string b{ "" };
	getline(cin, b);
	cout << "Enter genre: ";
	string n{ "" };
	getline(cin, n);
	cout << "Enter year: ";
	int a = 0;
	cin >> a;
	cin.ignore();
	cout << "Enter likes: ";
	int f = 0;
	cin >> f;
	cin.ignore();
	cout << "Enter trailer: ";
	string p{ "" };
	getline(cin, p);
	int index = 0;
	cout << "Enter index: ";
	cin >> index;

	this->ctrl.update(b, n, a, f, p, --index);
}

void UI::start()
{
	while (true)
	{
		int start = startMenu();
		if (start == 1)
		{
			int command;
			do
			{
				command = adminMenu();
				cin.ignore();
				switch (command)
				{
				case 1:
					if (this->ctrl.getListSize() == 0)
						cout << "No Movies\n";
					else cout << this->ctrl.getRepository();
					break;
				case 2:
					addUI();
					break;
				case 3:
					deleteUI();
					break;
				case 4:
					updateUI();
					break;
				default:
					break;
				}
			} while (command != 0);
		}
		else return;
	}
}
