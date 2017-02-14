#include "GameObject.h"

GameObject::GameObject(string type, Transform * transformObject, ParticleModel * particleModel, Appearance * appearance) : _type(type), _transformObject(transformObject), _particleModel(particleModel), _appearance(appearance)
{
	_parent = nullptr;
}

GameObject::~GameObject()
{
}

void GameObject::Update(DWORD elapsedTime)
{
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_transformObject->GetScale().x, _transformObject->GetScale().y, _transformObject->GetScale().z);
	XMMATRIX rotation = XMMatrixRotationX(_transformObject->GetRotation().x) * XMMatrixRotationY(_transformObject->GetRotation().y) * XMMatrixRotationZ(_transformObject->GetRotation().z);
	XMMATRIX translation = XMMatrixTranslation(_transformObject->GetPosition().x, _transformObject->GetPosition().y, _transformObject->GetPosition().z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	if (_parent != nullptr)
	{
		XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetWorldMatrix());
	}

	//_particleModel->Update(elapsedTime);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	// NOTE: We are assuming that the constant buffers and all other draw setup has already taken place

	Geometry * geometry = _appearance->GetGeometryDataPointer();

	// Set vertex and index buffers
	pImmediateContext->IASetVertexBuffers(0, 1, &geometry->vertexBuffer, &geometry->vertexBufferStride, &geometry->vertexBufferOffset);
	pImmediateContext->IASetIndexBuffer(geometry->indexBuffer, DXGI_FORMAT_R16_UINT, 0);

	pImmediateContext->DrawIndexed(geometry->numberOfIndices, 0, 0);
}