#ifndef ENGINE_NEW_REGISTRY_HPP
#define ENGINE_NEW_REGISTRY_HPP

#include <Engine/Core/Component.hpp>
#include <Engine/Core/Entity.hpp>
#include <Engine/Core/System.hpp>
#include <memory>
#include <typeindex>
#include <unordered_map>

namespace ng {

class NewRegistry {
public:
	template <IsSystem T, typename... Args>
	void activate(Args&&... args);

	template <IsSystem T>
	void deactivate();

private:
	std::unordered_map<
		std::type_index,
		std::unordered_map<Entity, std::unique_ptr<Component>>>
		components;
	std::unordered_map<std::type_index, std::unique_ptr<System>> systems;
};

template <IsSystem T, typename... Args>
void NewRegistry::activate(Args&&... args) {
	auto system = std::make_unique<T>(args...);
	systems.insert({typeid(T), std::move(system)});
}

template <IsSystem T>
void NewRegistry::deactivate() {
	systems.erase(typeid(T));
}

}

#endif
