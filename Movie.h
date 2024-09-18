#pragma once
#include "graphics.h"

class Movie {
public:
	graphics::Brush thumbnail;

	Movie();

	Movie(std::string nm, std::string yr, std::string dirs, std::string stars, 
		std::string genre, std::string desc,std::string thumPath);
	void draw();
	void clear();
	bool matchesCriteria(std::string s);
	bool matchesTitleCriteria(std::string title);
	bool matchesActorCriteria(std::string actors);
	bool matchesDirectorCriteria(std::string directors);
	void draw(int x);
	std::string getDescription() { return description; };
	std::string getName() { return name; };
	std::string getYear() { return year; };
	std::string getStarring();
	std::string getDirectors() { return directors; };
	std::string getGenre() { return genre; };
	void previewMovie();
	
	void setName(std::string s) { name = s; };
	void setYear(std::string s) { year = s; };
	void setStarring(std::string s) { starring = s; };
	void setDirectors(std::string s) { directors = s; };
	void setGenre(std::string s) { genre = s; };

private:
	std::string name;
	std::string year;
	std::string directors;
	std::string starring;
	std::string genre;
	std::string description;
	std::string thumbnailPath;
};