#include <iostream>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string>

using namespace std;

// this is a function stub that allows it to be called, 
// because it preceeds the main function, the program won't find it
// bool hasSymbols();

char lettersArray [] = { 
	'a', 
	'b', 
	'c', 
	'd', 
	'e', 
	'f', 
	'g', 
	'h', 
	'i', 
	'j',
	'k', 
	'l', 
	'm', 
	'n', 
	'o',
	'p', 
	'q', 
	'r',
	's', 
	't', 
	'u', 
	'v', 
	'w', 
	'x', 
	'y', 
	'z'
};

char symbolsArray [] = {
	'`',
	'~',
	'-',
	'_',
	'=',
	'+',
	'[',
	'{',
	']',
	'}',
	'\\',
	'|',
	';',
	':',
	'\'',
	'\"',
	',',
	'<',
	'.',
	'>',
	'/',
	'?',
	'!',
	'@',
	'#',
	'$',
	'%',
	'^',
	'&',
	'*',
	'(',
	')'
};

char numbersArray [] = {
	'1',
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'0'
};

string generatePassword(int passLen)
{
	int charType;
	int index;

	string passwd;

	int letLen = (sizeof(lettersArray) / sizeof(*lettersArray));
	int numLen = (sizeof(numbersArray) / sizeof(*numbersArray));
	int symLen = (sizeof(symbolsArray) / sizeof(*symbolsArray));

	for(int i=1 ; i <= passLen ; i++)
	{
		srand((unsigned int)time(NULL) + i);
		charType = rand() % 3;

		switch (charType)
		{
			case 0:
				srand((unsigned int)time(NULL) + i + 1);
				index = rand() % letLen;
				passwd += lettersArray[index];
				// cout << "Letters: " << passwd << "\n";
				break;
			case 1:
				srand((unsigned int)time(NULL) + i + 2);
				index = rand() % numLen;
				passwd += numbersArray[index];
				// cout << "Numbers: " << passwd << "\n";
				break;
			case 2:
				srand((unsigned int)time(NULL) + i + 1);
				index = rand() % symLen;
				passwd += symbolsArray[index];
				// cout << "Symbols: " << passwd << "\n";
				break;
		}
	}
	return passwd;
}

void help() 
{
	cout << "SYNOPSIS" << endl;
	cout << "\tgenpass [LENGTH]\n" << endl;
	cout << "DESCRIPTION" << endl;
	cout << "\tGenpass is a simple command-line utility to generate secure passwords." << endl;
	cout << "\tJust pass a length for the password, and the util will do the rest." << endl;
}




int main(int argc, char** argv)
{
	
	bool letters;
	bool numbers;
	bool symbols;
	int length;

	string passwd;
	bool verboseMode = false;

	int opt;
	string input = "";

	/*
	 Parse arguments
	*/


	while ((opt = getopt(argc, argv, "-h")) != -1) {
		switch (opt) {
			case 'h':
				help();
				return 0;
			case '?':
				cerr << "Unknown option: '" << char(optopt) << "'!" << endl;
				break;
		}
	}

	if ( (argc <=1) || (argv[argc-1] == NULL) || (argv[argc-1][0] == '-') ) {
		cerr << "No length argument provided" << endl;
		return 1;
	}
	else {
		input = argv[argc-1];
	}

	opterr = 0;

	length = std::stoi(input);
	passwd = generatePassword(length);

	if (verboseMode == true)
	{
		cout << "Password Generated:" << endl;
	}

	cout << passwd << endl;

	return 0;
}
