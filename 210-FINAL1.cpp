#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

void airportRange(map<string, int>, int, int);

int main()
{
	//Milestone 1
	map<string, int> traffic;
	
	ifstream fin;
	fin.open("210-final-1-SP26.txt");

	string origin;
	string destination;
	string buf;

	if (fin.good()){
		while (getline(fin, buf)) {
			origin = buf.substr(0, 3);
			destination = buf.substr(4, 3);

			traffic[origin]++;
			traffic[destination]++;
		}

		fin.close();

	}
	else {
		cout << "File not found";
	}

	cout << "All airport traffic counts: " << endl;
	for (const auto& airport : traffic) {
		cout << airport.first << " " << airport.second << endl;
	}

	//Milestone 2
	int maxTraffic = 0;
	for (const auto& airport : traffic) {
		if (airport.second > maxTraffic) {
			maxTraffic = airport.second;
		}
	}

	cout << endl << "Busiest airport(s) with count " << maxTraffic << ":" << endl;
	for (const auto& airport : traffic) { 
		if (airport.second == maxTraffic) {
			cout << airport.first << " " << airport.second << endl;
		}
	}

	cout << endl;
	airportRange(traffic, 5, 8);
	cout << endl;
	airportRange(traffic, 9, 12);
	//Milestone 4
	cout << endl;
	airportRange(traffic, 1, 3);

}

//Milestone 3
void airportRange(map<string, int> traffic, int low, int high) {
	cout << "Airports with traffic in range [" << low << ", " << high << "]: " << endl;

	for (const auto& airport : traffic) {
		if (airport.second >= low && airport.second <= high) {
			cout << airport.first << " " << airport.second << endl;
		}
	}
}
