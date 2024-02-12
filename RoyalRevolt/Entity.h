#pragma once

#include "IManagable.h"
#include "CollisionComponent.h"
#include "EntityType.h"

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class EntityManager;

class Entity : public IManagable<string>
{
    EntityType type;
    CollisionComponent* collision;

protected:
    Shape* shape;
    int tileAround;
    int currentLap;

public:
    EntityType GetType() const
    {
        return type;
    }
    Vector2f GetPosition() const
    {
        return shape->getPosition();
    }
    Shape* GetShape() const
    {
        return shape;
    }

public:
    Entity(const string& _name, const EntityType& _type, const Vector2f& _position, const string& _path, const int _tileAround);
    ~Entity();

private:
    virtual void Register() override;

protected:
    void InitTexture(const string& _path);

public:
    virtual void Update() = 0;
};