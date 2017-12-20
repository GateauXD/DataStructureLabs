#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	//Obtains the file and reads it
	ifstream inf("words.txt");

	int WhiteSpaceCount = 0;

	//If the file isn't found then it will return a 1 reporting that something went wrong
	if (!inf)
	{
		return 1;
	}

	//While there is something to read then it will go through this process
	while (inf)
	{
		string word;
		inf >> word;
		WhiteSpaceCount++;
	}
	cout << WhiteSpaceCount -1 << endl;

    return 0;
}

