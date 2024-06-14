#pragma once
#include <vector>
#include <iostream>
using namespace std;

class SpaceObject
{
protected:

	int x, y, z, radius, mass;

public:

	SpaceObject();
	SpaceObject(int x0, int y0, int z0, int radius0, int mass0);

	int get_cordinates();
	int get_mass();
	int get_radius();
};

SpaceObject::SpaceObject() {

	x = y = z = 0;
	mass = radius = 0;
}

SpaceObject::SpaceObject(int x0, int y0, int z0, int radius0, int mass0) {

	x = x0;
	y = y0;
	z = z0;
	mass = mass0;
	radius = radius0;
}

int SpaceObject::get_cordinates() {

	return x, y, z;
}

int SpaceObject::get_mass() {

	return mass;
}

int SpaceObject::get_radius() {

	return radius;
}




///////////////////////////////////////


class Star : public SpaceObject
{

	int temperature = 0, luminosity = 0;

public:

	Star(int x0, int y0, int z0, int radius0, int mass0, int temperature0, int luminocity0);

	int get_temperature();
	int get_luminocity();
};

Star::Star(int x0, int y0, int z0, int radius0, int mass0, int temperature0, int luminocity0) {

	temperature = temperature0;
	luminosity = luminocity0;
	x = x0;
	y = y0;
	z = z0;
	mass = mass0;
	radius = radius0;
}

int Star::get_temperature() {

	return temperature;
}

int Star::get_luminocity() {

	return luminosity;
}




///////////////////////////////////////

class Moon : public SpaceObject
{
	string name;

public:

	Moon(int x0, int y0, int z0, int radius0, int mass0, string name0);

	string get_name();
};

Moon::Moon(int x0, int y0, int z0, int radius0, int mass0, string name0) {
	name = name0;
	x = x0;
	y = y0;
	z = z0;
	mass = mass0;
	radius = radius0;
}

string Moon::get_name() {
	return name;
}


///////////////////////////////////////

class Planet : public SpaceObject
{
protected:

	bool atmosphere = false;
	vector <Moon> moons;

public:

	Planet(int x0, int y0, int z0, int radius0, int mass0, bool at);

	void add_moon(Moon m);
	vector <Moon> show_moons();
	int moon_count();
};

Planet::Planet(int x0, int y0, int z0, int radius0, int mass0, bool at) {

	atmosphere = at;
	x = x0;
	y = y0;
	z = z0;
	mass = mass0;
	radius = radius0;
}

void Planet::add_moon(Moon m){

	moons.emplace_back(m);
}

vector <Moon> Planet::show_moons() {

	return moons;
}

int Planet::moon_count() {

	return moons.size();
}


///////////////////////////////////////

class Exoplanet : public Planet
{
	int probability_of_life = 0;

	void set_probability(int p0);
	int get_probability();
};

void Exoplanet::set_probability(int p0) {
	if (p0 >= 0 && p0 <= 100)
		probability_of_life = p0;
}


int Exoplanet::get_probability() {
	return probability_of_life;
}



///////////////////////////////////////

int main() {

	Star Alpha1(10232, 122344, 432121, 400, 150, 10, 2500);
	cout << "Alpha1 mass is " << Alpha1.get_mass() << " sixtilion tons" << endl << endl;

	Moon Europa(345, 567, 6, 48, 644446, "Europa");
	Moon Io(345, 567, 6, 50, 780977, "Io");

	Planet Jupiter(345, 567, 6, 457, 98787659, 1);
	Jupiter.add_moon(Europa);
	Jupiter.add_moon(Io);

	cout << "Jupiter's moons: " << endl;
	for (int i = 0; i < Jupiter.moon_count(); i++)
		cout << Jupiter.show_moons()[i].get_name() << endl;

	return 0;
}