#include <iostream>
#include <fstream>	
#include <string>

using namespace std;

bool compare(string findWord, string readWord)
{
	if (findWord.size() != readWord.size())
	{
		return false;
	}

	for (int i = 0; i < findWord.size(); i++) 
	{
		if(tolower(findWord[i]) != tolower(readWord[i]))
		{
			return false;
		}
	}
	return true;
}


using namespace std;

int main()
{
	int wordCount = 0;
	string findWord = "";

	//Obtains Users word
	cin >> findWord;

	//Reads the file
	fstream read("words.txt");

	//Returns 1 if the program can't be read
	if (!read)
	{
		return 1;
	}

	while (read)
	{
		//Searches each word and stores it into readWord
		string readWord;
		read >> readWord;
		
		//Checks if readWord is the same as the user's input
		if (compare(findWord, readWord))
		{
			wordCount++;
		}

	}

	//Outputs the amount of times the word was read in the file		
	cout << wordCount << endl;
	

    return 0;
}

