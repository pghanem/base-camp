#include <iostream>
#include <string>
using namespace std;

int acceptSelection();
int main_menu();
int voltCapAccept();
int voltCapCalc(int battVol, int iniRes, int finaRes, double capVal);

const double e = 2.71828;

int main()
{
	acceptSelection();
	return 0;
}

int acceptSelection(){

		main_menu();
		char choice;
		cin >> choice;

		switch(choice)
		{
			case 'v':
			case 'V':
			case '1':
				system("cls");
				voltCapAccept();
				break;

			case 'e':
			case 'E':
			case '0':
				cout << "Exit!\n\n";
				break;

			default:
				system("cls");
				acceptSelection();
		}
		
	return 0;
}

int voltCapAccept(){

	int battVoltage, initialRes,  finalRes;
	double capValue;
	cout << "Voltage values across a capacitor\n\n" << endl;

	cout << "Please enter battery voltage (integer) <0 for Quick exit>: ";
	cin >> battVoltage;
	if (battVoltage == 0){

	}
	cout << "Please enter initial resistance value (integer) from: ";
	cin >> initialRes;
	cout << "Please enter final resistance value (integer) to:     ";
	cin >> finalRes;

	//my way of reversing values if the initial resistance is greater than the final
	if (initialRes > finalRes){
		initialRes = initialRes + finalRes;
		finalRes = initialRes - finalRes;
		initialRes = initialRes - finalRes;
	}

	cout << "Please enter capacitor value (MUST be between 0.1 and 0.9 inclusive): ";
	cin >> capValue;
	//making sure the capacitor value is in acceptable range
	while (capValue < 0.1 || capValue > 0.9){
		cout << "\nRe-enter capacitor value (MUST be between 0.1 and 0.9 inclusive): ";
		cin >> capValue;
	}

	voltCapCalc(battVoltage, initialRes, finalRes, capValue);

	return 0;
}

int voltCapCalc(int battVol, int iniRes, int finaRes, double capVal){
	int time, calc = 1;
	//temp while until i figure out 95% calc
	while(1 == calc){
		for (calc==0; calc < 95; calc++){

		}


	}

	double vAtTimeT = battVol * (1 - pow(e,-time) / (
		cout << " vol: " << battVol << " initial: " << iniRes << " final: " << finaRes << " cap: " << capVal << endl;
	
		return 0;
}

int main_menu(){

	cout << "		Peter Ghanem Scientific Analysis";
	cout << "\n\n\n\n	1.		V)oltage values across a capacitor Table";
	cout << "\n\n\n\n\n\n\n	0.		E)xit";
	cout << "\n\n			Enter Choice: ";

	return 0;
}




