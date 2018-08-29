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
		Employee theEmployee; //추가할 종업원 객체 선언 
		theEmployee.setFirstName(inFirstName);
		theEmployee.setLastName(inLastName);
		theEmployee.setEmployeeNumber(mNextEmployeeNumber++); //1000 에서 한명 추가될때마다 번호 1씩 추가
		theEmployee.hire();

		mEmployees.push_back(theEmployee); 
		//벡터 맨 뒤에 데이터 추가해줌
		//헤더파일에서 벡터가 Employee타입의 mEmployees벡터였는데 theEmployee도 Employee타입이므로 같은 타입이 된다 
		//그렇기 때문에 mEmployees라는 벡터에 정상적으로 추가된다
		
		return mEmployees[mEmployees.size() - 1]; 
		//아까 추가했던 종업원의 객체가 반환됨 
		//

	}


	Employee& Database::getEmployee(int inEmployNumber)
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin은 벡터의 첫번째 인덱스, end는 벡터의 마지막 다음 인덱스 => 벡터 전체 반복함 
		{
			if (iter->getEmployeeNumber() == inEmployNumber)
				return *iter;
			//iter은 기본적으로 포인터임, 포인터는 앞에*를 붙여주면 그 포인터가 가리키던 값을 반환해줌 
		}
		cerr << "No employee with number " << inEmployNumber << endl;
		throw exception();

	}

	Employee& Database::getEmployee(std::string inFirstName, std::string inLastName)
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin은 벡터의 첫번째 인덱스, end는 벡터의 마지막 다음 인덱스 => 벡터 전체 반복함 
		{
			if (iter->getFirstName() == inFirstName && iter->getLastName() == inLastName)
				return *iter;
			//iter은 기본적으로 포인터임, 포인터는 앞에*를 붙여주면 그 포인터가 가리키던 값을 반환해줌 
		}
		cerr << "No employee with first name " << inFirstName << ", last name " << endl;
		throw exception();
	}

	void Database::displayAll() const 
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin은 벡터의 첫번째 인덱스, end는 벡터의 마지막 다음 인덱스 => 벡터 전체 반복함 
		{
			iter->display();
		}
	}
	void Database::displayCurrent() const
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin은 벡터의 첫번째 인덱스, end는 벡터의 마지막 다음 인덱스 => 벡터 전체 반복함 
		{
			if(iter->getIsHired())
			iter->display();
		}
	}
	void Database::displayFormer() const
	{
		for (auto iter = mEmployees.begin(); iter != mEmployees.end(); ++iter) //begin은 벡터의 첫번째 인덱스, end는 벡터의 마지막 다음 인덱스 => 벡터 전체 반복함 
		{
			if(!(iter->getIsHired()))
			iter->display();
		}
	}


}