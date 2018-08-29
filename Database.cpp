#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace Records
{
	Database::Database()
	{
		mNextEmployeeNumber = kFirstEmployeeNumber;
	}
	Database::~Database()
	{

	}

	Employee& Database::addEmployee(std::string inFirstName, std::string inLastName)
	{
		Employee theEmployee; //�߰��� ������ ��ü ���� 
		theEmployee.setFirstName(inFirstName);
		theEmployee.setLastName(inLastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++); //1000 ���� �Ѹ� �߰��ɶ����� ��ȣ 1�� �߰�
		theEmployee.hire();

		mEmployees.push_back(theEmployee); 
		//���� �� �ڿ� ������ �߰�����
		//������Ͽ��� ���Ͱ� EmployeeŸ���� mEmployees���Ϳ��µ� theEmployee�� EmployeeŸ���̹Ƿ� ���� Ÿ���� �ȴ� 
		//�׷��� ������ mEmployees��� ���Ϳ� ���������� �߰��ȴ�
		
		return mEmployees[mEmployees.size() - 1]; 
		//�Ʊ� �߰��ߴ� �������� ��ü�� ��ȯ�� 
		//

	}


	Employee& Database::getEmployee(int inEmployNumber)
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin�� ������ ù��° �ε���, end�� ������ ������ ���� �ε��� => ���� ��ü �ݺ��� 
		{
			if (iter->getEmployeeNumber() == inEmployNumber)
				return *iter;
			//iter�� �⺻������ ��������, �����ʹ� �տ�*�� �ٿ��ָ� �� �����Ͱ� ����Ű�� ���� ��ȯ���� 
		}
		cerr << "No employee with number " << inEmployNumber << endl;
		throw exception();

	}

	Employee& Database::getEmployee(std::string inFirstName, std::string inLastName)
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin�� ������ ù��° �ε���, end�� ������ ������ ���� �ε��� => ���� ��ü �ݺ��� 
		{
			if (iter->getFirstName() == inFirstName && iter->getLastName() == inLastName)
				return *iter;
			//iter�� �⺻������ ��������, �����ʹ� �տ�*�� �ٿ��ָ� �� �����Ͱ� ����Ű�� ���� ��ȯ���� 
		}
		cerr << "No employee with first name " << inFirstName << ", last name " << endl;
		throw exception();
	}

	void Database::displayAll() const 
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin�� ������ ù��° �ε���, end�� ������ ������ ���� �ε��� => ���� ��ü �ݺ��� 
		{
			iter->display();
		}
	}
	void Database::displayCurrent() const
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin�� ������ ù��° �ε���, end�� ������ ������ ���� �ε��� => ���� ��ü �ݺ��� 
		{
			if(iter->getIsHired())
			iter->display();
		}
	}
	void Database::displayFormer() const
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin�� ������ ù��° �ε���, end�� ������ ������ ���� �ε��� => ���� ��ü �ݺ��� 
		{
			if(!(iter->getIsHired()))
			iter->display();
		}
	}


}