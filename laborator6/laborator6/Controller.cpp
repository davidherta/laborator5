#include "Controller.h"

void Controller::add(string &a, string &b, int c, int d, string &e)
{
	Movie m{ a, b, c, d, e };
	this->repo.add(m);
}

void Controller::remove(int pos)
{
	this->repo.remove(pos);
}

void Controller::update(string &a, string &b, int c, int d, string &e, int pos)
{
	this->repo.update(a, b, c, d, e, pos);
}

void Controller::addToWatchlistFromRepo()
{
	for (int i = 0; i < this->getListSize(); i++)
		this->watch.add(this->getRepository().getMovies()[i]);
}
