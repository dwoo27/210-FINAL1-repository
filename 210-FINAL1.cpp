#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

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
	int maxTraffic;
}

