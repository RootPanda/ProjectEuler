#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	string value;
	vector<string> namesVect;
	ifstream fin;
	fin.open("names.txt");
	while (fin.good())
	{
		getline(fin, value, ',');
		namesVect.push_back(string(value, 1, value.length()-2));
	}
	
	// Sort the vector
	sort(namesVect.begin(), namesVect.end());

	int retVal = 0;

	for (vector<string>::iterator it = namesVect.begin(); it != namesVect.end(); ++it)
	{
		int nameWeight = 0;
		for (int i = 0; i < (*it).size(); i++)
		{
			nameWeight += (int)((*it)[i]) - 'A' + 1;
		}

		int pos = it - namesVect.begin() + 1;
		retVal += pos * nameWeight;
	}
	
	cout << "Answer: " << retVal << endl;
}
