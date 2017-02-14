#include "d016619fTank.h"
#include "../TankManager.h"
#include "../Commons.h"
#include "../C2DMatrix.h"

//--------------------------------------------------------------------------------------------------

d016619fTank::d016619fTank(SDL_Renderer* renderer, TankSetupDetails details) : BaseTank(renderer, details)
{
	

	steering = new 
}

//--------------------------------------------------------------------------------------------------

d016619fTank::~d016619fTank()
{
}

//--------------------------------------------------------------------------------------------------

void d016619fTank::ChangeState(BASE_TANK_STATE newState)
{
	BaseTank::ChangeState(newState);
}

//--------------------------------------------------------------------------------------------------

void d016619fTank::Update(float deltaTime, SDL_Event e)
{
	switch (e.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent event;
			Point = Vector2D((double)event.x, (double)event.y);
		break;
	}


	//Call parent update.
	BaseTank::Update(deltaTime, e);
}

//--------------------------------------------------------------------------------------------------

void d016619fTank::MoveInHeadingDirection(float deltaTime)
{
	//Get the force that propels in current heading.
	Vector2D force = steering->CombinedBehaviours(Point);

	//Acceleration = Force/Mass
	Vector2D acceleration = force / GetMass();

	//Update velocity.
	mVelocity += acceleration * deltaTime;

	//Don't allow the tank does not go faster than max speed.
	mVelocity.Truncate(GetMaxSpeed()); //TODO: Add Penalty for going faster than MAX Speed.

									   //Finally, update the position.
	Vector2D newPosition = GetPosition();
	newPosition.x += mVelocity.x*deltaTime;
	newPosition.y += (mVelocity.y/**-1.0f*/)*deltaTime;	//Y flipped as adding to Y moves down screen.
	SetPosition(newPosition);
}