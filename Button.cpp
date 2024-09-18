#pragma once
#include "widget.h"


class Button : Widget {
public:
	Button() {
		width = 0;
		height = 0;
	}


	Button(int* h, int* w) {
		height = *h;
		width = *w;
	}
	void draw();
	void update();
	void remove();
	void create();
	int getWidth() {
		return width;
	}
	void setWidth(int n) { width = n; }
	int getHeight() {
		return height;
	}
	void setHeight(int n) { height = n; }

private:
	int width;
	int height;
};



