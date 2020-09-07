#include <stdio.h>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


//input
/*
Given a sorted array of integers, return the low and high index of the given key. You must return -1 if the indexes are not found. The array length can be in the millions with many duplicates.

In the following example, according to the key, the low and high indices would be:
idx 0,1,2,3,4,5,6,7,8,9,10
key 1,2,5,5,5,5,5,5,5,5,20

key: 1, low = 0 and high = 0
key: 2, low = 1 and high = 1
key: 5, low = 2 and high = 9
key: 20, low = 10 and high = 10
*/

static int naiveruntime = 0;
static int optimizedruntime = 0;

int findLow(vector<int> input, int key)
{
	int lowIdx = 0;
	int highIdx = input.size()-1;
	
	//Knowing that the array is sorted already allows us to check the lowest value
	// and the highest value to see if the key is beyond the data provided.
	if (key > input[highIdx] || key < input[lowIdx])
	{
		naiveruntime++;
		return -1;
	}
	
	//Start from the bottom and iterate until you find the value. 
	//return that index.
	for (int i = 0; i < input.size(); i++)
	{
		naiveruntime++;
		if (key == input[i])
		{
			//cout << "lowruntime: " << i << endl;
			return i;
		}
	}
	return -1;
}

int findHigh(vector<int> input, int key)
{
	int lowIdx = 0;
	int highIdx = input.size()-1;
	
	//Knowing that the array is sorted already allows us to check the lowest value
	// and the highest value to see if the key is beyond the data provided.
	if (key > input[highIdx] || key < input[lowIdx])
	{
		naiveruntime++;
		return -1;
	}
	
	//Start from the top and iterate down until you find the value. 
	//return that index.
	for (int i = input.size(); i >= 0; i--)
	{
		naiveruntime++;
		if (key == input[i])
		{
			//cout << "highruntime: " << input.size()-i << endl;
			return i;
		}
	}
	return -1;
}


/*
Do 1 sweep via a binary search for the matching key and then jog left and right to find the low and high
*/
pair<int, int> findkeys(vector<int> input, int key)
{
	int lowIdx = 0;
	int midIdx = input.size()/2;
	int highIdx = input.size()-1;
	
	int low = -1;
	int hi = -1;
			
	pair<int, int> hi_and_lo(hi,low);
	
	int cnt = 0;
	
	//Knowing that the array is sorted already allows us to check the lowest value
	// and the highest value to see if the key is beyond the data provided.
	if (key > input[highIdx] || key < input[lowIdx])
	{
		optimizedruntime++;
		return hi_and_lo;
	}
	
	while ( midIdx != lowIdx && midIdx != highIdx && cnt++ <= input.size())
	{
		optimizedruntime++;
		//cout << "[processing] Key="<<key<<", lowIdx="<<lowIdx<<", highIdx="<<highIdx<<", midIdx="<<midIdx<<", midVal="<<input[midIdx]<<endl;
		if (key == input[midIdx])
		{
		
			//cout << "[processing] Found the key at Idx="<<midIdx<<", finding low and high" <<endl;
			int low = midIdx;
			int hi = midIdx;
			
			//Key was found, go left to find the lowest
			//store each successful match
			//if you hit something that doesn't match
			//then it's no longer your key
			for (int i = low-1; i >= lowIdx; i--)
			{
				if (input[i] != key)
					break;
				else
					low = i;
					
				optimizedruntime++;
			}
			//cout << "[processing] Low="<<low <<endl;
			
			//Now start from the intial key
			// go to the right and do the same thing 
			// as going left
			for (int i = hi+1; i <= highIdx; i++)
			{
				if (input[i] != key)
					break;
				else
					hi = i;
					
				optimizedruntime++;
			}
			//cout << "[processing] hi="<<hi <<endl;
			
			//Save the value as a pair
			hi_and_lo = pair<int,int>(hi,low);
			break;
		}
		
		if (key > input[midIdx])
		{
			//cout << "[processing] Key="<<key<<" > midVal="<<input[midIdx]<<endl;
			midIdx = (highIdx + midIdx) / 2;
		}
		else
		{
			//cout << "[processing] Key="<<key<<" <= midVal="<<input[midIdx]<<endl;
			highIdx = midIdx;
			midIdx = (midIdx) / 2;

		}
	   // cout << "[processing] midIdx changed to="<<midIdx<<", value="<<input[midIdx]<<endl;
	    
		//cin.get();
	}
	return hi_and_lo;
}


int main (int argc, char** argv)
{
	vector<int> intputvals;
	int key = -1;
	
	if (argc < 3)
	{
		cout << "Usage: " << argv[0] << " key# int1 int2 int3 int4 .... intn" << endl;
		return 0;
	}
	
	//The first parameter (after name of program) will be the key to search for
	key = stoi(argv[1]);

	//Get remaining arguments passed into the program
	// and store as ints to be processed and searched
	for (int i = 2; i <= argc-1; i++)
	{			
		int inval = stoi(argv[i]);
		intputvals.push_back(inval);
	}
	
	
	//Perform Naive search
	int loval = findLow(intputvals, key);
	int hival = findHigh(intputvals, key);
	
	//Perform optimized search
	pair<int,int> hi_and_low = findkeys(intputvals, key);
	
	
	//Pretty printing
// Example:
//		idxs:  0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 
//		keys:  1  1  1  2  2  2  2  2  3  3  3  4  4  4  4  5  5  5  6  6  6  6  6  6 
//		(Naive)     key: 2, low = 3 and high = 7, runtimecycles=22
//		(Optimized) key: 2, low = 3 and high = 7, runtimecycles=6

	cout << "idxs: ";
	for (int i = 0; i < intputvals.size(); i++)
    {
    	cout << setw(2) << i << " ";
    }
    cout << endl;
    cout << "keys: ";
    for (int i = 0; i < intputvals.size(); i++)
    {
    	cout << setw(2) << intputvals[i] << " ";
    }
    cout << endl;
    
	
	cout << "(Naive)     key: "<<key<<", low = "<<loval            <<" and high = "<<hival           <<", runtimecycles="<< naiveruntime      << endl;
	cout << "(Optimized) key: "<<key<<", low = "<<hi_and_low.second<<" and high = "<<hi_and_low.first<<", runtimecycles="<< optimizedruntime  << endl;
	
    return 1;

}
