#ifndef _BUTTON_
#define _BUTTON_
#include "Label.h"
#include "Command.h"


class Button :

	public Label
{
public:
	Button();
	Button(const std::string& display);
	Button::Button(const std::string& display, float x, float y, Commands::Command* command);
	~Button();
	inline bool isPressed() { return isPress; };
	inline bool isMouseOverButton() { return isMouseOver; };
	void update(const sf::Event& event);
	void setState(Enums::BUTTON_STATES sta);
	sf::FloatRect& getBounds();
	inline Commands::Command& getCommand() { return *command; };
private:
	bool isMouseOver;
	bool isPress;
	const sf::Color currentColor;
	Enums::BUTTON_STATES state;
	Commands::Command* command;
};

#endif