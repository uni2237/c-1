#include <iostream>
#include <stdexcept> //예외처리
#include "Database.h"

using namespace std;
using namespace Records;



//함수들 선언 

int displayMenu(); //메뉴를 보고 어떤 메뉴를 실행할지를 결정하면 값을 반환
void doHire(Database& inDB); //Database의 reference 인자로 가지는 inDB
//함수 호출시 넣어준 값(Database 타임임)을 inDB 주소값에 복사해서 넣어라 
//(변수앞에 &가 붙으면 그 주소값에 값을 복사해서 넣으라는 소리) 
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int main()
{
	Database employeDB; //Database 객체 필요하므로 하나 선언 
	bool done = false;

	while (!done)
	{
		int selection = displayMenu();

		switch (selection)
		{
		case 1:
			doHire(employeDB);
			break;
		case 2:
			doFire(employeDB);
			break;
		case 3:
			doPromote(employeDB);
			break;
		case 4: 
			doDemote(employeDB);
			break;
		case 5:
			employeDB.displayAll();
			break;
		case 6:
			employeDB.displayCurrent();
			break;
		case 7: 
			employeDB.displayFormer();
			break;
		case 0:
			done = true;
			break;
		default:
			cerr << "Unknown command." << endl;

		}
	}
	return 0;
}


//함수 구현
int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Employee Database" << endl;
	cout << "-----------------" << endl;
	cout << "1) Hire a new employee" << endl;
	cout << "2) Fire an employee" << endl;
	cout << "3) Promote an employee" << endl;
	cout << "4) Demote an employee" << endl;
	cout << "5) List all employees" << endl;
	cout << "6) List all current employees" << endl;
	cout << "7) List all previous employees" << endl;
	cout << "0) Quit" << endl;
	cout << endl;
	cout << "--->";
	cin >> selection; //selection 값 입력 
	return selection;

}

void doHire(Database& inDB) 
{
	string firstName;
	string lastName;

	cout << "First name? ";
	cin >> firstName;
	cout << "Last name? ";
	cin >> lastName;

	//<예외처리>

	//inDB에 종업원을 추가하기위한 시도
	try
	{
		inDB.addEmployee(firstName, lastName);
	}
	catch (const std::exception&)
	{
		cerr << "Unable to add new employee!" << endl;
	}
}
void doFire(Database& inDB) 
{
	int employeeNumber;
	cout << "Employee number? ";
	cin >> employeeNumber;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.fire();
		cout << "Employee " << employeeNumber << "terminated." << endl;
	}
	catch (const std::exception&)
	{
		cerr << "Unable to terminate employee!" << endl;
	}
}
void doPromote(Database& inDB)
{
	int employeeNumber;
	int raiseAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a raise? ";
	cin >> raiseAmount;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.promote(raiseAmount);
	}
	catch (std::exception&)
	{
		cerr << "Unable to promote employee!" << endl;

	}
}
void doDemote(Database& inDB)
{
	int employeeNumber;
	int downAmount;
	cout << "Employee number? ";
	cin >> employeeNumber;
	cout << "How much of a down? ";
	cin >> downAmount;

	try
	{
		Employee& emp = inDB.getEmployee(employeeNumber);
		emp.demote(downAmount);
	}
	catch (std::exception&)
	{
		cerr << "Unable to demote employee!" << endl;

	}
}