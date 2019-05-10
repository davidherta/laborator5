#pragma once
#include "Movie.h"
#include "DynamicVector.h"
#include <assert.h>

class MovieRepository
{
private:
	DynamicVector<Movie> movies;
public:
	MovieRepository() : movies(DynamicVector<Movie>()) {}
	void add(Movie&);
	void remove(int);
	void update(string&, string&, int, int, string&, int);
	bool exists(Movie&);
	int getMoviePos(Movie&);
	const int getSize() { return this->movies.getSize(); }
	DynamicVector<Movie> getMovies() { return this->movies; }
	Movie& getAtPos(const int pos) { return this->movies[pos]; }


	friend ostream& operator<<(ostream&, MovieRepository&);
};

void testRepo();