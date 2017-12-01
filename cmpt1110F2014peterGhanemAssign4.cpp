#include <iostream>
using namespace std;
void mainMenu();

class clearScreen{
public:
	static void clrscr()
	{
		system("CLS");
	}
	static void clrscr(int a)
	{
		for (int i = 0; i < a; i++){
			cout << endl;
		}
	}
};

class Pay{
public:
	Pay::Pay();

	double Pay::calc_payroll();
	double Pay::tax(double);

	void Pay::setHoursWorked(double);
	int Pay::getHoursWorked() const;

	void Pay::setRate(double);
	int Pay::getRate() const;

	void Pay::setStraightHours(int);
	int Pay::getStraightHours() const;

private:
	double hoursWorked;
	double hourlyRate;
	int straightHours;
};

class Payroll : public Pay
{
public:
	double Payroll::calc_payroll();
	Payroll::Payroll(double, int, double);
private:
};

class PayrollInOut : public Pay
{
public:
	void PayrollInOut::displayInfo();
	void PayrollInOut::acceptPay();
private:
};

Pay::Pay()
	:hoursWorked(0), hourlyRate(0), straightHours(0)
{
}
Payroll::Payroll(double d, int i, double dd)
{
	setHoursWorked(d);
	setStraightHours(i);
	setRate(dd);
}


int main(){
	mainMenu();
	return 0;
}

void mainMenu(){
	//do{
	cout << "		Peter Ghanem Business Utilities";
	clearScreen::clrscr(4);
	cout << "1.		P)ayroll Computation";
	clearScreen::clrscr(3);
	cout << "2.		E)xit";
	clearScreen::clrscr(3);
	cout << "		Enter choice: ";
	char input;
	cin >> input;
	input = toupper(input);
	if(input == 'P' || input == '1'){

		PayrollInOut person;
		person.acceptPay();
		person.displayInfo();

	}
	//}(while input != 'e' || input != '2');
}

void PayrollInOut::acceptPay()
{
	double h, r;
	int sh;
	cout << "Enter number of hours worked (00.0): ";
	cin >> h;
	cout << "Enter first number of hours straight (integer or 0 to disable): ";
	cin >> sh;
	cout << "Enter hourly rate of worker (00.00):";
	cin >> r;
	setHoursWorked(h);
	setRate(r);
	setStraightHours(sh);
	cout << "===================================================" << endl;
}

void PayrollInOut::displayInfo()
{

	double grossPay = calc_payroll();

	cout << "Gross pay is : $" << grossPay << endl;
	cout << "Tax rate is : " << tax(grossPay) * 100 << "%" << endl;
	Payroll hydra(getHoursWorked(), getStraightHours(), getRate());

	cout << "Net pay is : $" << hydra.calc_payroll() << endl;
}

double Payroll::calc_payroll() // Net Pay
{
	double netPay;
	double grossPay = Pay::calc_payroll();
	double taxRate = tax(grossPay);

	netPay = grossPay - (grossPay * taxRate);
	return netPay;
}

double Pay::calc_payroll() // Gross Pay
{
	double grossPay;
	if(straightHours == 0){
		grossPay = hourlyRate * hoursWorked;
	}else{
		if(hoursWorked > straightHours){
			grossPay = (straightHours * hourlyRate) + ((hoursWorked - straightHours) * (hourlyRate * 1.5));
		}else{
			grossPay = hourlyRate * hoursWorked;
		}
	}
	return grossPay;
}

double Pay::tax(double amount)
{
	double taxRate;
	if(amount < 500.0){
		taxRate = 0.08;
	}else if (amount >= 1000.0){
		taxRate = 0.15;
	}else{
		taxRate = 0.10;
	}
	return taxRate;
}

void Pay::setHoursWorked(double hw)
{
	hoursWorked = hw;
}

int Pay::getHoursWorked() const
{
	return hoursWorked;
}

void Pay::setRate(double r)
{
	hourlyRate = r;
}

int Pay::getRate() const
{
	return hourlyRate;
}

void Pay::setStraightHours(int sh)
{
	straightHours = sh;
}

int Pay::getStraightHours() const
{
	return straightHours;
}