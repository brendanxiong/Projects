#define _CRT_SECURE_NO_DEPRECATE

#include "utilities.h"
	#include <iostream>
	#include <cctype>
#include <cstring>
	using namespace std;

	const char WORDFILENAME[] = "C:/Users/Brendan Xiong/Dropbox/medicareUnion/WordPuzzle/wordFile.txt";
	int runOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum);

	int main()
	{
	    /*char w[9000][7];
	    int n = getWords(w, 9000, WORDFILENAME);
	    if (n == 2)
	    {
		cout << "getWords successfully found the file and read its two words." << endl;			//remember to take this out
		cout << "You're ready to start working on Project 5." << endl;
	    }
	    else if (n == -1)
		cout << "The path to your file of words is probably incorrect" << endl;
	    else
		cout << "getWords found the file, but loaded " << n
                     << " words instead of 2" << endl;*/
		const int MAXWORDS = 9000;
		const int MAXWORDLEN = 6;

		int rounds = 0;
		int random = 0;								//declare all variables here
		char secret[7];
		int length = 0;
		int tries = 0;
		int tryList[10000];
		double average = 0;
		int min = 0;
		int max = 0;
		double tryNum = 0;
		double sum = 0;
		int temp = 0;
		int temp2 = 10000;

		char wordList[MAXWORDS][MAXWORDLEN + 1];
		int nWords = getWords(wordList, MAXWORDS, WORDFILENAME);

		if (nWords < 1)
		{
			cout << "No words were loaded, so I can't play this game" << endl;		//check for words

		}

		else if (nWords >= 1 && nWords <= MAXWORDS)
		{
			

			cout << "How many rounds do you want to play? ";

			
			cin >> rounds;
			cin.ignore(10000, '\n');
			if (rounds <= 0)
			{
				cout << "The number of rounds must be positive." << endl;		//ask for and check rounds
				return -1;
			}

			
				for (int i = 1; i <= rounds; i++)
				{
					
					random = randInt(0, nWords - 1);
					strcpy(secret, wordList[random]);						//create a random integer
					length = strlen(secret);

					cout << endl  << "Round " << i << endl;
					cout << "The secret word is " << length << " letters long." << endl;

				tries=	runOneRound(wordList, nWords, random);
				if (tries == 1)
				{

					cout << "You got it in " << tries << " try." << endl;
					
																						//make sure to change tries to try for one try
				}
				else
				{
					cout << "You got it in " << tries << " tries." << endl;
				}
				tryList[i - 1] = tries;
				tryNum++;
				sum = 0;
				for (int z = 0; z < tryNum; z++)							//calculate the average
				{
					sum += tryList[z];
					
				}

				for (int o = 0; o<tryNum; o++)
				{
					if (tryList[o]>temp)								//calculate the min/max
						temp = tryList[o];
				}

				for (int p = 0; p<tryNum; p++)
				{
					if (tryList[p]<temp2)
						temp2 = tryList[p];
				}
				average = sum / tryNum;
				min = temp2;
				max = temp;
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << "Average: " << average << ", minimum: " << min << ", maximum: " << max  << endl;			//output average
				
				
			}
		}
	}

	int runOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
	{
		char probe[10000] = "";
		int tries = 0;
		int stars = 0;
		int planets = 0;														//declare all variables
		char secret2[7];
		strcpy(secret2, words[wordnum]);
		for (;;)
		{
			stars = 0;
			planets = 0;
			strcpy(secret2, words[wordnum]);
			//cout << secret2 << endl;
			cout << "Probe word: ";
			//cin >> probe;

			cin.getline(probe, 100);					//get the word
			
			int compare = 0;
			int test = 0;


			for (int j = 0; j < strlen(probe); j++)
			{
				if (isupper(probe[j]) || isdigit(probe[j]) || (probe[j]==' '))		//make sure word is syntactically correct
				{
					test++;
				}
			}

			for (int z = 0; z < nWords; z++)
			{
				if (strcmp(probe, words[z]) == 0)						//make sure the word is in the list
					compare++;
			}
		

			if ((strlen(probe) < 4 || strlen(probe) > 6) || test != 0)
			{
				cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;  //make sure the word is within length
				
			}
			
			else if (compare == 0)
			{
				cout << "I don't know that word." <<  endl;	//output if word not in list
				
			}

			else
			{
				tries++;
			for (int i = 0; i < strlen(secret2); i++)
			{
				if (secret2[i] == probe[i])					//replace stars so they're not read again
				{
					stars++;
					secret2[i] = 'A';

					if (stars == strlen(secret2))
					{
						return tries;
						//break;
					}
					
				}
				for (int k = 0; k < strlen(secret2); k++)		//do the same for planets
				{
					if (probe[k] == secret2[i])
					{
						planets++;
						probe[k] = 'A';
						
					}
				}
			}
	
			cout << "Stars: " << stars << ", Planets: " << planets << endl;			//outputting stars and planets
			
		}
			
	}
	}