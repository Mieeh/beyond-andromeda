#pragma once

#include<random>
#include<ctime>

#include<SFML\Graphics.hpp>

#include"math.h"

#define PI 3.14159f

static void GenerateAsteroidVertexArray(float minR, float maxR, 
	float minStep, float maxStep, 
	const sf::Vector2f& origin, 
	const sf::Color& color,
	sf::VertexArray& vertex_array)
{

	vertex_array.clear(); // Make sure the vertex array we use is empty
	vertex_array.setPrimitiveType(sf::PrimitiveType::LineStrip);

	// Tickers
	float current = 0;
	const int end = 2 * PI;

	// First vertex
	float _startR = getRandomFloat(minR, maxR);
	sf::Vector2f pos(cos(current), sin(current));
	pos *= _startR;
	sf::Vertex v(origin + pos, color);

	// Insert first vertex
	vertex_array.append(v);

	// Now for the main part
	while (true) { // I trust that this loops self breaks
		// Take step
		float step = getRandomFloat(minStep, maxStep);
		if (current + step > end) {
			current = 0;

			// Create vertex (use starting r)
			sf::Vector2f pos(cos(current), sin(current));
			pos *= _startR;
			sf::Vertex v(origin + pos, color);

			// Append vertex
			vertex_array.append(v);

			break;
		}
		else {
			current += step;

			// Create vertex
			float _r = getRandomFloat(minR, maxR);
			sf::Vector2f pos(cos(current), sin(current));
			pos *= _r;
			sf::Vertex v(origin + pos, color);

			// Append vertex
			vertex_array.append(v);
		}


	}

}