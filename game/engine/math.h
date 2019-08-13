#pragma once

#include<random>

static float getRandomFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = max - min;
	float r = random * diff;
	return min + r;
}

struct vec2 {
	double x, y;

	/* Constructors */
	vec2() : x(0), y(0) { }
	vec2(double _x, double _y) : x(_x), y(_y) { }
	vec2(const vec2& other) { x = other.x; y = other.y; }

	/* Operators */
	friend vec2 operator+(vec2 lhs, const vec2& rhs) {
		lhs.x += rhs.x; lhs.y += rhs.y;
		return lhs;
	}
	friend vec2 operator-(vec2 lhs, const vec2& rhs) {
		lhs.x -= rhs.x; lhs.y -= rhs.y;
		return lhs;
	}
	friend vec2 operator*(vec2 lhs, const float& rhs) {
		lhs.x *= rhs; lhs.y *= rhs;
		return lhs;
	}
};