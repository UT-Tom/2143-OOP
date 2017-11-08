#pragma once
#include <vector>
#include <cmath>
#include "asteroid.h"
#include "starcraft.h"

class Starship : public Starcraft {

public:

  Starship();

  // returns number of asteroids collected
  int getAsteroids();
  // method to set limit and coordinates
  void flightPlan();
  // "blasts" an asteroid
  void blAsteroid(int, std::vector<Asteroid>&);

  ~Starship();

};
