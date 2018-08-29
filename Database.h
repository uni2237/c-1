#include<iostream>
#include <vector>
#include "Employee.h"

namespace Records
{
	const int kFirstEmployeeNumber = 1000;
	//ù��° �������� ���� ��ȣ = 1000


	class Database
	{
	public:
		Database();
		~Database();
		//������ �߰� 
		Employee& addEmployee(std::string inFirstName, std::string inLastName); //�������� �߰��ϱ� ���� �Լ� 
		//c++�� std::string ���� ���ڿ� ǥ�� 

		//������ �ĺ��� ��ȣ�� ��,�̸����� �� ����
		//Employee �Լ���  
		Employee& getEmployee(int inEmployeeNumber);
		Employee& getEmployee(std::string inFirstName, std::string inLastName);


		void displayAll() const; //��ü ������ ����
		void displayCurrent() const; //���� ������ ���� 
		void displayFormer() const; //���� ������ ���� 

	protected:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;
	};
}