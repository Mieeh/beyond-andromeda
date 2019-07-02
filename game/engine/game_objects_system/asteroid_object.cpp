#include"asteroid_object.h"

#include"../planetary_utility.h"
#include"../math.h"
#include"../sfml/sfml_window_singleton.h"

AsteroidObject::AsteroidObject()
{
	auto window = SFMLWindow::Get()->window;
	float x = getRandomFloat(0, 500);
	float y = getRandomFloat(0, 500);

	sf::Vector2f o(x, y);
		
	GenerateAsteroidVertexArray(80, 100, 0.1, 0.9, o, points);
}

sf::Drawable & AsteroidObject::GetDrawable()
{
	return points;
}
