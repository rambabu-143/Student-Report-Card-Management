#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	int roll;
	float OOPs, ADE, DS, COSM, COA, average;
public:

	void InsertData(string n, int r, float oop, float ade, float ds, float cosm, float coa)
	{
		name = n;
		roll = r;
		OOPs = oop;
		ADE = ade;
		DS = ds;
		COSM = cosm;
		COA = coa;

		average = (OOPs + ADE + DS + COSM + COA) / 5;
	}
	


//<---------Grade calculation section completed------->
	int GetRoll()
	{
		return roll;
	}

	void Report()
	{
		cout << "\nBIET STUDENT REPORT" << endl;
		cout << "==============" << endl << endl;
		cout << "Name: " << name << endl;
		cout << "Roll Number: " << roll << endl;
		cout << "OOPs Marks: " << OOPs << endl;
		cout << "ADE Marks: " << ADE << endl;
		cout << "DS Marks: " << DS << endl;
		cout << "COSM Marks: " << COSM << endl;
		cout << "COA Marks: " << COA << endl;
		cout << "Average Marks: " << average << endl;
		cout << "GPA: " << average / 10 << endl;
	}
};

//Vector is used instead of an array due to its flexibility in size extension

vector<Student> database;
int databaseSize;

void PrintReport(int roll)
{
	for (int i = 0; i < databaseSize; i++)
		if (database[i].GetRoll() == roll)
		{
			database[i].Report();
			return;
		}

	cout << "\nTHE ENTERED ROLL NUMBER:(" << roll << ") DOES NOT EXIST.\n" << endl;
}

void ResizeDatabase()
{
	database.resize(databaseSize);
}

void ShowStats()
{
	cout << "\nSIZE: " << databaseSize << endl;
	cout << "STUDENT LIST (ROLL): ";

	if (databaseSize == 0)
	{
		cout << "DATABASE IS EMPTY\n" << endl;
		return;
	}
    else{
        
	for (int i = 0; i < databaseSize; i++)
		cout << database[i].GetRoll()<<endl;

	cout<< "\n" << endl;
}

}

void Add()
{
	string name;
	int roll;
	float OOPs, ADE, DS, COSM, COA;

	cout << "\nPLEASE ENTER THE DETAILS OF THE STUDENT:" << endl;
	cout << "NAME: ";
	cin.ignore();
	getline(cin, name);
	cout << "ROLL: ";
	cin >> roll;
	cout << "MARKS IN OOPs, ADE, DS, COSM AND COA: ";
	cin >> OOPs >> ADE >> DS >> COSM >> COA;
	cout << "\nSTUDENT DATA ADDED TO DATABASE" << endl;

	databaseSize++;
	ResizeDatabase();
	database[databaseSize - 1].InsertData(name, roll, OOPs, ADE, DS, COSM, COA);
}

void Delete(int roll)
{
	for (int i = 0; i < databaseSize; i++)
		if (database[i].GetRoll() == roll)
		{
			database.erase(database.begin() + i);
			cout << "\nSTUDENT WITH ROLL NUMBER" << roll << " HAS BEEN REMOVED FROM THE DATABASE\n" << endl;
			databaseSize--;
			return;
		}

	cout << "\nTHE ENTERED ROLL NUMBER: (" << roll << ") DOES NOT EXIST.\n" << endl;
}

int main()
{
	int choice, roll;

	cout << "STUDENT REPORT MANAGEMENT" << endl;
	cout << "==================================" << endl;

	do
	{
		cout << "\n1. ADD NEW STUDENT DATA\n2. DELETE STUDENT DATA\n3. PRINT REPORT\n4. DATABASE STATS\n0. EXIT" << endl;
		cout << "YOUR CHOICE: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Add();
			break;

		case 2:
			cout << "ROLL: ";
			cin >> roll;
			Delete(roll);
			break;

		case 3:
			cout << "ROLL: ";
			cin >> roll;
			PrintReport(roll);
			break;

		case 4:
			ShowStats();
			break;

		case 0:
			break;

		default:
			cout << "\nINVALID CHOICE\n" << endl;
			break;
		}
	} while (choice);

	return 0;
}
