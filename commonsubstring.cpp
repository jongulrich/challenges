#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;


//input
//ABCDGHZZ
//ACDGHRZZ
//Given two strings X and Y. The task is to find the length of the longest common substring.

string naiveFindCommonSubstring(vector<string> strings)
{
	string currentSubstring("");
	
	
	for (int i = 0; i < strings.size(); i++)
    {
		for (int j = i+1; j < strings.size(); j++)
		{
			string string1 = strings[i];
			string string2 = strings[j];
			
			//if (i == 0 && j == i+1)
			{
				cout << "Comparing: "<< string1 <<" and "<< string2 <<" " <<endl;
			}
    
			string workingSubstring("");
			for (int k = 0; k < string1.length(); k++)
			{
				string candidateSubstring("");
				string testingSubstring("");
				for (int l = 0; k < string1.length() && l < string2.length(); l++)
				{
					
					/*
					Compare 
					*/
					//cout << "do '"<<string1.at(k)<<"' and '"<<string2.at(l)<<"' match?" << endl;
					
					if (string1.at(k) == string2.at(l))
					{
						testingSubstring.append(string1, k, 1);
						cout << "Yes, appended: " << testingSubstring << endl;
						k++;
					}
					else
					{
						testingSubstring.clear();
					}
					
					if (candidateSubstring.length() < testingSubstring.length())
					{
						candidateSubstring = testingSubstring;
					}
				}
				
				if ( currentSubstring.length() < candidateSubstring.length() )
				{
					currentSubstring = candidateSubstring;
					cout << "New longest substring: " << currentSubstring << endl;
				}

			}
			

		}
    }
    return currentSubstring;
}

int main (int argc, char** argv)
{
	vector<string> strings;

	//only works for two at the moment
	for (int i = 1; i <= 2; i++)
	{
		string string(argv[i]);
		strings.push_back(string);
	}
	
	//print
    for (int i = 0; i < strings.size(); i++)
    {
    	cout << strings[i] << endl;
    }
    
	string substring = naiveFindCommonSubstring(strings);
	cout << "Common Substring (naive) " << substring << endl;
    return 0;

}
