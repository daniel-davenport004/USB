#include "d016619fSteeringBehaviour.h"
#include "../TankManager.h"
#include "../Commons.h"
#include "../C2DMatrix.h"

d016619fSteeringBehaviour::d016619fSteeringBehaviour()
{
	seek = false;
	flee = false;
	arrive = false;
	pursuit = false;
	offsetPursuit = false;
	evade = false;
	wander = false;
	obstacleAvoidance = false;
	wallAvoidance = false;
	followPath = false;
	interpose = false;
	hide = false;
}

d016619fSteeringBehaviour::~d016619fSteeringBehaviour()
{
}

Vector2D d016619fSteeringBehaviour::CombinedBehaviours(Vector2D TargetPos, Deceleration Deceleration, BaseTank * evader, Vector2D offset, BaseTank * leader, BaseTank* tank)
{
	Vector2D vector;

	if (_seek)
	{
		vector += Seek(TargetPos, tank);
	}
	if (_flee)
	{
		vector += Flee(TargetPos, tank);
	}
	if (_arrive)
	{
		vector += Arrive(TargetPos, Deceleration, tank);
	}
	if (_pursuit)
	{
		vector += Pursuit(evader, tank);
	}
	if (_offsetPursuit)
	{
		vector += OffsetPursuit(offset, leader, tank);
	}

	return vector;
}

Vector2D d016619fSteeringBehaviour::Seek(Vector2D TargetPos, BaseTank * tank)
{
	return Vector2D(Vec2DNormalize(TargetPos - tank->GetPosition()) * tank->GetMaxSpeed() - tank->GetVelocity());
}

Vector2D d016619fSteeringBehaviour::Flee(Vector2D TargetPos, BaseTank * tank)
{
	return Vector2D(tank->GetVelocity() - Vec2DNormalize(TargetPos - tank->GetPosition()) * tank->GetMaxSpeed());
}

Vector2D d016619fSteeringBehaviour::Arrive(Vector2D TargetPos, Deceleration Deceleration, BaseTank * tank)
{
	Vector2D ToTarget = TargetPos - tank->GetPosition();
	double magnitude = ToTarget.Length();
	if (magnitude > 0)
	{
		const double decelerationTweaker = 1 / 3;
		double speed = magnitude / ((double)Deceleration * decelerationTweaker);
		speed = min(speed, tank->GetMaxSpeed());
		return Vector2D((ToTarget * speed) / magnitude - tank->GetVelocity());
	}
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::Pursuit(BaseTank * evader, BaseTank * tank)
{
	Vector2D ToEvader = evader->GetPosition() - tank->GetPosition();
	if ((ToEvader.Dot(tank->GetHeading()) > 0) && (tank->GetHeading().Dot(evader->GetHeading()) < -0.95)) //acos(0.95) = 18 degs
	{
		return Seek(evader->GetPosition(), tank); //target is directly ahead
	}

	double LookAhead = ToEvader.Length() / (tank->GetCurrentSpeed() + evader->GetCurrentSpeed());
	return Seek(evader->GetPosition() + evader->GetVelocity() * LookAhead, tank);
}

Vector2D d016619fSteeringBehaviour::OffsetPursuit(Vector2D offset, BaseTank * leader, BaseTank * tank)
{
	/*Vector2D WorldOffsetPosition = PointToWorldSpace(offset, leader->GetHeading(), leader->GetSide(), leader->GetPosition());
	Vector2D ToOffset = WorldOffsetPosition - tank->GetPosition();
	double LookAhead = ToOffset.Length() / (tank->GetCurrentSpeed() + leader->GetCurrentSpeed());
	return Arrive(WorldOffsetPosition + leader->GetVelocity() * LookAhead, fast, tank);*/
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::Evade()
{
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::Wander()
{
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::ObstacleAvoidance()
{
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::WallAvoidance()
{
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::FollowPath()
{
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::Interpose()
{
	return Vector2D(0, 0);
}

Vector2D d016619fSteeringBehaviour::Hide()
{
	return Vector2D(0, 0);
}