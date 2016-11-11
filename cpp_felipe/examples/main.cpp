#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
 
int main(int argc, char *argv[]) {
    using namespace std;

    string fileName = argv[1];
    vector<int> procData; /* param order
							1- init time
							2- priority
							3- cpuTime
							4- memBlocks
							5- printerCode
							6- scannerCode
							7- modemCode
							8- diskCode
							 */
    ifstream inputFile;
    int i;
 	
 	// open file for reading
    inputFile.open(fileName.c_str());
 	
 	if(inputFile.is_open()) {
 		// read file (if sucessfully opened) until the end
	    string str;
	    
		while (getline(inputFile, str)) {
			cout << "string atual: [" << str << "]" << endl;
			stringstream ss(str);
			while(ss >> i) {
				procData.push_back(i);
				if (ss.peek() == ',') {
					ss.ignore();
				}
			}
			ss.str("");
			ss.clear();

			for (i=0; i < procData.size(); i++) {
				cout << procData.at(i) << ' ';
			}
			cout << endl;
		}

	    inputFile.close();
 	}
    
    return 0;
}

