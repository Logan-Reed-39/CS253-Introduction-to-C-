#include "U.h"
#include "P.h"
#include <iostream>
#include <cassert>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
int main() {
    try {
        U u;
        u.append("a³+b³≠c³");
		P p(pub+"UnicodeData.txt");
		string s("Logan Reed");
        u += s;							//Testing u+=s;
		cout << "U+=s: " << u << "\n";
		U u2("/s/bach/c/under/lvreed/CS253/HW7/data3");
		u2 = string("DOES THIS WORK?");
		cout << "U2: " << u2 << "\n";
		u2 = string("I think so!");
		cout << "U2: " << u2 << "\n";
		U u3;
		u3.append("\U0001F6BD");
		U u88;
		u88 = s + u;
		u += u3;
		cout << "U+=U: " << u << "\n";
		cout << "U[18]: " << u[18] << "\n";
		cout << "U+U: " << u2 << "\n";
		string w("MOOOORE \u263a");
		u2 = u2 + w;
		cout << "U+S: " << u2 << "\n";
		string x("\u4DCA");
		u2 = x + u2;
		cout << "S+U: " << u2 << "\n";
		U u4("/s/bach/a/class/cs253/pub/hamlet.txt");
		for (int i=0; i<u4.size(); i++)
		{
			p.count(u4.codepoint(i));
		}
		U u9;
		string t1("LLLLL");
		u9.append(t1);
		//cout << p << "\n";
		//cout << u4 << "\n";
		const U u5("/s/bach/c/under/lvreed/CS253/HW7/data3");
		const U u6("/s/bach/c/under/lvreed/CS253/HW7/data2");
		const U u8 = u6;
		U u7;
		u7 = u5 + u6;
		cout << "CONST CONCAT: " << u7 << "\n";
		//assert(!u5);
		assert(u8 == u6);
		assert(u != u2);
		assert("LLLLL" == u9);
		assert(s != u);
		assert(u != t1);
		assert(u6 != u5);
		assert(p);
		P p2(pub + "UnicodeData.txt");
		assert(p2);
		return 0;
    }
		
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
        }
    }
