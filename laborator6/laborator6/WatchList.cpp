#include "Watchlist.h"

void Watchlist::add(const Movie &movie)
{
	this->movies.add(movie);
}

void Watchlist::showCurrent()
{
	this->getCurrent().showTrailer();
}

void Watchlist::next()
{
	if (this->current == this->movies.getSize() - 1)
		this->current = 0;
	else this->current++;
}

void Watchlist::empty()
{
	this->current = 0;
	this->movies = DynamicVector<Movie>();
}

Movie& Watchlist::getCurrent()
{
	return this->movies[this->current];
}

bool Watchlist::isEmpty()
{
	return (this->movies.getSize() == 0);
}

