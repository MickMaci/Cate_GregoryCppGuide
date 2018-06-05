#include <iostream>
#include <string>
#include <tuple>
#include <array>
#include <map>

// If you got a 
namespace MySpace
{
	enum MyClassValue {DEFOULT,SET_ON,SET_OFF,WAITING,OUT_OF_RANGE,OTHER_ERROR};

	class MyClass_A
	{

	public:
		//MyClass_A(std::string name, int val ) : MyName(name), Myval(val) { std::cout << "Create MyClass" << std::endl; };
		MyClass_A(std::string name = "Adam", int val = 0) : MyName(name), Myval(val) { std::cout << "Konstruktor klasy A.\n"; };
		MyClass_A(const MyClass_A & AA) { this->MyName = std::move(AA.MyName); this->Myval = AA.Myval; }
		MyClass_A & operator=(MyClass_A & AA) { if (this->MyName == AA.MyName && this->Myval == AA.Myval) return *this; std::cout << "Operator = \n"; MyName = std::move(AA.MyName); Myval = AA.Myval; return *this; };
		~MyClass_A() {};

	private:
		std::string MyName;
		int Myval;
	public:
		friend std::ostream& operator<<(std::ostream& OstreamRef, const MyClass_A &A);
	};

	std::ostream& operator<<(std::ostream &OstreamRef, const MyClass_A &A)
	{
		OstreamRef << "Name: " << A.MyName << " Current value: " << A.Myval << '\n';
		return OstreamRef;
	}

	class MyClass_B
	{
	public:
		MyClass_B(int MyB_XVal = 10, int MyB_YVal = 10 , std::string myString = "Default")
		: BxVal(MyB_XVal), ByVal(MyB_YVal), MyClassBString(myString) { std::cout << "Konstruktor domyslny klasy B\n"; }
		~MyClass_B() {};
		
		friend std::ostream & operator <<(std::ostream &OsteramRefer, const MyClass_B &BB);

	private:
		int BxVal;
		int ByVal;
		std::string MyClassBString;
	};
	std::ostream & operator <<(std::ostream &OsteramRefer, const MyClass_B &BB)
	{
		OsteramRefer << " Wartosc X: " << BB.BxVal << " Wartosc y: " << BB.ByVal << "\n" << " MyClassBString " << BB.MyClassBString;
		return OsteramRefer;
	}
}

int main()
{
	MySpace::MyClass_B BB;
	MySpace::MyClass_A AA;
	std::cout << AA;
	std::cout << BB;
	MySpace::MyClass_A B("Ewa", MySpace::MyClassValue::WAITING);
	std::cout << B;
	auto[TestName] = std::tuple(AA);
	std::cout << TestName;
	return 0;
}