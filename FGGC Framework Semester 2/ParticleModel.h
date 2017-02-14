#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include "Vector3.h"
#include "Transform.h"

enum ParticleState
{
	EMPTY,
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
	ParticleState GetParticleState() const { return _particleState; }
	void SetParticleState(ParticleState particleState) { _particleState = particleState; }
	float GetMass() const { return _mass; }
	void SetMass(float mass) { _mass = mass; }
	Vector3 GetNetForce() const { return _netForce; }
	void SetNetForce(Vector3 netForce) { _netForce = netForce; }

	void moveForward();
	void moveConstVel(DWORD elapsedTime);
	void moveConstAccel(DWORD elapsedTime);
	void UpdateNetForce();
	void UpdateAccel();

	void Update(DWORD elapsedTime);
private:
	Transform * _transform;

	Vector3 _velocity;
	Vector3 _acceleration;
	ParticleState _particleState;
	float _mass;
	Vector3 _netForce;

	Vector3 _thrustForce;
	Vector3 _brakeForce;
	Vector3 _frictionForce;
};