#include <iostream>

//officially c++ calsss replaces sturct

using namespace std;

struct date
{
	int month;
	int day;
	int year;
};

struct BAccount //template for the structure-- to store the data
{
	int acctNum; //member variables
	char lname[25];
	date birth; //structure within strucutre must be declared before BA
	double amt;

};



int main () 
{
	BAccount cust1;
	cust1.acctNum = 101;//alway the structure variable not the name of the structure
	strcpy_s(cust1.lname, "gates");
	cust1.amt = 100.0; 
	cust1.birth.month = 11;



	return 0;
}

//void displayData(BAccount rec)
//{
//	cout << rec.acctNum <<endl;
//	cout << rec.lname <<endl;
//	cout << rec.atm <<endl;
//
//}