#pragma once
#include "MovieRepository.h"
#include "WatchList.h"

class Controller
{
private:
	MovieRepository repo;
	MovieRepository watchList;
	Watchlist watch;
public:
	Controller(const MovieRepository &repo, const MovieRepository &watchList, const Watchlist &watch) :
		repo(repo),
		watch(watch),
		watchList(watchList) {}

	void add(string&, string&, int, int, string&);
	void remove(int);
	void update(string&, string&, int, int, string&, int);

	void addToWatchlistFromRepo();

	MovieRepository& getRepository() { return this->repo; }
	MovieRepository& getWatched() { return this->watchList; }
	Watchlist& getWatchList() { return this->watch; }
	int getListSize() { return this->repo.getSize(); }
	int getWatchListSize() { return this->watchList.getSize(); }
};
