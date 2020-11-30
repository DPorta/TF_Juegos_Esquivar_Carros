#include <string>
#include <iostream>

using namespace std;

void fatalError(std::string errorString) {

	cout << errorString << endl;
	cout << "Enter any key to quit " << endl;
	int tmp;
	cin >> tmp;
	exit(-1);

}