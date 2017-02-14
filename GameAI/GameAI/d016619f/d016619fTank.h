#ifndef D016619FTANK_H
#define D016619FTANK_H

#include "../BaseTank.h"
#include <SDL.h>
#include "../Commons.h"
#include "d016619fSteeringBehaviour.h"

//---------------------------------------------------------------

class d016619fTank : public BaseTank
{
	//---------------------------------------------------------------
public:
	d016619fTank(SDL_Renderer* renderer, TankSetupDetails details);
	~d016619fTank();

	void ChangeState(BASE_TANK_STATE newState);

	void Update(float deltaTime, SDL_Event e);
	void MoveInHeadingDirection(float deltaTime);

	//---------------------------------------------------------------
private:

	d016619fSteeringBehaviour* steering;
	Vector2D Point;

};

//---------------------------------------------------------------

#endif