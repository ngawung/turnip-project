#include "DisplayObject.hpp"

DisplayObject::DisplayObject(std::string name) 
    : NGObject(name), x(0), y(0), rotation(0), scaleX(100), scaleY(100), layer(0), bound(0, 0, 0, 0), visible(true), _type("DisplayObject")
{

}

// Touch

bool DisplayObject::getTouch(KeyPhase phase) {
	if (bound.x == 0 && bound.y == 0 && bound.width == 0 && bound.height == 0) {
		if (SNF::getTouch(phase))
			std::cout << "Please set sprite '" << get_name() << "(" << get_id() << ")' bound first!" << std::endl;
		
		return false;
	}

	return SNF::getTouchRect(
		x + bound.x,
		y + bound.y,
		bound.width,
		bound.height,
		phase
	);
}

// Get && Set

std::string DisplayObject::get_type() {
	return _type;
}