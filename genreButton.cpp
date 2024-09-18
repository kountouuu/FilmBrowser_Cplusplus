#include "button.cpp"
#include "graphics.h"
#include "Platform.h"


class genreButton : Button {
public:
	genreButton(std::string genre, int x_centre, int y_centre, int wd, int ht) {
		x = x_centre;
		y = y_centre;
		width = wd;
		height = ht;
		typeOfGenre = genre;
	};
	genreButton() {
		x = 0;
		y = 0;
		width = 0;
		height = 0;
		typeOfGenre = "";
	};
	graphics::Brush ba;
	int getX() { return x; };
	int getY() { return y; };
	int getWidth() { return width; };
	int getHeight() { return height; };
	std::string getGenre() { return typeOfGenre; };

	void update() {
		
	}

private:
	std::string typeOfGenre;
	
	int x;
	int y;
	int width;
	int height;

};