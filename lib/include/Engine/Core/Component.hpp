#ifndef ENGINE_COMPONENT_HPP
#define ENGINE_COMPONENT_HPP

#include <type_traits>

namespace ng {

struct Component {
	// TODO: Evaluate idea
	// - Save current deltaTime + 1 instead
	// - Check if saved value >= deltaTime to invalidate cache
	// - No need to reset after each frame
	// TODO: Keep in mind
	// - Dirty flag is not only useful for caching, but also to prevent
	//	 recalculation of matrices within one frame for hierarchical entities
	bool isDirty = true;
};

template <typename T>
concept IsComponent = std::is_base_of<Component, T>::value;

}

#endif
