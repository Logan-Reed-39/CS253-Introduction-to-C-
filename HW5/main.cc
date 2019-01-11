#include "U.h"
#include <iostream>    
#include<set>
#include<string>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
int main() {
    U foo(pub+"UnicodeData.txt", "a³+b³≠c³");
    cout << "Should be 8: " << foo.size() << '\n';
    cout << "Should be 2: " << foo.propcount("Sm") << '\n';
	try{
    cout << "Should be b³: " << foo.get(3,5) << '\n';
	}
	catch(const string &s)
	{
		cout << s << '\n';
		return 1;
	}
    U foo2 = foo;
	const U foo7 = foo2;
    cout << "Testing copy constructor, Should be 8: " << foo2.size() << '\n';
	/*try{
		cout << "Foo2 Should be ERROR: " << foo2.get(-1,2) << '\n';
		U foo4(pub+"UnicodeDat.txt", "a³+b³≠c³");
	}
	catch(const string &s)
	{
		cout << s << '\n';
		return 1;
	}
	*/
	cout << "Foo7 const test get << should be b³: " << foo.get(3,5) << '\n';
	U foo6;
	foo6 = foo2;
	cout << "Testing equals, Should be all: " << foo6.get() << '\n';
	
	/*try{
		U foo3;
		foo3.propfile("/s/bach/a/class/cs253/pub/UnicodeData.txt");
		foo3.readfile("/s/bach/a/class/cs253/pub/hamlet.txt");
		//cout << "FOO3 Should be 2 characters: "  << foo3.get(4,4) << '\n';
		cout << "Hamlet count test, should be 10412: " << foo3.propcount("Cc") << "\n";
		//cout << "Hamlet get: " << foo3.get() << "\n";
	}
	catch(const string &s)
	{
		cout << s << '\n';
		return 1;
	}
	*/
	U foo5;
	foo5.readfile("/s/bach/c/under/lvreed/CS253/HW5/testfile.txt");
	try{
		cout << "Gnarly: " << foo5.propcount("Gnarly") << "\n";
	}
	catch(const string &s)
	{
		cout << s << '\n';
		return 1;
	}
	cout << "GET WITHOUT PROPS: " << foo5.get(3,5) << "\n";
	
    U foo3;
	foo3.propfile("/s/bach/a/class/cs253/pub/UnicodeData.txt");
	/*
	try{
			foo3.propfile("/s/bach/a/class/cs253/pub/UnicodeData.txt");	
	}
	catch(const string &s)
	{
		cout << s << '\n';
		return 1;
	}
	*/
	//cout << "Should be b³: " << foo3.get() << '\n';
    foo3.props();
    set<string> propsprinted = foo3.props();
    for(auto val : propsprinted)
    {
        cout << val << '\n';
    }

    return 0;
    }
