#include "CollisionComponent.h"
#include "Entity.h"

bool CollisionComponent::CheckCollision(Entity* _currentEntity, const vector<Entity*>& _allEntities, const vector<CollisionReaction>& _reactions)
{
	Shape* _currentShape = _currentEntity->GetShape();
	FloatRect _rect = _currentShape->getGlobalBounds();

	const float _gap = 0.4f;
	
	_rect.top += _rect.height * _gap;
	_rect.left += _rect.width * _gap;
	_rect.width -= _rect.width * _gap * 2.0f;
	_rect.height -= _rect.height * _gap * 2.0f;

	bool _hasCollide = false;

	for (Entity* _entity : _allEntities)
	{
		Shape* shape = _entity->GetShape();

		//si l'entity est la meme que l'actuelle continue
		if (shape == _currentShape) continue;

		//si l'entity est en collision
		if (_rect.intersects(shape->getGlobalBounds()))
		{
			//on recup le type de l'entity

			const EntityType& _entityType = _entity->GetEntityData()->GetType();

			//on cherche si sont type est dans la liste
			for (CollisionReaction _reaction : _reactions)
			{
				// si elle fait partie des réactions
				if (_entityType == _reaction.type)
				{
					//on effectue les réactions
					_reaction.callbacks(_entity);
					return true;
				}

			}

			if (_hasCollide) return true;
		}
	}

	return false;
}
