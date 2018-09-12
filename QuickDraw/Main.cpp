#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
int main()
{
	sf::RenderWindow gameWindow(sf::VideoMode::getDesktopMode(), "Quick Draw",
	sf::Style::Titlebar | sf::Style::Close);



	//timer functionality
	float signalTimeLowerLimit = 5.0f;
	float signalTimeUpperLimit = 10.0f;
	sf::Time timeTilSignal= sf::seconds(0.0f); 
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
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}
		gameWindow.clear(sf::Color::Red);
		gameWindow.draw(buttonSprite);
		gameWindow.display();
	}

	return 0;
}
