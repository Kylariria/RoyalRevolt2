#pragma once
#include "Entity.h"
#include "functional"

using namespace std;

class Building : public Entity
{
protected:
    function<void()> callback;

public:
    function<void()> GetCallback() const
    {
        return callback;
    }

public :
    template <class Class, typename RType = void, typename... Args>
    Building(const string& _name, const Vector2f& _position, const EntityType& _type,
    Class* _owner, RType(Class::* _callback)(Args...),
    const Vector2f& _size = Vector2f(0.0f, 0.0f),const string& _path = "", const int& _tileAround = 0, const bool& _isBuildable = false, Args... _args)
        : Entity(EntityData(_name, _type, _position, _size)) 
    {
        callback = [_callback, _owner, _args...]() {
            return (_owner->*_callback)(_args...);
            };
    }
    Building(const string& _name, const Vector2f& _position, const EntityType& _type, const function<void()>& _callback,
        const Vector2f& _size = Vector2f(0.0f, 0.0f), const string& _path = "", const int& _tileAround = 0, const bool& _isBuildable = false);

    virtual void Update();

};

