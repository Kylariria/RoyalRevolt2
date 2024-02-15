#pragma once
#include "Entity.h"

enum RemovableType
{
    R_ROCK, R_TREE, R_GRASS, R_PATH
};

class Removable : public Entity
{
    RemovableType type;

public:
    Removable(const string& _name, const Vector2f& _position,
        const EntityType& _type, RemovableType _RType,
        const Vector2f& _size = Vector2f(0.0f, 0.0f),
        const string& _path = "");

public:
    virtual void Update() override;
};