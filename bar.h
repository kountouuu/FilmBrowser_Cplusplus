#pragma once
#include "widget.h"

class Bar : public Widget {
public:
	Bar() {
		width = 400;
		height = 100;
	}
	Bar(int h, int w) {
		height = h;
		width = w;
	}
	void drawBar();
	void update();
	void remove();
	void create();
	void setWidth(int n) { width = n; }
	void setHeight(int n) { height = n; }
	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	int height;
	int width;
};
