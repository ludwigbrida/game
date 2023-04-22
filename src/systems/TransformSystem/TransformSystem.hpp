#ifndef GAME_TRANSFORM_SYSTEM_HPP
#define GAME_TRANSFORM_SYSTEM_HPP

#include "../../ecs/System.hpp"

struct TransformSystem : System {
  void run() final;
};

#endif
