#pragma once
#include <iostream>
#include <string>
using namespace std;

class Movie
{
private:
	string title;
	string genre;
	int year;
	int likes;
	string trailer;
public:
	Movie() : title(""), genre(""), year(0), likes(0), trailer("") {}
	Movie(string&, string&, int, int, string&);

	string getTitle() const { return this->title; }
	string getGenre() const { return this->genre; }
	int getYear() const { return this->year; }
	int getLikes() const { return this->likes; }
	string getTrailer() const { return this->trailer; }

	void setTitle(const string title) { this->title = title; }
	void setGenre(const string genre) { this->genre = genre; }
	void setYear(const int year) { this->year = year; }
	void setLikes(const int likes) { this->likes = likes; }
	void setTrailer(const string trailer) { this->trailer = trailer; }

	friend ostream& operator<<(ostream&, Movie&);
	bool operator==(Movie&);

	void showTrailer();
};

