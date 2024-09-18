#pragma once
#include "Movie.h"
class Platform
{
public:
	void update();
	void draw();
	void init();

	Platform();
	~Platform();
	
	bool getTypeMode();
};