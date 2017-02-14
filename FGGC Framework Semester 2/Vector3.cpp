#include "Vector3.h"

Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

float Vector3::DotProduct(Vector3 vector1, Vector3 vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

Vector3 Vector3::CrossProduct(Vector3 vector1, Vector3 vector2)
{
	return Vector3(vector1.y * vector2.z - vector1.z * vector2.y, vector1.z * vector2.x - vector1.x * vector2.z, vector1.x * vector2.y - vector1.y * vector2.x);
}

float Vector3::Magnitude(Vector3 vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}

Vector3 Vector3::Normalise(Vector3 vector)
{
	return Vector3(vector.x / sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)), vector.y / sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)), vector.z / sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2)));
}

Vector3 Vector3::Addition(Vector3 vector1, Vector3 vector2)
{
	return Vector3(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
}

Vector3 Vector3::Subtraction(Vector3 vector1, Vector3 vector2)
{
	return Vector3(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
}

Vector3 Vector3::Multiplication(Vector3 vector, float number)
{
	return Vector3(vector.x * number, vector.y * number, vector.z * number);
}

Vector3 Vector3::Division(Vector3 vector, float number)
{
	return Vector3(vector.x / number, vector.y / number, vector.z / number);
}