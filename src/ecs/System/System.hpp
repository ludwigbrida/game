#ifndef GAME_SYSTEM_HPP
#define GAME_SYSTEM_HPP

struct System {
  virtual void run() = 0;

  virtual ~System() = 0;
};

#endif
