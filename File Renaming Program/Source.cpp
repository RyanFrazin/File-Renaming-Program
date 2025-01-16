#include<iostream>;
#include<filesystem>;
#include<fstream>;
#include<string>;
#include<cstdio>;
namespace fs = std::filesystem;
using namespace std;

int main() {
	std::string sourceFolder;
	fs::path destinationFolder;
	cout << "Enter the path of the source directory: ";
	cin >> sourceFolder;
	cout << "Enter the path of the output director: ";
	cin >> destinationFolder;


	if (fs::exists(sourceFolder) && fs::is_directory(sourceFolder)) {
		for (const auto& entry : fs::directory_iterator(sourceFolder)) {
			fs::path destPath = destinationFolder / entry.path().filename();
			
			while (fs::exists(destPath)) {
				std::string newName = "file_" + std::to_string(time(nullptr)) + entry.path().extension().string();
				destPath = destinationFolder / newName;
			}
			
			fs::copy(entry.path(), destPath);
			cout << entry.path().string() << " has been copied successfully." << endl;
		}
	} else {
		cerr << "The provided path is not a valid directory." << endl;
	}


	return 0;
}