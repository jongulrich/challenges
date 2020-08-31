#include <stdio.h>
#include <iostream>

using namespace std;
int main (int argc, char** argv)
{
    int month1 = std::stoi(argv[1]);
    int day1 = std::stoi(argv[2]);
    int month2 = std::stoi(argv[3]);
    int day2 = std::stoi(argv[4]);
    
    cout << "Compare: " << month1 << "/" << day1 << " & " << month2 << "/" << day2 << endl;
    return 0;

}
