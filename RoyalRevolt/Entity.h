#pragma once
#include "IManagable.h"
#include "EntityType.h"
#include "IManagable.h"

#include <iostream>
#include <SFML/Graphics.hpp>

class Component;

using namespace std;
using namespace sf;

struct EntityData
{
    string name;
    Vector2f position;
    Vector2f size;
    string path;
    EntityType type;
    int tileAround;
    int health;
    int damage;

    EntityData()
    {
        name = "";
        position = Vector2f();
        size = Vector2f();
        path = "";
        type = ENTITY_NONE;
        tileAround = 0;
        health = 0;
        damage = 0;
    }

    EntityData(const string& _name, const EntityType& _type, const Vector2f& _position,
        const Vector2f& _size,const int _tileAround = 0, const string& _path = "",const int _health = 0, const int _damage = 0 )
    {
        name = _name;
        type = _type;
        position = _position;
        size = _size;
        path = _path;
        tileAround = _tileAround;
        health = _health;
        damage = _damage;
    }

    EntityType GetType() const
    {
        return type;
    }
};

class Entity : public IManagable<string>
{
protected:
    Shape* shape;
    vector<Component*> components;
    EntityData* data;
    
public:
    template<typename T>
    T* GetComponent()const
    {
        for (Component* _component : components)
        {
            if (T* _components = dynamic_cast<T*>(_component))
            {
                return _components;
            }
        }

        return nullptr;
    }

    Shape* GetShape() const
    {
        return shape;
    }
    Vector2f GetShapePosition() const
    {
        if (!shape) return Vector2f();
        return shape->getPosition();
    }
    EntityData* GetEntityData() const
    {
        return data;
    }

public:
    Entity(const EntityData& _data);
    ~Entity();

private:
    virtual void Register() override;

public:
    virtual void Update() = 0;
    //virtual void Attack(const Entity& _entityDamaged) {};

};