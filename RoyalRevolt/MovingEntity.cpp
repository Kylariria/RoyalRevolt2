#include "MovingEntity.h"
#include "Macro.h"
#include "InputManager.h"
#include "EntityManager.h"
#include "Hero.h"
MovingEntity::MovingEntity(const EntityData& _data, const Stat& _stats, const int _speed, const int _cooldown) : Entity(_data), Stat(_stats)
{
	
	movement = new MovementComponent(this, shape, _speed, _cooldown);
	collision = new CollisionComponent();
	reactions = vector<CollisionReaction>();
	stats = new Stat(_stats);
}

MovingEntity::~MovingEntity()
{
	delete movement;
	delete collision;
}

void MovingEntity::Update()
{
	Entity::Update();

	const vector<Entity*> _allEntities = EntityManager::GetInstance().GetAllValues();
	// si c le Hero
	if (Hero* _hero = dynamic_cast<Hero*>(this))
	{
		if (!movement->CanMove() || !movement->HasDestination()) return;
		TryToMove();

		collision->CheckCollision(this, _allEntities, reactions);
	}

	// si c  une autre entiter non controler pas le jouer
	/*if (!destination || movement->IsAtLocation())
	{
		Vector2f _destination;
		RandomPositionAround(_destination, GetPosition(), movement->GetSpeed());
		movement->SetDestination(_destination);
	}*/


}

void MovingEntity::TryToMove()
{
	const vector<Entity*> _allEntities = EntityManager::GetInstance().GetAllValues();
	if (!collision->CheckCollision(this, _allEntities, reactions))
	{
		movement->Move();
	}
}
