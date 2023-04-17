#ifndef GAME_REGISTRY_HPP
#define GAME_REGISTRY_HPP

#include "../System/System.hpp"
#include <memory>
#include <vector>

struct Registry {
  std::vector<std::shared_ptr<System>> systems;
};

#endif
