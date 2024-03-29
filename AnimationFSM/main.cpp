#include <iostream>
#include <SFML/Graphics.hpp>
#include <AnimatedSprite.h>
#include <Player.h>
#include <Input.h>
#include <Debug.h>

using namespace std;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	// Load a sprite to display
	sf::Texture texture;
	if (!texture.loadFromFile("assets\\sprite.png")) {
		DEBUG_MSG("Failed to load file");
		return EXIT_FAILURE;
	}

	// Setup Players Default Animated Sprite
	AnimatedSprite animated_sprite(texture);
	
	animated_sprite.addFrame(sf::IntRect(3, 3, 159, 159));
	animated_sprite.addFrame(sf::IntRect(88, 3, 159, 159));
	animated_sprite.addFrame(sf::IntRect(173, 3, 159, 159));
	animated_sprite.addFrame(sf::IntRect(258, 3, 159, 159));
	animated_sprite.addFrame(sf::IntRect(343, 3, 159, 159));
	animated_sprite.addFrame(sf::IntRect(428, 3, 159, 159));
	

	// Setup the Player
	Player player(animated_sprite);
	Input input;
	
	// Start the game loop
	while (window.isOpen())
	{
		player.i++;
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close window : exit
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					input.setCurrent(Input::Action::LEFT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					input.setCurrent(Input::Action::RIGHT);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					input.setCurrent(Input::Action::UP);
				}
				else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					input.setCurrent(Input::Action::SPACE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				{
					input.setCurrent(Input::Action::ONE);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				{
					input.setCurrent(Input::Action::TWO);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
				{
					input.setCurrent(Input::Action::THREE);
				}
			
				break;
			default:
				player.handleInput(input);
				input.setCurrent(Input::Action::IDLE);
				break;
			}
		}

		// Handle input to Player
		

		// Update the Player
		player.update();

		// Clear screen
		window.clear();

		// Draw the Players Current Animated Sprite
		window.draw(player.getAnimatedSprite());

		// Update the window
		window.display();
	}

	return EXIT_SUCCESS;
};