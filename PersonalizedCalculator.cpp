#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

struct 	History
{
	string expression;
	double result;
};

void ClearInputBuffer()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ShowMenu()
{
	cout <<"Welcome To Simple Command Line Calculator !" << endl <<" Select an option" << endl;
	cout <<"1. Basic Claculations (Multiplication, Division, Addition, Subtraction) " << endl;
	cout <<"2. Tempreture Conversion C <--> F" << endl;
	cout <<"3. Currency conversion USD <--> INR " << endl;
	cout <<"4. Length Conversion Meter <--> Kilometers" << endl;
	cout <<"5. Time Conversion Hours <--> Minutes" << endl;
	cout <<"6. Recent History" << endl;
	cout <<"7. Exit Calculator" << endl;
}

int main()
{
	int choice;
	double result;
	vector<History> History;
	
	while(true)
	{
		ShowMenu();
		cin >> choice;
		ClearInputBuffer();
		
		switch(choice)
		{
			case 1:
				cout << "Enter Your Expression (For Eg. 2+2-2*2/2) : " ;
				break;
				
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

