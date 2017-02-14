#pragma once

#include <math.h>

class Vector3
{
public:
	Vector3();
	Vector3(float x, float y, float z);
	~Vector3();

	float DotProduct(Vector3 vector1, Vector3 vector2);
	Vector3 CrossProduct(Vector3 vector1, Vector3 vector2);
	float Magnitude(Vector3 vector);
	Vector3 Normalise(Vector3 vector);
	Vector3 Addition(Vector3 vector1, Vector3 vector2);
	Vector3 Subtraction(Vector3 vector1, Vector3 vector2);
	Vector3 Multiplication(Vector3 vector, float number);
	Vector3 Division(Vector3 vector, float number);

	float x;
	float y;
	float z;

	/*Vector3 velocity;
	Vector3 acceleration;
	Vector3 position;*/
};