#include "Button.h"
class OptionsMenu : public Container
{
public:
	OptionsMenu();
	~OptionsMenu();
private:
	Button back;
	Commands::Back bac;
};