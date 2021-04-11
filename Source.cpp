#include <SFML/Graphics.hpp>
#include"Cvijet.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "SPA Domaca Zadaca", Style::Close);
	window.setFramerateLimit(60);
	Cvijet cvijet(&window);

	float elapsed{ 0.f };

	Clock frameClock;

	while (window.isOpen())
	{
		elapsed = frameClock.getElapsedTime().asSeconds();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		float time = cvijet.draw(elapsed);
		window.display();

		if (time == 0)
		{
			elapsed = frameClock.restart().asSeconds();
		}
	}

	return 0;
}