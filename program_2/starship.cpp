#include <iostream>
#include <vector>
#include <cmath>
#include "starship.h"

Starship::Starship(){
  asteroids = 0;
}

void Starship::captainsLog(std::string &input,std::string &output){

  // warp using pre-defined or manually defined coords?
  int choice;
  std::cout << "Would you like to warp using "
					"pre-defined coordinates?\n\n1. Yes\n2. No.\n";
	std::cin >> choice;

  // if manually defined, set x and y
  int x = 0, y = 0;
	if(choice == 2){
		std::cout << "Please enter an x coordinate followed by a y coordinate\n "
		"for the ship to warp to. (Example: 5 25):";
		std::cin >> x >> y;
	}
  std::cout << "\nWarping to (" << x << "," << y << ")...\n\n";
  // ship will now begin its mission at the specified launchCoords
  coords[0] = x;
  coords[1] = y;

  // set the limit of the ship's mission
	std::cout << "How many asteroids would you like to collect before "
					"returning to earth? (integer): ";
	std::cin >> limit;

  // get input/output files
	std::cout << "What's the name of your input file? ('def' for 'input.txt'): ";
	std::cin >> input;
	std::cout << "What's the name of your output file? ('def' for 'output.txt'): ";
	std::cin >> output;

  input = input == "def" ? "input.txt" : input;
	output = output == "def" ? "output.txt" : output;

}

int Starship::getLimit() {
  return limit;
}

int Starship::findClosest(std::vector<Asteroid> &vect) {

  double minDist = 0;

  // loop through all asteroids
  int index = 0;
  // set initial minDist to the maximum double value possible
  minDist = 1.79769e+308;
  // go through vector to compare distances
  for(int i = 0;i < vect.size();i++){

    double tempDist = 0;

    int x, y;
    x = vect[i].getX() - coords[0];
    y = vect[i].getY() - coords[1];
    // ship distancec from asteroid[i]
    tempDist = std::sqrt((x*x + y*y));
    // if the asteroid hasn't been collected and
    // the distance is less than the initla minDist
    // then this is the closest asteroid to the ship
    if(!vect[i].isCollected() && tempDist < minDist){
      index = i;
      minDist = tempDist;
    }

  }

  // return the final closest index in the vector
  return index;

}

void Starship::moveTo(int index, std::vector<Asteroid> &asts){

  double dist;
  dist = std::sqrt((asts[index].getX() * asts[index].getX()) + (asts[index].getY() * asts[index].getY()));
  // ship moves to the asteroid
  distance+= dist;

  // ship's coordinates are updated
  coords[0] = asts[index].getX();
  coords[1] = asts[index].getY();

  // temp print
  std::cout << "\nMoved to: " << coords[0] << ", " << coords[1] << "\nDistance: " << dist << "\n";

}

void Starship::mineAsteroid(int index, std::vector<Asteroid> &asts){

  // asteroid in the vector is now collected
  asts[index].setCollected(true);
  // asteroid count increases
  asteroids++;
  // ship's cargo weight is updated
  cargoWeight = cargoWeight + asts[index].getWeight();

  std::cout << "Cargo weight: " << cargoWeight << "\n";

}