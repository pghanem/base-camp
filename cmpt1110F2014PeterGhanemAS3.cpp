#include <iostream>
#include <string>
using namespace std;

void passwordGenerate(string &, string & , string &);

int main()
{
	string lstnm, pc, bday;
	string password;

	cout << "\t\t Your Name Magazine Subcription Password Generator" << endl;

	cout << "Enter lastname\t:";
	getline(cin,lstnm);
	
	if(!lstnm.empty())
	{
		cin.ignore(6,'\n');
		cout << "Postcode\t:";
		getline(cin,pc);
			
		
		while(pc.length () > 6)
		{
			cout << "re-enter Postcode, must be 6 characters long:";
			getline(cin,pc);
		}


		cout << "Birthdate mm/yy\t:";
		getline(cin,bday);

		passwordGenerate(lstnm, pc, bday);
	}

	cout << pc;

	cout << "Agian (y/n)" << endl;

	

	return 0;
}

void passwordGenerate(string &l, string &p , string &b)
{
	for(int a=0; a < 4; a++)
	{
		p[a] = toupper(p[a]);
	}

	/*for(int q = l.length -2; q < l.length; q++)
	{
		l[q] = 
	}*/


}
