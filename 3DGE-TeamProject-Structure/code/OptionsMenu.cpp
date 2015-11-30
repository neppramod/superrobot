#include "OptionsMenu.h"

OptionsMenu::OptionsMenu() : back("Back", 50, 100, &bac), Container()
{
	push(&back);
}

OptionsMenu::~OptionsMenu()
{

}
