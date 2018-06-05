#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <gsl/gsl>
using namespace std;

int& add_local(map<string, int> vars, const string &newName)
{
	//using structre binding
	if (auto[iter, succes] = vars.insert(make_pair(newName, 0)); succes == false) { throw std::runtime_error("variable alredy exist"); }
	else {

		auto[kay, value] = *iter;
		return value;
	}

}


// const ref pareameter of function is probably out
// non const ref parameter of function is porobably in/out


// when you want to use a pointer to some object and it is chance for that object in future be pointing to nullptr what is an error (it is't a compiller error but it is runtime error)
// Then you can use gls::no_null<YourClass*> pt = &YourClass; 
// i = ps->DoSomethink();
// ps = nullptr; // WRONG COMPILER ERRROR GREAT


// narrow_cast<> using when you don't mind a losing data 
// narrow checed when you cast some variable amd it changed their value narrow_cast throw an error

int main()
{
	std::map<string, int> locals;
	int &i = add_local(locals, "Just new string.\n");
	cout << i;
	return 0;
}