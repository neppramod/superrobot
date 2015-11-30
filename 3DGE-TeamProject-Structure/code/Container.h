#ifndef _CONTAINER_
#define _CONTAINER_
#include <vector>
#include "Component.h"
///Remember to add sf::Transformable and sf::NonCopyable later
class Container : sf::Drawable, sf::Transformable, sf::NonCopyable
{
public:
	Container();
	~Container();
	void virtual draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void virtual update(const sf::Event& evnt, const sf::RenderWindow& window);
	void virtual update() {};
	typedef std::vector<Component*> component_vector_t;
	typedef component_vector_t::const_iterator const_iterator;
	inline const_iterator cbegin() const { return components.cbegin(); };
	inline const_iterator cend() const { return components.cend(); };
	inline void push(Component* comp) { components.push_back(comp); };
	inline void pop() { components.pop_back(); };
private:
	component_vector_t components;
};


#endif // !_CONTAINER_