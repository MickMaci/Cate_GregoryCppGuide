#include <iostream>
#include <optional>
#include <functional>

/*
#include "C:\Users\User\Desktop\gls\include\gsl\gsl.hpp"
#include "C:\Users\User\Desktop\gls\include\gsl\gsl_algorithm.hpp"
#include "C:\Users\User\Desktop\gls\include\gsl\gsl_assert.hpp"
*/

#include <gsl/gsl>


using namespace std;

class MyClass
{
	int a;
	std::string name;
public:
	MyClass() {};
	~MyClass() {};
	
};

// when you need to set a state of object
optional<string> MyOptional(bool is_set)
{
	if (is_set)
		return "It work";
	else
		return {};
};

// Tuple is using wehn you want to return more then one value 
//How to use tuple
std::tuple<int, int> fooTwo(int intValue)
{
	return std::make_tuple(intValue * 2, intValue * 3);
};

std::tuple<string, int > BasicInfo(string Tname, int Tyo)
{
	return std::make_tuple(Tname, Tyo);
};

int main()
{
	int i = 10;
	int *tmp = &i;
	gsl::owner<int*> own = tmp;
	cout << *own << '\n';
	cout << MyOptional(true).value_or("empty") << '\n';
	// Structuerd binding
	string name("Michal");
	int &&yo = 21;
	/*
	string CpyName;
	int CpyYo = 0;
	*/
	auto[CpyName, CpyYo] = BasicInfo(name, yo);
	cout << CpyName << '\n' << CpyYo;
	yo += 10;
	cout << CpyName << "  " << CpyYo << " and oryginal years old " << yo;
	CpyYo += 5;
	cout << '\n' << CpyYo;
	cout.flush();
}