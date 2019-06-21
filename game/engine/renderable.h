#pragma once

namespace sf {
	class Drawable;
}

class Renderable {
public:
	virtual sf::Drawable& GetDrawable() = 0;

};