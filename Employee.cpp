#include <iostream> 
#include "Employee.h" //Employee 헤더파일 추가 

using namespace std;

namespace Records
{
	Employee::Employee()
		:mFirstName(""), mLastName(""), mEmployeeNumber(-1),mSalary(KDefaultStartingSalary),bHired(false)
	{} //멤버 이니셜라이징 한것임

	void Employee::promote(int inRaiseAmount)
	{
		setSalary(getSalary() + inRaiseAmount);
	}
	void Employee::demote(int inDemeritAmount)
	{
		setSalary(getSalary() - inDemeritAmount);
	}
	void Employee::hire()
	{
		bHired = true;
	}
	void Employee::fire()
	{
		bHired = false;

	}
	void Employee::display() const
	{
		cout << "Employee: " << getLastName() << getFirstName() << endl;
		cout << "--------------------------------" << endl;
		cout << (bHired ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number: " << getEmployeeNumber() << endl;
		cout << "Salary: $" << getSalary() << endl;
		cout << endl;

	}

	void Employee::setFirstName(string inFirstName)
	{
		mFirstName = inFirstName;
	}

	string Employee::getFirstName() const
	{
		return mFirstName;
	}
	void Employee::setLastName(string inLastName)
	{
		mLastName = inLastName;
	}

	string Employee::getLastName() const
	{
		return mLastName;
	}

	void Employee::setEmployeeNumber(int inEmployeeNumber)
	{
		mEmployeeNumber = inEmployeeNumber;
	}

	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int inNewSalary)
	{
		mSalary = inNewSalary;
	}

	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::getIsHired() const
	{
		return bHired;
	}
	/*void promote(int inRaiseAmount = 1000);
		void demote(int inDemeritAmount = 1000);
		void hire();
		void fire();
		void display() const; //화면에 표시될땐 어떤 값이 수정될 경우가 없으므로 constant 메소드로 함

		void setFirstName(std::string inFirstName);
		std::string getFirstName() const;
		void setLastName(std::string inLastName);
		std::string getLastName() const;
		void setEmployeeNumber(int inEmployeeNumber);
		int getEmployeeNumber() const;
		void setSalary(int inNewSalary);
		int getSalary() const;
		bool getIsHired() const;
		
		protected: //자식 클래스의 멤버 함수로부터의 접근만 허용
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber;
		int mSalary;
		bool bHired;*/
}
