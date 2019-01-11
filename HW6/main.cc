#include "U.h"
#include "P.h"
#include <iostream>
using namespace std;
const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells
int main() {
    try {
        U u;
        u.append("a³+b³≠c³");
		P p(pub+"UnicodeData.txt");
        for (int i=0; i<u.size(); i++)
		{
			p.count(u.codepoint(i));
		}
		cout << "Should be 8: " << u.size() << '\n'
        	 << "Should be 2: " << p.count("Sm") << '\n'
        	 << "Should be b³: " << u.get(3,5) << '\n';
        try {
        	u.readfile("/bogus");
            }
        catch (const string &msg) {
        	cout << "I expected this: " << msg << '\n';
        }
		//P p7;
		//p7.count(1212);
		cout << "Cow codepoint should be 179: " << u.codepoint(7) << '\n';
		cout << "Should be 8: " << u.size() << '\n'
         << "Should be 2: " << p.count("Sm") << '\n'
         << "Should be all: " << u.get() << '\n'
		 << "Should be b: " << u.get(3) << '\n';
		 cout << "Should be 179: " << u.codepoint(7) << '\n';
		 cout << "Should be 0: " << p.count("<*>") << '\n';
        try {
        	u.readfile("/bogus");
        }
        catch (const string &msg) {
        	cout << "I expected this: " << msg << '\n';
        }
		U u2;
		P p9(pub+"UnicodeData.txt");
		const string s = "/s/bach/c/under/lvreed/CS253/HW6/data3";
		u2.readfile("/s/bach/a/class/cs253/pub/hamlet.txt");
		for(int i = 0; i < u2.size(); i++)
		{
			p9.count(u2.codepoint(i));
		}
		cout << "Should be 48: " << p9.count("Sm") << "\n";
		cout << "Should be 0: " << p9.count("Sc") << p9.count("Co") << "\n";
		cout << "Should be 7418: " << p9.count("Po") << "\n";

		cout << u2.size() << '\n';
		/*P p2(pub+"UnicodeData.txt");
		const P p3(pub+"UnicodeData.txt");
		cout << "possible to call size on const object? " << p3.size() << '\n';
		p2.count(194669);
		cout << "P2 SO should be 1: " << p2.count("Lo") << p2.count("So") << '\n';
		const U u5 = u;
		cout << "U5 Should be all: " << u5.get() << '\n';
		cout << "Empty?" << p3.size() << boolalpha << p3.empty() << '\n';
		p2.count(19914);
		p2.count(19914);
		p2.count(19914);
		p2.count(43671);
		p2.count(55229);
		cout << "P2 Testing count, should be 3: " << p2.count("So") << '\n';
		cout << "P2 Testing count, should be 2: " << p2.count("Lo") << '\n';
		cout << "Testing u size, should be 9: " << u2.size() << '\n';
		
		cout << "Is u empty? " << boolalpha << u.empty() << '\n';
		cout << "Is p empty? " << boolalpha << p.empty() << '\n';
		p.clear();
		cout << "Is p empty AFTER CLEAR? " << boolalpha << p.empty() << '\n';
		u.clear();
		p.readfile(pub+"UnicodeData.txt");
		set<string> propss = p2.props();
		cout << "Is p empty AFTER CLEAR & READFILE? " << boolalpha << p.empty() << '\n';
		cout << "Is u empty AFTER CLEAR? " << boolalpha << u.empty() << '\n';
		U u4;
		cout << "Is u4 Empty? " << boolalpha << u4.empty() << " " << u4.size() << '\n';
		*/
		return 0;
    }
		
    catch (const string &msg) {
        cout << "Unexpected error: " << msg << '\n';
        }
    }
