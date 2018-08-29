#include<iostream>
#include <vector>
#include "Employee.h"

namespace Records
{
	const int kFirstEmployeeNumber = 1000;
	//첫번째 종업원의 시작 번호 = 1000


	class Database
	{
	public:
		Database();
		~Database();
		//종업원 추가 
		Employee& addEmployee(std::string inFirstName, std::string inLastName); //종업원을 추가하기 위한 함수 
		//c++은 std::string 으로 문자열 표현 

		//종업원 식별을 번호나 성,이름으로 할 예정
		//Employee 함수임  
		Employee& getEmployee(int inEmployeeNumber);
		Employee& getEmployee(std::string inFirstName, std::string inLastName);


		void displayAll() const; //전체 종업원 열람
		void displayCurrent() const; //현재 종업원 열람 
		void displayFormer() const; //과거 종업원 열람 

	protected:
		std::vector<Employee> mEmployees;
		int mNextEmployeeNumber;
	};
}