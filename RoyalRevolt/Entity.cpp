#include "Entity.h"
#include "EntityManager.h"
#include "TextureManager.h"
#include "Macro.h"

Entity::Entity(const string& _name, const EntityType& _type, const Vector2f& _position,
	const string& _path, const int _tileAround)
	: IManagable(_name)
{
	Register();

	type = _type;
	shape = nullptr;
	/*const Vector2f& _size = MapManager::GetInstance().GetCurrent()->GetCellSize();
	shape = new RectangleShape(Vector2f(_size));*/
	shape->setPosition(_position);
	SetOriginAtMiddle(shape);//TODO
	InitTexture(_path);
	tileAround = _tileAround;
	currentLap = 0;
	collision = new CollisionComponent();
}

Entity::~Entity()
{
	delete shape;
	delete collision;
}

void Entity::Register()
{
	EntityManager::GetInstance().Add(id, this);
}

void Entity::InitTexture(const string& _path)
{
	TextureManager::GetInstance().Load(shape, _path);
}

void Entity::Update()
{
	currentLap++;
}