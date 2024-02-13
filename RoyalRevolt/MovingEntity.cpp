#include "MovingEntity.h"
#include "Macro.h"

MovingEntity::MovingEntity(const string& _name, const EntityType& _type, const Vector2f& _position,
							const Vector2f& _size, const string& _path, const int _tileAround, 
							const const int _speed, const int _cooldown)
	                  : Entity(EntityData(_name, _type, _position, _size))
{

	movement = new MovementComponent(this, shape, _speed, _cooldown);
	collision = new CollisionComponent(_type,);
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
}
