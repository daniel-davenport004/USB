#ifndef D016619FSTEERINGBEHAVIOUR_H
#define D016619FSTEERINGBEHAVIOUR_H

#include "../BaseTank.h"
#include <SDL.h>
#include "../Commons.h"

class d016619fSteeringBehaviour
{
public:
	d016619fSteeringBehaviour();
	~d016619fSteeringBehaviour();

	Vector2D CombinedBehaviours(Vector2D TargetPos, Deceleration Deceleration, BaseTank * evader, Vector2D offset, BaseTank * leader, BaseTank * tank);
	void SetSeek(bool seek) { _seek = seek; }
	void SetFlee(bool flee) { _flee = flee; }
	void SetArrive(bool arrive) { _arrive = arrive; }
	void SetPursuit(bool pursuit) { _pursuit = pursuit; }
	void SetOffsetPursuit(bool offsetPursuit) { _offsetPursuit = offsetPursuit; }
	void SetEvade(bool evade) { _evade = evade; }
	void SetWander(bool wander) { _wander = wander; }
	void SetObstacleAvoidance(bool obstacleAvoidance) { _obstacleAvoidance = obstacleAvoidance; }, bool wallAvoidance, bool followPath, bool interpose, bool hide);

	Vector2D Seek(Vector2D TargetPos, BaseTank * tank);
	Vector2D Flee(Vector2D TargetPos, BaseTank * tank);
	Vector2D Arrive(Vector2D TargetPos, Deceleration Deceleration, BaseTank * tank);
	Vector2D Pursuit(BaseTank * evader, BaseTank * tank);
	Vector2D OffsetPursuit(Vector2D offset, BaseTank * leader, BaseTank * tank);
	Vector2D Evade();
	Vector2D Wander();
	Vector2D ObstacleAvoidance();
	Vector2D WallAvoidance();
	Vector2D FollowPath();
	Vector2D Interpose();
	Vector2D Hide();
private:
	bool _seek;
	bool _flee;
	bool _arrive;
	bool _pursuit;
	bool _offsetPursuit;
	bool _evade;
	bool _wander;
	bool _obstacleAvoidance;
	bool _wallAvoidance;
	bool _followPath;
	bool _interpose;
	bool _hide;
};

#endif