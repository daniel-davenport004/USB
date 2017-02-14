#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Vector3.h"
#include "Transform.h"
#include "ParticleModel.h"
#include "Appearance.h"

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Transform * transformObject, ParticleModel * particleModel, Appearance * appearance);
	~GameObject();

	string GetType() const { return _type; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

	Transform * GetTransformObject() const { return _transformObject; }
	ParticleModel * GetParticleModel() const { return _particleModel; }
	Appearance * GetAppearance() const { return _appearance; }

	void SetParent(GameObject * parent) { _parent = parent; }

	void Update(DWORD elapsedTime);
	void Draw(ID3D11DeviceContext * pImmediateContext);

private:
	string _type;

	XMFLOAT4X4 _world;

	Transform * _transformObject;
	ParticleModel * _particleModel;
	Appearance * _appearance;

	GameObject * _parent;
};

