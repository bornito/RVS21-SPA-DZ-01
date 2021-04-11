#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Cvijet
{
public:
	Cvijet(RenderWindow* window);
	float draw(float elapsed);
private:
	float totalTime;

	RenderWindow* window;
	CircleShape sunce{40.f};
	RectangleShape trava{ Vector2f{800.f, 150.f} };
	CircleShape oblak1[3];
	CircleShape oblak2[3];
	CircleShape oblak3[3];
	RectangleShape pozadina{ Vector2f{800.f,600.f} };

	CircleShape pupoljak{20.f};
	RectangleShape latice{ Vector2f(55,5) };
	RectangleShape stabiljka{ Vector2f{8.f, 250.f} };
	ConvexShape list_prvi;
	ConvexShape list_drugi;

};

