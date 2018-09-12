#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <cstdlib>
#include <ctime>
int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode::getDesktopMode(), "Quick Draw",
	sf::Style::Titlebar | sf::Style::Close);

	//seed our random number generator
	srand(time(NULL));

	//timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal= sf::seconds(signalTimeLowerLimit); 
	sf::Time timeSinceSignal = sf::seconds(0.0f);
	sf::Clock gameClock;

	// Create Button Sprite
	sf::Texture buttonTexture;
	buttonTexture.loadFromFile("graphics/button.png");

	sf::Sprite buttonSprite;
	buttonSprite.setTexture(buttonTexture);


	buttonSprite.setTexture(buttonTexture);
	//center the sprite on the screen.
	buttonSprite.setPosition(
		gameWindow.getSize().x / 2 - buttonTexture.getSize().x / 2,
		gameWindow.getSize().y / 2 - buttonTexture.getSize().y / 2
	);

	
	while (gameWindow.isOpen())
	{
		sf::Event gameEvent;
		sf::Event event;
		while (gameWindow.pollEvent(gameEvent))
		{
			if (gameEvent.type == sf::Event::MouseButtonPressed)
			{
				if (buttonSprite.getGlobalBounds().contains(gameEvent.mouseButton.x, gameEvent.mouseButton.y))
				{
					//we did
					int range = (int)(signalTimeUpperLimit - signalTimeLowerLimit);
					float signalSeconds = rand() % range + signalTimeLowerLimit;
					timeTilSignal - sf::seconds(signalSeconds);
				}
			}
			if (gameEvent.type == sf::Event::Closed)
				gameWindow.close();
		}

		//update game state
		sf::Time frameTime = gameClock.restart();

		timeTilSignal = timeTilSignal - frameTime;
		if (timeTilSignal.asSeconds() <= 0.0f)
		{
			//signal is go
			buttonSprite.setColor(sf::Color::Red);
		}


		gameWindow.clear(sf::Color::Red);
		gameWindow.draw(buttonSprite);
		gameWindow.display();
	}

	return 0;
}
