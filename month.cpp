#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

map<int, int> months = 
{
	{1,31},
	{2,28},
	{3,31},
	{4,30},
	{5,31},
	{6,30},
	{7,31},
	{8,31},
	{9,30},
	{10,31},
	{11,30},
	{12,31}
};

int days(int month)
{
	if (month <= 12 && month >= 1)
		return months[month];
	else
		return -1;
}

typedef struct Date
{
	int day;
	int month;
	int year;

} Date;
ostream& operator << (ostream &os, const Date &date) {
    return (os <<  date.month << "/" << date.day << "/" << date.year);
}


bool  greaterThanMonth(Date date1, Date date2)
{
	
	int diff = 0;
	int date1total = date1.year*10000 + date1.month*100 + date1.day;
	int date2total = date2.year*10000 + date2.month*100 + date2.day;
	cout << "date1total: " << date1total << endl;
	cout << "date2total: " << date2total << endl;
	
	bool date1greater = (date1total > date2total);

	Date tmpDate;
	if (date1greater)
		tmpDate = date2;
	else
		tmpDate = date1;

	tmpDate.month = tmpDate.month + 1;
	if (tmpDate.month>12)
	{
		tmpDate.month = 1;
		tmpDate.year = tmpDate.year + 1;
	}
	int tmpDatetotal = tmpDate.year*10000 + tmpDate.month*100 + tmpDate.day;
	
	if (tmpDatetotal < date2total)
		return true;
	else
		return false;
}

int main (int argc, char** argv)
{
	bool leapyear = false;
	int argvit = 0;
	Date day1;
	Date day2;
		
	if (argc > 5)
	{

     	day1.month  = stoi(argv[++argvit]);
		day1.day = stoi(argv[++argvit]);
		day1.year= stoi(argv[++argvit]);
		
		day2.month  = stoi(argv[++argvit]);
		day2.day = stoi(argv[++argvit]);
		day2.year= stoi(argv[++argvit]);
		
		string res = greaterThanMonth(day1,day2)?"":" NOT";
    	cout << "Compare: " << day1 << " is" << res << " more than a month from " << day2 << endl;
    }
    else
    {
    	cout << "invalid entry: mm1 dd1 yyyy1 mm2 dd2 yyyy2" << endl;
    }

    
    return 0;

}
