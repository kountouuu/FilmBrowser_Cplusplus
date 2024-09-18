#pragma once
#include "config.h"
#include "Platform.h"

class Widget {
public:
	void draw();
	void update();
	void create();
	void remove();
	void setWidth(int n) { width = n; }
	void setHeight(int n) { height = n; }
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
private:
	int height;
	int width;
};

