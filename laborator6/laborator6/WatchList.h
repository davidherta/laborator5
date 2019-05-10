#pragma once
#include "DynamicVector.h"
#include "Movie.h"
#include <assert.h>

class Watchlist
{
private:
	DynamicVector<Movie> movies;
	int current;
public:
	Watchlist() : current(0) {}


	void add(const Movie&);
	void showCurrent();
	void next();
	void empty();
	Movie& getCurrent();

	bool isEmpty();
};

