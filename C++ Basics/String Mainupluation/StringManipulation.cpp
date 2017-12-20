#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;

	vector<string> words;

	while (input != "quit") {
		cin >> input;

		if (input.size() > 1){
			words.push_back (input);
		}
		else {
			//Got helped from Nick
			for (int j = 0; j <= words.size(); j++) {	
				if (words[j][0] == input[0]) {
					cout << words[j] << endl;
					break;
				}
			}
		}
	}
    return 0;

}

