#include "U.h"
#include <iostream>
#include <cassert>
using std::cout;
using std::hex;
using std::showbase;
using std::string;
	
    int main() {
        const char s[] = "\U0001f382 × 11 \u21d2 9\u00be";
		string p("\U0001F6BD \u038F");
		string l("Can simple letters work too?");
		const U u2(p.begin(),p.end()); 
		U u(s, s+sizeof(s)-1);
		U::iterator it2 = u2.begin();
		U::iterator it8;
		U u3(l.begin(), l.end());
		it8 = u3.begin();
		cout << "IT8 Begin: " << hex << showbase << *it8 << "\n";
		cout << "IT8 PREINC: " << hex << showbase << *++it8 << "\n";
		it8++;
		cout << "IT8 INCREMENT: " << hex << showbase << *it8 << "\n";
		it8 = u3.end();
		it8--;
		cout << "IT8 End-1: " << hex << showbase << *it8 << "\n";
		cout << "BACK: " << hex << showbase << u3.back() << "\n";
		assert(*it2 == 0x1F6BD);
		++it2;
		cout << "IT2 PREInCR: " << *it2 << "\n";
		cout << u2[0] << '\n';
		for (auto cp : u2)
            cout << hex << showbase << cp << ' ';
        cout << '\n';

		cout << "U2: " << hex << showbase << u2 << "\n";
        assert(u == "\U0001f382 × 11 \u21d2 9\u00be");
        cout << u << '\n';			// 🎂 × 11 ⇒ 9¾
        assert(u.front() == 0x1f382);		// birthday cake
        assert(u.back() == 0xbe);		// three-quarters
		U u5;
		try{
			cout << u5.back() << "\n";
		}
		catch(string &s)
		{
			cout << s << "\n";
		}
        U::iterator it = u.begin();
		U::iterator it3 = it;
		cout << "IT2 BEGIN: " << hex << showbase << *u2.begin() << "\n";
		it3++;
		cout << "BEGIN+1: " << *it3 << "\n";
		it3++;
		cout << "BEGIN+2: " << *it3 << "\n";
		it3--;		
		cout << "BEGIN + 1: " << *it3 << "\n";
		cout << "BACK: " << hex << showbase << u.back() << "\n";
		cout << "FRONT: " << hex << showbase << u.front() << "\n";
		
		assert(it2 != it);
		//assert(*it3 == 0x1f382);
        assert(*it == 0x1f382);			// birthday cake
        it++;
        assert(*it == ' ');
        it = u.end();
        --it;
        assert(*it == 0xbe);			// ¾
		--it;
		assert(*it == '9');
        for (auto cp : u)
            cout << hex << showbase << cp << ' ';
        cout << '\n';
    }
