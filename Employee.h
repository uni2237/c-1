//Employee.h
#include <string> //���ڿ� ����ϱ� ���ؼ� ���ڿ� ������� �߰� 

namespace Records //{}�� �ѷ����� �κ��� namespace�ȿ� ���ϵ��� �� 
{
	const int KDefaultStartingSalary = 30000; //���Ի���� ù �޿�

	class Employee
	{
	public:
		Employee();
		void promote(int inRaiseAmount = 1000);
		void demote(int inDemeritAmount = 1000);
		void hire();
		void fire();
		void display() const; //ȭ�鿡 ǥ�õɶ� � ���� ������ ��찡 �����Ƿ� constant �޼ҵ�� ��

		void setFirstName(std::string inFirstName);
		std::string getFirstName() const;
		void setLastName(std::string inLastName);
		std::string getLastName() const;
		void setEmployeeNumber(int inEmployeeNumber);
		int getEmployeeNumber() const;
		void setSalary(int inNewSalary);
		int getSalary() const;
		bool getIsHired() const;



	protected: //�ڽ� Ŭ������ ��� �Լ��κ����� ���ٸ� ���
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool bHired;
	};
}