#include "Menu.h"
#include "GameWindow.h"
#include "TextureManager.h"
#include "Macro.h"
#include "GameInstance.h"
#include "InputManager.h"

#define BACKGROUND_PATH "UI/Menu.png"
#define BUTTON_PATH "UI/Button_Menu_Play.png"

Menu::Menu() : Map("Menu",Vector2f())
{
	elements = vector<BasicElement*>();
}

Menu::~Menu()
{
	for (BasicElement* _element : elements)
	{
		delete _element;
	}
}

void Menu::Launch()
{
	//background = new RectangleShape(Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	TextureManager::GetInstance().Load(background, BACKGROUND_PATH);

	elements.push_back(new Button(new RectangleShape(Vector2f(200.0f, 180.0f)), BUTTON_PATH, Vector2f(SCREEN_WIDTH * 0.2f, SCREEN_HEIGHT * 0.6f), "", [&]() {GameInstance::GetInstance().LaunchVillage(); }));
	Update();
}

void Menu::Update()
{
	while (WINDOW.isOpen())
	{
		Event _event;
		if (WINDOW.pollEvent(_event))
		{
			if (_event.type == Event::Closed) WINDOW.close();

			InputManager::GetInstance().Update(WINDOW,_event);
			UpdateElements(_event);
		}
		Display();
	}
}

void Menu::UpdateElements(const Event& _event)
{
	for (BasicElement* _element : elements)
	{
		_element->Update(_event);
	}
}

void Menu::Display()
{
	WINDOW.clear();

	for (Drawable* _drawable : GetDrawables())
	{
		WINDOW.draw(*_drawable);
	}

	WINDOW.display();
}
