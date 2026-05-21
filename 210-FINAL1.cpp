#include <iostream>
#include <string>
#include <fstream>
#include <map>
using namespace std;

int main()
{
	map<string, int> traffic;
	
	ifstream fin;
	fin.open("210-final-1-DP26.txt");

	string origin;
	string destination;
	string buf;

	if (fin.good()){
		while (getline(fin, buf)) {
			origin = buf.substr(0, 3);
			destination = buf.substr(4, 6);

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

}

