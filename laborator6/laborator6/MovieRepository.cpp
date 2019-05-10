#include "MovieRepository.h"

void MovieRepository::add(Movie &movie)
{
	if (!exists(movie))
		this->movies = this->movies + movie;
}

void MovieRepository::remove(int pos)
{
	if (exists(this->getAtPos(pos)))
		this->movies.remove(pos);
}

void MovieRepository::update(string &title, string &genre, int year, int likes, string &trailer, int pos)
{
	this->getAtPos(pos).setTitle(title);
	this->getAtPos(pos).setGenre(genre);
	this->getAtPos(pos).setYear(year);
	this->getAtPos(pos).setTrailer(trailer);
}

bool MovieRepository::exists(Movie &movie)
{
	for (int i = 0; i < this->getSize(); i++)
		if (movie.getGenre() == this->movies[i].getGenre())
			return true;
	return false;
}

int MovieRepository::getMoviePos(Movie &movie)
{
	for (int i = 0; i < this->getSize(); i++)
		if (this->getAtPos(i) == movie)
			return i;
	return -1;
}

ostream& operator<<(ostream &stream, MovieRepository &repo)
{
	for (int i = 0; i < repo.getSize(); i++)
		stream << i + 1 << ". " "Movie " << repo.getAtPos(i).getTitle() << " called "
		<< repo.getAtPos(i).getGenre() << " from the year " << repo.getAtPos(i).getYear() << ", likes:" << repo.getAtPos(i).getLikes() << " trailer: " << repo.getAtPos(i).getTrailer() << endl;
	stream << endl;
	return stream;
}

void testRepo()
{
	Movie movie1{ string("sda"), string("gfda"), 3, 5, string("https://www.youtube.com/watch?v=HZ7PAyCDwEg") };
	Movie movie2{ string("csa"), string("gdas"), 4, 7, string("gDAS") };
	Movie movie3{ string("ewq"), string("dsac"), 5, 214, string("DASC") };
	assert(!(movie1 == movie2));
	MovieRepository repo = MovieRepository();
	assert(repo.getSize() == 0);
	repo.add(movie1);
	assert(repo.getSize() == 1);
	repo.add(movie2);
	assert(repo.getSize() == 2);
	repo.add(movie3);
	repo.remove(2);
	assert(repo.getSize() == 2);

	repo.update(string("csa"), string("ewq"), 1, 3, string("csad"), 0);
	assert(repo.getAtPos(0).getGenre() == "ewq" && repo.getAtPos(0).getTitle() == "csa" && repo.getAtPos(0).getTrailer() == "csad" && repo.getAtPos(0).getYear() == 1);
	assert(repo.getMoviePos(movie2) == 1);
}