#include <iostream>
using namespace std;

int printArray(const int a[]);
void selection(int a[], int);
int binarySearch(int a[], int);
int linearSearch(int a[], int);

const int size = 10;

int main()
{

	int numUsed = 1, counter = 0;
	//dim the array and default everything to 0
	int mainArray[10] = {0} ;
	
	//loops for array inputs, break if user enters 0
	for(int i = 0; i <= 9; i++){
		cout << "Input number (0 to terminate): ";
		cin >> mainArray[i];
		counter++;
		cout << endl;

		if(mainArray[i] == 0)
		{ 
			counter--;
			break;
		}
	}
	//prints array as user entered it
	printArray(mainArray);
	//runs a sorting function on only the relevant numbers by sending a modified size
	selection(mainArray, size - (size - counter));
	//prints sorted array
	printArray(mainArray);

	while(numUsed != 0)
	{
	cout << "\nEnter number to search (0 to end): ";
	cin >> numUsed;

		int location = binarySearch(mainArray, numUsed);

		if (location == -1)
			cout << "Value not found.";
		else
			linearSearch(mainArray, location);

	cout << endl;

	}
	return 0;
}

int indexOfSmallest(int a[], int startIndex, int sizeUsed){
	int min = a[startIndex];
	int indexOfMin = startIndex;

	for(int index = startIndex +1; index < sizeUsed; index++){
		if(a[index] < min){
			min = a[index];
			indexOfMin = index;
		}

	}
	return indexOfMin;
}

void selection(int a[], int sizeUsed)
{
	int indexOfNextSmallest, temp;

	for(int index = 0; index < sizeUsed -1; index++)
	{
		indexOfNextSmallest = indexOfSmallest(a, index, sizeUsed);
		temp = a[indexOfNextSmallest];
		a[indexOfNextSmallest] = a[index];
		a[index] = temp;

	}
}

int binarySearch(int a[], int target)
{
	int first = 0;
	int last = size -1;
	int mid = -1;
	bool found = false;

	while (first <= last && found == false) /*&& target != 0*/
	{

		mid = (first + last)/2;
		cout << mid << endl;

		if(a[mid] == target)
		{
			found = true;		
			
		}
		else 
			if(a[mid] > target || a[mid] == 0)			
				last = mid - 1;			
			else			
				first = mid + 1;
	}

	if(found==true)
		return mid;
	else
		return -1;
	

}

int linearSearch(int a[], int start){
	int target = a[start];
	int first;
	for(int i = start; a[i] == target; i--)
		first = i;
	
	cout << "Value found in element: " << first << endl;
	for(int i = first+1; a[i] == target; i++)
		cout << "And in element number: " << i << endl;
	
	return 0;
}

int printArray(const int a[])
{
	for(int i = 0; i <= 9; i++)
		cout << a[i] << " ";
	
	cout << endl;
	return 0;
}