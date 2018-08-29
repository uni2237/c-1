//Employee.h
#include <string> //문자열 사용하기 위해서 문자열 헤더파일 추가 

namespace Records //{}로 둘러싸인 부분이 namespace안에 속하도록 함 
{
	const int KDefaultStartingSalary = 30000; //신입사원의 첫 급여

	class Employee
	{
	public:
		Employee();
		void promote(int inRaiseAmount = 1000);
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
		bool bHired;
	};
}