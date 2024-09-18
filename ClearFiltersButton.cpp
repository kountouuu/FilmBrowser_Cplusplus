#include "button.cpp"
#include "graphics.h"

class ClearFiltersButton : Button {
public:
	void draw() {
		cfb.texture = std::string(ASSET_PATH) + "filterButton.png";
		cfb.fill_color[0] = 1.0f;
		cfb.fill_color[1] = 1.0f;
		cfb.fill_color[2] = 1.0f;
		cfb.outline_opacity = 0.0f;
		graphics::drawRect(200, 115, 80, 80, cfb);
	};
	ClearFiltersButton() {
		pressed = false;
		width = 0;
		height = 0;
	}
	graphics::Brush cfb;

	
private:

	int width;
	int height;
	bool pressed;
	
};
