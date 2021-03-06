/*
	Tom Johnson
	2143 - Object Oriented Programming
	Dr. Stringfellow
	Program 2 - Asteroids
	10/04/2017
*/

#include <iostream>
#include <iomanip>
#include <string>

#include "asteroid.h"
#include "starship.h"

using namespace std;

// function prototypes
void openFiles(fstream&,fstream&);
void generateAsteroidField(vector<Asteroid>&,fstream&,Starship&);
void endMission(fstream&, fstream&, Starship&);

int main(){

	fstream ifile, ofile;
	Starship Ship;
	vector<Asteroid> asteroids;

	// prompt the user for input/output
	openFiles(ifile,ofile);
	//  discuss flight plans with the captain (user)
	Ship.captainsLog();

	// generate asteroids from input file & allow the ship to scan
	generateAsteroidField(asteroids,ifile,Ship);

	// loops until the captain gets as many asteroids as he wants
	while(Ship.getLimit() != Ship.getAsteroidCount()){

		int index;
		double distance;
		bool mined;

		// find target
		index = Ship.findClosest(asteroids);

		// if the captain wants to collect more than the field, end mission.
		if(Ship.getAsteroidCount() == Ship.getDetectedAsteroids())
			break;

		// ship moves to target
		distance = Ship.moveTo(index, asteroids);

		// mine asteroid
		mined = Ship.mineAsteroid(index, asteroids);

		// send mission data back to earth
		if(mined)
			Ship.transmitData(index, asteroids, distance, ofile);
	}

	// close files and end program
	endMission(ifile, ofile, Ship);

	return 0;
}

/*
 * @FunctionName: openFiles
 * @Description:
 *			Prompts the user for input & output files
 * @Params:
 *			fstream &ifile - fstream set to ios::in
 *			fstream &ofile - fstream set to ios::out
 * @Returns:
 *			void
 */

void openFiles(fstream &ifile, fstream &ofile){

	string input, output;

	cout << "Name of input file ('def' for 'input.txt'): ";
	cin >> input;
	input = input == "def" ? "input.txt" : input;

	ifile.open(input.c_str(), ios::in);

	cout << "Name of output file ('def' for 'output.txt'): ";
	cin >> output;
	output = output == "def" ? "output.txt" : output;

	ofile.open(output.c_str(), ios::out);

	// setting tabular mission headers
	ofile << "Welcome captain, here's a table of asteroids collected:\n\n";
	ofile << left << setw(15) << "Asteroid #" << setw(12) << "Position" << setw(15)
		<< "Size" << setw(12) << "Distance (in miles)" << endl;

}

/*
 * @FunctionName: generateAsteroidField
 * @Description:
 *			Loops through input file and generates a vector of type Asteroid
 * @Params:
 *			vector<Asteroid> &vect - the vector used to store Asteroids
 *			fstream &ifile - the input file to read from
 *			Starship &Ship - Ship is passed in to know how big the field is
 * @Returns:
 *			void
 */

void generateAsteroidField(vector<Asteroid> &vect, fstream &ifile, Starship &Ship){

  int getx,gety;
  double getw;
  bool c = false;

	int count = 1;

  ifile >> getx >> gety >> getw;
  while(!ifile.eof()){
		Asteroid temp(getx,gety,getw,c);
    vect.push_back(temp);
    ifile >> getx >> gety >> getw;
		count++;
  }

	Ship.setDetected(count);

}

/*
 * @FunctionName: endMission
 * @Description:
 *			Prompts the user for input & output files
 * @Params:
 *			fstream &ifile - input file
 *			fstream &ofile - output file
 *			Starship &Ship - passed in ship to prompt end results
 * @Returns:
 *			void
 */

void endMission(fstream &ifile, fstream &ofile, Starship& Ship){

	ofile << "\nOur ship traveled: " << Ship.getDistance() * 10 << " miles!\n"
				<< "Asteroids collected: " << Ship.getAsteroidCount() << "\n";

	cout << "\nMission complete!\n"
			 << "Our ship traveled: " << Ship.getDistance() * 10 << " miles!\n"
			 << "Asteroids collected: " << Ship.getAsteroidCount() << "\n";

	ifile.close();
	ofile.close();

}
