#include <iostream>
#include <string>
#include <tuple>
#include <array>
#include <map>
#include <vector>
#include <utility>
#include <typeindex>	// allows to add a template specialization for user-definded object
// If you got a 

typedef struct ToBind;

namespace MySpace
{
	enum MyClassValue { DEFOULT, SET_ON, SET_OFF, WAITING, OUT_OF_RANGE, OTHER_ERROR };

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
		MyClass_B(int MyB_XVal = 10, int MyB_YVal = 10, std::string myString = "Default")
			: BxVal(MyB_XVal), ByVal(MyB_YVal), MyClassBString(myString) {
			std::cout << "Konstruktor domyslny klasy B\n";
		}
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

	class Config
	{
		std::string name = "Michal";
		std::size_t id = 0;
		std::vector<std::string> data;
	public:
		Config(std::string n, size_t New_id, std::vector<std::string> newData) :name(n), id(New_id) {
			std::cout << "Defoult constructor.\n";
			data = std::move(newData);

		}
		~Config() {};
		template<size_t N>
		decltype(auto) get() const
		{
			if		constexpr (N == 0) return strd::string_view{ name }; // we dont need to use std::move becouse we return the std::string_view with 
																		 // is only a const char * and lenght of the steing
			else if constexpr (N == 1) return id;
			else if constexpr (N == 2) return (data); // parens need to get the reference 
		}

	};
}

namespace std
{
	template<>
	struct tuple_size<MySpace::Config> :
		std::integral_constant <std::size_t, 3> {};
	// taking a type of elements passing in tuple
	template<sdt::size_t N>
	struct tuple_element<N, Config>
	{
		using type = declatype(std::declval<Config>().get<N>());
	};

	template <>
	struct tuple_size<ToBind> :
		std::integral_constant<std::size_t, 3> {};

	template<std::size_t N>
	struct tuple_elemnet<N, ToBind>
	{
		using type = declatype(std::declval<ToBind>().get<N>());
	};
}

struct ToBind
{
	int aaa = 1;
	int bbb = 2;
	float ffff = 3.3;
	template<size_t N>
	decltype(auto) get() const
	{
		if		constexpr (N == 0) return aaa;
		else if constexpr (N == 1) return bbb;
		else if constexpr (N == 2) return ffff;
	}
};

int main()
{
	MySpace::MyClass_B BB;
	MySpace::MyClass_A AA;
	std::vector<std::string> MyData = { "Data01","Data02","Data03" };
	MySpace::Config Config01("Janek", 10, MyData);
	std::cout << AA;
	std::cout << BB;
	MySpace::MyClass_A B("Ewa", MySpace::MyClassValue::WAITING);
	std::cout << B;
	Config01.get();
	auto[BName, BId, BData] = std::tuple(Config01);
	ToBind structToBind;
	//	auto[Sa,Sb,Sc] = std::tuple(structToBind);
	//	auto[TestName] = std::tuple(AA);
	//	std::cout << TestName;

	return 0;
}