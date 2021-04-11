#include "Cvijet.h"

Cvijet::Cvijet(RenderWindow* window)
{
	this->window = window;
	this->totalTime = 0.f;
}

float Cvijet::draw(float elapsed)
{
	totalTime += elapsed;
	float position = totalTime;
	float rgb = (totalTime/6);

	// Pozadina
	pozadina.setFillColor(Color(0, 0, (255 - rgb)));

	// Sunce / mjesec
	//sunce.setRadius(40.f);
	sunce.setPosition(20.f, 20.f);
	sunce.setFillColor(Color(255,255,rgb));
	//sunce.setOutlineThickness(3.f);
	//sunce.setOutlineColor(Color(0, 0, 0, 255));

	// Trava
	trava.setPosition(0.f, 500.f);
	trava.setFillColor(Color::Green);

	// Oblak3

	oblak3[0].setRadius(20.f);
	oblak3[0].setPosition(30.f + position/3,40.f);
	oblak3[0].setFillColor(Color::White);
	oblak3[0].setScale(4.f, 1.6f);

	oblak3[1].setRadius(20.f);
	oblak3[1].setPosition(90.f + position/3, 40.f);
	oblak3[1].setFillColor(Color::White);
	oblak3[1].setScale(4.f, 1.6f);

	oblak3[2].setRadius(20.f);
	oblak3[2].setPosition(60.f + position/3, 20.f);
	oblak3[2].setFillColor(Color::White);
	oblak3[2].setScale(4.f, 1.6f);

	// Oblak2

	oblak2[0].setRadius(20.f);
	oblak2[0].setPosition(140.f + position/2, 100.f);
	oblak2[0].setFillColor(Color::White);
	oblak2[0].setScale(4.f, 1.6f);

	oblak2[1].setRadius(20.f);
	oblak2[1].setPosition(240.f + position/2, 100.f);
	oblak2[1].setFillColor(Color::White);
	oblak2[1].setScale(4.f, 1.6f);

	oblak2[2].setRadius(20.f);
	oblak2[2].setPosition(180.f + position/2, 80.f);
	oblak2[2].setFillColor(Color::White);
	oblak2[2].setScale(4.f, 1.6f);

	// Oblak 3

	oblak1[0].setRadius(20.f);
	oblak1[0].setPosition(450.f + position/3, 80.f);
	oblak1[0].setFillColor(Color::White);
	oblak1[0].setScale(4.f, 1.6f);

	oblak1[1].setRadius(20.f);
	oblak1[1].setPosition(505.f + position/3, 80.f);
	oblak1[1].setFillColor(Color::White);
	oblak1[1].setScale(4.f, 1.6f);

	oblak1[2].setRadius(20.f);
	oblak1[2].setPosition(560.f + position/3, 60.f);
	oblak1[2].setFillColor(Color::White);
	oblak1[2].setScale(4.f, 1.6f);

	// Stabiljka

	stabiljka.setPosition(350.f, 250.f);
	stabiljka.setFillColor(Color(0, 250, 150));

	// Pupoljak

	pupoljak.setPosition(334.0f, 235.5f);
	pupoljak.setFillColor(Color::Yellow);

	// List1

	list_prvi.setPointCount(4);
	list_prvi.setPoint(0, Vector2f(350.f, 400.f));
	list_prvi.setPoint(1, Vector2f(390.f, 370.f));
	list_prvi.setPoint(2, Vector2f(470.f, 420.f));
	list_prvi.setPoint(3, Vector2f(350.f, 400.f));
	list_prvi.setFillColor(Color(0, 250, 150));

	// List2

	list_drugi.setPointCount(4);
	list_drugi.setPoint(0, Vector2f(350.f, 400.f));
	list_drugi.setPoint(1, Vector2f(300.f, 370.f));
	list_drugi.setPoint(2, Vector2f(240.f, 420.f));
	list_drugi.setPoint(3, Vector2f(350.f, 400.f));
	list_drugi.setFillColor(Color(0, 250, 150));

	// Iscrtavanje

	window->draw(pozadina);

	window->draw(oblak3[0]);
	window->draw(oblak3[1]);
	window->draw(oblak3[2]);

	window->draw(oblak2[0]);
	window->draw(oblak2[1]);
	window->draw(oblak2[2]);

	window->draw(oblak1[0]);
	window->draw(oblak1[1]);
	window->draw(oblak1[2]);

	window->draw(trava);
	window->draw(sunce);

	window->draw(stabiljka);
	window->draw(list_prvi);
	window->draw(list_drugi);

	// Latice

	int angle{ 0 };
	for (int i = 0; i < 1000; i++)
	{
		latice.setPosition(354.f, 255.f);
		latice.setFillColor(Color::Red);
		latice.rotate(angle);
		angle += 1;
		window->draw(latice);
	}

	window->draw(pupoljak);

	if (totalTime > 2000)
	{
		totalTime = 0;
		position = 0;
		rgb = 0;
	}
	return totalTime;
}
