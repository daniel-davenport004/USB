#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include "Vector3.h"
#include "Transform.h"

enum ParticleState
{
	VELOCITY,
	ACCELERATION
};

class ParticleModel
{
public:
	ParticleModel(Transform * transform);
	~ParticleModel();

	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }
	Vector3 GetAcceleration() const { return _acceleration; }
	void SetAcceleration(Vector3 acceleration) { _acceleration = acceleration; }
	ParticleState GetVelocityOrAcceleration() const { return _velOrAccel; }
	void SetVelocityOrAcceleration(ParticleState velOrAccel) { _velOrAccel = velOrAccel; }

	void moveForward();
	void moveConstVel(DWORD elapsedTime);
	void moveConstAccel(DWORD elapsedTime);

	void Update(DWORD elapsedTime);
private:
	Transform * _transform;
	Vector3 _velocity;
	Vector3 _acceleration;

	ParticleState _velOrAccel;
};