// int a[] can only be filled with int similar with char
// still needs one that takes in both int and char -- by using vectors
#include <iostream>

using namespace std;

//declaring a structure--rarely declared inside a funciton-- sometimes inside main

struct BAccount //tag name -- template for the structure-- to store the data
{
	int acctNum; //member variables
	char lname[25];
	double atm;
};

// with a struture variable already declared
struct CAccount //template for the structure
{
	int acctNum;
	char lname[25];
	double atm;

}person1 = {123, "smith", 12.34}; // another way for declaring a structure-- decalring the variables -- cannot be passed to the fucntion
//Ba and Ca are different they have diff memory cannot be called together

//struct
//{
//	int num; // computer reserve memory whether its used or not(no tag name)
//}num1;


void displayData(BAccount );//structure deffintion comes before the prototype, not btwn diff structures
void displayDataRef(BAccount &);

int main () 
{
	//this is when it starts alocating memory
	BAccount cust1,cust2; //structure variable-- creates a structure with three slots 
	BAccount cust3 = {154, "lister", 12.34};// another way of initializing the variables
	cust1.acctNum = 1001;
	strcpy_s(cust1.lname, "gates");
	cust1.atm = 234.56; 

	cout << cust1.acctNum << " " << endl;// cust2 has created three new slots filled with garbage that why it wont compile

	cust2.acctNum = 1011;
	strcpy_s(cust2.lname, "bates");
	cust2.atm = 100.56;

	//displayData(cust1);
	displayDataRef(cust1);
	cout << cust1.acctNum << endl;

	
	return 0;
}

void displayData(BAccount rec)// only accepts BA not CA -- pass by value -- it passes the whole array down not each element
{
	cout << rec.acctNum <<endl;
	cout << rec.lname <<endl;
	cout << rec.atm <<endl;

	//rec.acctNum = 200; // doesn not change the value cuz pass by value

}

void displayDataRef(const BAccount &rec)// passing a reference point(easy and it cannot be changed) -- passes down each element
{                                       //const so that the elemetn is not changed
	cout << rec.acctNum <<endl;
	cout << rec.lname <<endl;
	cout << rec.atm <<endl;

	//rec.acctNum = 200;
}