#include "MovingEntity.h"
#include "Macro.h"

MovingEntity::MovingEntity(const EntityData& _data,
							const int _speed, const int _cooldown)
	                  : Entity(_data)
{

	movement = new MovementComponent(this, shape, _speed, _cooldown);
	collision = new CollisionComponent();
}

MovingEntity::~MovingEntity()
{
	delete movement;
	delete collision;
}

void MovingEntity::Update()
{
	Entity::Update();
	// si c le Hero
	//if (Entity::GetEntityData()->type==)
	//{

	//}

	// si c  une autre entiter non controler pas le jouer
	/*if (!destination || movement->IsAtLocation())
	{
		Vector2f _destination;
		RandomPositionAround(_destination, GetPosition(), movement->GetSpeed());
		movement->SetDestination(_destination);
	}*/





	//movement->Move();
};
