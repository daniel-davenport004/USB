#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform * transform) : _transform(transform)
{
	_velocity = Vector3(0.0f, 0.0f, 0.001f);
	_acceleration = Vector3(0.0f, 0.0f, 0.001f);
	_particleState = ParticleState::EMPTY;
	_mass = 100000.0f;
	_netForce = Vector3();

	_thrustForce = Vector3(0.0f, 0.0f, 1.0f);
	_brakeForce = Vector3(0.0f, 0.0f, -2.0f);
	_frictionForce = Vector3(0.0f, 0.0f, 3.0f);
}

ParticleModel::~ParticleModel()
{
}

void ParticleModel::Update(DWORD elapsedTime)
{
	UpdateNetForce();
	//Assumption: net external force is constant between consecutive updates of object state
	UpdateAccel();

	if (_particleState == ParticleState::VELOCITY) //change time in calculations from 25 to something smaller
	{
		moveConstVel(elapsedTime);
	}
	else if (_particleState == ParticleState::ACCELERATION)
	{
		moveConstAccel(elapsedTime);
	}
}

void ParticleModel::moveForward()
{
	Vector3 position = _transform->GetPosition();
	position.z += 0.025f;
	_transform->SetPosition(position);
}

void ParticleModel::moveConstVel(DWORD elapsedTime)
{
	Vector3 vector;
	_transform->SetPosition(vector.Addition(_transform->GetPosition(), vector.Multiplication(_velocity, (float)elapsedTime)));
}

void ParticleModel::moveConstAccel(DWORD elapsedTime)
{
	Vector3 vector;
	_transform->SetPosition(vector.Addition(vector.Addition(_transform->GetPosition(), vector.Multiplication(_velocity, (float)elapsedTime)), vector.Multiplication(vector.Multiplication(vector.Multiplication(_acceleration, 0.5), (float)elapsedTime), (float)elapsedTime)));
	_velocity = vector.Addition(_velocity, vector.Multiplication(_acceleration, (float)elapsedTime));
}

void ParticleModel::UpdateNetForce()
{
	//linked list?

	_netForce.x += _thrustForce.x + _brakeForce.x + _frictionForce.x;
	_netForce.y += _thrustForce.y + _brakeForce.y + _frictionForce.y;
	_netForce.z += _thrustForce.z + _brakeForce.z + _frictionForce.z;
}

void ParticleModel::UpdateAccel()
{
	_acceleration.x = _netForce.x / _mass;
	_acceleration.y = _netForce.y / _mass;
	_acceleration.z = _netForce.z / _mass;
}