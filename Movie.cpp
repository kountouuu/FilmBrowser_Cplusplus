#include "Movie.h"
#include "config.h"
#include <vector>


Movie::Movie() {
	
}
std::string Movie::getStarring() {
	return starring;
}
Movie::Movie(std::string n, std::string y, std::string dir, std::string strs,
	std::string gnr, std::string dsc,std::string thumbPath) {
	name = n;
	year = y;
	directors = dir;
	starring = strs;
	genre = gnr;
	description = dsc;
	thumbnailPath = thumbPath;
};

std::vector<std::string> split(const std::string& str, int n) {
	std::vector<std::string> substrings;

	for (size_t i = 0; i < str.size(); i += n) {
		substrings.push_back(str.substr(i, n));
	}
	return substrings;
}

void Movie::previewMovie() {
	thumbnail.texture = thumbnailPath;
	thumbnail.fill_color[0] = 1.0f;
	thumbnail.fill_color[1] = 1.0f;
	thumbnail.fill_color[2] = 1.0f;
	thumbnail.outline_opacity = 0.0f;
	graphics::drawRect(150, (CANVAS_HEIGHT / 2) - 30, 100, 100, thumbnail);;
	// Initialize text Brush
	graphics::Brush textBrush;
	textBrush.fill_color[0] = 1.0f;
	textBrush.fill_color[1] = 1.0f;
	textBrush.fill_color[2] = 1.0f;
	textBrush.outline_opacity = 0.0f;
	// draw Title
	graphics::drawText(220, 190, 24, this->getName(), textBrush);
	//draw Year
	graphics::drawText(750, 190, 16, this->getYear(), textBrush);
	//draw Genre
	graphics::drawText(800, 190, 16, this->getGenre(), textBrush);
	//draw director/s
	graphics::drawText(220, 220, 16, "Directed by : " + this->getDirectors(), textBrush);
	//draw Stars / Actors
	graphics::drawText(220, 250, 16, "Starring    : " + this->getStarring(), textBrush);
	//draw Description splitting it to 100 chars per line to show
	int y_pos = 320;
	std::vector<std::string> stringTokens = split(this->getDescription(), 100);
	for (auto& token : stringTokens) {
		graphics::drawText(100, y_pos, 18, token, textBrush);
		y_pos += 30;
	}
	
	
}

void Movie::draw() {
	thumbnail.texture = thumbnailPath;
	thumbnail.fill_color[0] = 1.0f;
	thumbnail.fill_color[1] = 1.0f;
	thumbnail.fill_color[2] = 1.0f;
	thumbnail.outline_opacity = 0.0f;
	graphics::drawRect(150, 400, 100, 100,thumbnail);
	
}

void Movie::draw(int x_coords) {
	thumbnail.texture = thumbnailPath;
	thumbnail.fill_color[0] = 1.0f;
	thumbnail.fill_color[1] = 1.0f;
	thumbnail.fill_color[2] = 1.0f;
	thumbnail.outline_opacity = 0.0f;
	graphics::drawRect(x_coords, 400, 100, 100, thumbnail);
}

void Movie::clear() {
	thumbnail.texture = "";
}