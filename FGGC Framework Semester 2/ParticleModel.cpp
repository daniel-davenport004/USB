#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform * transform) : _transform(transform)
{
	_velocity = Vector3(0.0f, 0.0f, 0.001f);
	_acceleration = Vector3(0.0f, 0.0f, 0.001f);
	_particleState = ParticleState::EMPTY;
	_mass = 0.0f;
	_netForce = Vector3();
}

ParticleModel::~ParticleModel()
{
}

void ParticleModel::Update(DWORD elapsedTime)
{
	UpdateNetForce();
	//carry on

	if (_particleState == ParticleState::VELOCITY)
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

}

void ParticleModel::UpdateAccel()
{

}