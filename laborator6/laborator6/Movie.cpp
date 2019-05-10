#include "Movie.h"
//#include <windows.h>
//#include <shellapi.h>

Movie::Movie(string &title, string &genre, int year, int likes, string &trailer)
{
	this->title = title;
	this->genre = genre;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

bool Movie::operator==(Movie &movie)
{
	return (this->getGenre() == movie.getGenre()) && (this->getTitle() == movie.getTitle()) && (this->getYear() == movie.getYear()) && (this->getLikes() == movie.getLikes()) && (this->getTrailer() == movie.getTrailer());
}

void Movie::showTrailer()
{
	//ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

ostream& operator<<(ostream &stream, Movie &movie)
{
	return stream << "Movie " << movie.getTitle() << " of genre " << movie.getGenre() << " from the year " << movie.getYear() << ", likes:" << movie.getLikes() << endl;
}

