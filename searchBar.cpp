#include "widget.h"
#include "bar.h"
#include "graphics.h"
#include "config.h"

class searchBar : public Bar {
public:
	graphics::Brush br;

	searchBar() {
		height = 100;
		width = 400;
		cursor_y = 175;
		searching = false;
		typeMode = false;
	}

	void drawBar() {
		br.texture = "";
		br.fill_color[0] = 0.8f;
		br.fill_color[1] = 0.8f;
		br.fill_color[2] = 0.8f;
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.7f;
		br.gradient = true;
		br.gradient_dir_u = 0.7f;
		br.gradient_dir_v = 0.0f;
		graphics::drawRect(510, 175, 500, 30, br);
	}

	void drawActorBar() {
		br.texture = "";
		br.fill_color[0] = 0.8f;
		br.fill_color[1] = 0.8f;
		br.fill_color[2] = 0.8f;
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.7f;
		br.gradient = true;
		br.gradient_dir_u = 0.7f;
		br.gradient_dir_v = 0.0f;
		graphics::drawRect(610, 225, 300, 30, br);
	}
	void drawDirectorsBar() {
		br.texture = "";
		br.fill_color[0] = 0.8f;
		br.fill_color[1] = 0.8f;
		br.fill_color[2] = 0.8f;
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.7f;
		br.gradient = true;
		br.gradient_dir_u = 0.7f;
		br.gradient_dir_v = 0.0f;
		graphics::drawRect(610, 275, 300, 30, br);
	}
	void drawYearBar() {
		br.texture = "";
		br.fill_color[0] = 0.8f;
		br.fill_color[1] = 0.8f;
		br.fill_color[2] = 0.8f;
		br.outline_opacity = 0.0f;
		br.fill_opacity = 0.7f;
		br.gradient = true;
		br.gradient_dir_u = 0.7f;
		br.gradient_dir_v = 0.0f;
		graphics::drawRect(610, 325, 300, 30, br);
	}

	void setTypeMode(bool b) { typeMode = b; }
	bool getTypeMode() { return typeMode; }
	void setWidth(int n) { width = n; }
	void setHeight(int n) { height = n; }
	int getWidth() { return width; }
	int getHeight() { return height; }
private:
	bool typeMode;
	int height;
	int width;
	bool searching;
	float cursor_y;
};