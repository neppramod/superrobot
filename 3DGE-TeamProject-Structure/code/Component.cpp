#include "Component.h"


Component::Component() : isSelectabl(false)
{
}

Component::Component(bool isSelect) : isSelectabl(isSelect) {}

Component::~Component()
{
}
