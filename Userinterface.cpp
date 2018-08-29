#include <iostream>
#include <stdexcept> //����ó��
#include "Database.h"

using namespace std;
using namespace Records;



//�Լ��� ���� 

int displayMenu(); //�޴��� ���� � �޴��� ���������� �����ϸ� ���� ��ȯ
void doHire(Database& inDB); //Database�� reference ���ڷ� ������ inDB
//�Լ� ȣ��� �־��� ��(Database Ÿ����)�� inDB �ּҰ��� �����ؼ� �־�� 
//(�����տ� &�� ������ �� �ּҰ��� ���� �����ؼ� ������� �Ҹ�) 
void doFire(Database& inDB);
void doPromote(Database& inDB);
void doDemote(Database& inDB);

int main()
{
	Database employeDB; //Database ��ü �ʿ��ϹǷ� �ϳ� ���� 
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


//�Լ� ����
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
	cin >> selection; //selection �� �Է� 
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

	//<����ó��>

	//inDB�� �������� �߰��ϱ����� �õ�
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