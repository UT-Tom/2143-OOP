#pragma once
#include <vector>
#include "asteroid.h"
#include "spaceobject.h"

class Starcraft : public SpaceObject {

private:

  // asteroids in the field
  int detectedAsteroids;
  // limit of asteroids to collect/visit
  int limit;
  // total weight of asteroids collected
  double cargoWeight;
  // total distance traveled
  double distance;

protected:

public:
  Starcraft();

  // gets the ship's collection limit
  int getLimit();

  // gets the ship's current total distance traveled
  double getDistance();

  // gets total amount of asteroids within a field
  int getDetectedAsteroids();

  // get a report from the cargo bay
  double getWeight();

  // set collection/visitation limit
  void setLimit(int);

  // sets detectedAsteroids
  void setDetected(int);

  // sets weight of spacecraft
  void setWeight(double);

  // updates the SpaceObject's coordinates (moves to an asteroid) and returns distance
  double moveTo(int,std::vector<Asteroid>&);

  // calculates the closest asteroid
  int findClosest(std::vector<Asteroid>&);

  ~Starcraft();

};