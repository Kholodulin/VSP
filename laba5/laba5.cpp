#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

class IVehicle {
public:
	virtual bool drive(int kilometres) = 0;
	virtual void refuel() = 0;
	virtual void printstatus() = 0;
};

class Abstractcar : public IVehicle {
protected:
	double max_fuel_level;
	double litres_km;
	double probeg;
	double fuel_level;
public:
	Abstractcar(double _max_fuel_level, double _litres_km, double _probeg, double _fuel_level) { max_fuel_level = _max_fuel_level; litres_km = _litres_km; probeg = _probeg; fuel_level = _fuel_level; }
	Abstractcar(double _max_fuel_level, double _litres_km) { max_fuel_level = _max_fuel_level; litres_km = _litres_km; probeg = 0; fuel_level = 0; }
	Abstractcar() { max_fuel_level = 0; litres_km = 0; probeg = 0; fuel_level = 0; }

	bool drive(int kilometres) {
		double need_fuel;
		need_fuel = kilometres * litres_km / 100;
		if (need_fuel <= fuel_level) {
			fuel_level -= need_fuel;
			probeg += kilometres;
			return true;
		}
		else {
			return false;
		}
	}

	void refuel() { fuel_level = max_fuel_level; }
	void printstatus() {
		cout << "Fuel level is " << fuel_level << endl;
		cout << probeg << "km was driven\n";
	}
};

class Sedan : public Abstractcar {
public:
	Sedan() : Abstractcar(75, 10) {}
};
class Suv : public Abstractcar {
public:
	Suv() :Abstractcar(150, 20) {}
};
class Bus : public Abstractcar {
public:
	Bus() :Abstractcar(250, 23) {}
};

class Bicycle : public IVehicle {
protected:
	double probeg;
public:
	Bicycle() { probeg = 0; }
	bool drive(int kilometres) {
		probeg += kilometres;
		return true;
	}
	void refuel() {}
	void printstatus() { cout << probeg << "km was driven\n"; }
};

struct RoutePoint {
	double xKm;
	double yKm;
	string name;
public:
	RoutePoint(double x, double y, string _name) { xKm = x; yKm = y; name = _name; }
};

class Route {
private:
	vector<RoutePoint>route;
public:
	void addPoint(const RoutePoint& point) {
		route.push_back(point);
	}
	void run(IVehicle* vehicle) {
		if (route.size() < 2) { cout << "not enough points\n"; return; }
		double way = 0;
		for (int i = 0; i < (route.size() - 1); i++) {
			way = sqrt(pow((route[i + 1].xKm - route[i].xKm), 2) + pow((route[i + 1].yKm - route[i].yKm), 2));
			if (vehicle->drive(way)) {
				vehicle->printstatus();
			}
			else {
				vehicle->refuel();
				vehicle->drive(way);
				vehicle->printstatus();
			}
		}
	}
};

int main(int argc, char* argv[]) {
	if (argc < 2) { cout << "no arguments"; return 0; }

	ifstream fin;
	string file_name;

	for (int k = 1; k < argc; k++) {
		Route routes;
		cout << argv[k] << " opening...\n" << endl;
		file_name = argv[k];
		fin.open(file_name);

		if (!fin.is_open()) {
			cout << "Error! file not open\n";
		}
		else {
			double x, y;
			string point, str;
			int count = 1;
			while (!fin.eof()) {
				str = "";
				fin >> str;
				switch (count) {
				case 1: x = stoi(str);
					break;
				case 2: y = stoi(str);
					break;
				case 3: point = str;
					break;
				}
				if (count == 3) {
					count = 0;
					routes.addPoint(RoutePoint(x, y, point));
				}
				count++;

			}
			IVehicle* vehicles[4] = { new Sedan, new Suv, new Bus, new Bicycle };

			for (int i = 0; i < 4; i++) {
				IVehicle* vehicle = vehicles[i];
				routes.run(vehicles[i]);
				cout << endl;
				delete vehicle;
			}

		}
		fin.close();
	}
	system("pause");
	return 0;
}
