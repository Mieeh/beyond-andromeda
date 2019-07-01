#include"asteroid_object.h"

#include"../asteroid_generator.h"
#include"../math.h"
#include"../sfml/sfml_window_singleton.h"

AsteroidObject::AsteroidObject()
{
	auto window = SFMLWindow::Get()->window;
	float x = getRandomFloat(0, window->getSize().x);
	float y = getRandomFloat(0, window->getSize().y);

	sf::Vector2f o(x, y);
	GenerateAsteroidVertexArray(80, 100, 0.1, 0.9, o, sf::Color::Red, points);
}

sf::Drawable & AsteroidObject::GetDrawable()
{
	return points;
}
