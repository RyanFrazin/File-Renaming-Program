#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main() {
	string sourceFileName, destinationFileName;

	cout << "Enter the name of the source file: ";
	cin >> sourceFileName;
	cout << "Enter the name of the destination file: ";
	cin >> destinationFileName;

	ifstream sourceFile(sourceFileName);
	ofstream destinationFile(destinationFileName);


}