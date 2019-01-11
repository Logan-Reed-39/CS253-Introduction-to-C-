    #include "U.h"
    #include "P.h"
    #include <iostream>
    #include <cassert>
    using namespace std;
    const string pub="/s/bach/a/class/cs253/pub/";   // ~ only works in shells

    int main() {
        /*U u;
		u.append("a³+b³≠c³");
		string s = "Smiley Face?";
		string t = "Logan Reed";
		u += " \u263a";				// happy face (lowercase u)
		u += s;
		cout << "U: " << u.get() << endl;
		U u2;
		u2 += u;
		cout << "U2: " << u2.get() << endl;
		U u3;
		u3 = u + string("Logan");
		cout << "U3: " << u3.get() << endl;
		U u4;
		u4 = s + u3;
		cout << "U4 Get: " << u4.get() << "\n";
		cout << "U4: " << u4 << "\n";
		U u6;
		u6 = s;
		cout << "U6: " << u6 << "\n";
		assert(u6 == u6);
		u6 = u6;
		cout << "U6 after equals: " << u6 << "\n";
		
		assert(u == u2);
		U u5;
		u5 = t;
		assert(u5 == t);
		//assert(u5 == s);
		assert(u4 != u5);
		cout << "U5: " << u5 << "\n";
		try{
		cout << "U5 at 0: " << u5[0] << '\n';
		}
		catch(string &s)
		{
			cout << s << endl;
		}
		assert(s != u5);
		*/
		P p(pub+"UnicodeData.txt");
		U u7("/s/bach/a/class/cs253/pub/hamlet.txt");
		assert(u7);
		for (int i=0; i<u7.size(); i++)
		{
			p.count(u7.codepoint(i));
		}
		cout << u7 << "\n";
		cout << "Printing p: "<< p << "\n";
		//assert(u);
		//assert(u5);
		//const U u8 = u;
		//cout << "U8: " << u8 << "\n";
		
		//cout << "U: " << u7 << "\n";
		//cout << "P: " << p << "\n";
		/*
        U u;
        assert(!u);
        u = "a";
        u += " \u263a";				// happy face (lowercase u)
        {
            U u2;
            const string space = " ";
            u2 += space;
            u2.append("\U0001f42e");		// cow face (uppercase U)
            u += u2;
        }
        const U u3 = u;
        assert(u3);
        assert(u3.size() == 5);
        assert(u3[0] == "a");			// Let’s start easy.
        assert(u3.codepoint(2) == 0x263a);	// happy face is U+263a
        assert(u3.codepoint(4) == 0x1f42e);	// cow is U+1f42e
        assert(u3 == u);
        assert(u3 == "a \u263a \U0001f42e");
        assert("a \u263a \U0001f42e" == u3);
        assert("☮☮☮" != u3);			// Cows are peaceful, but …
        cout << "A happy cow: " << u3 << endl;  // a ☺ 🐮	
        					// (If your terminal manages it)
        P p;
        assert(!p);
        p.readfile(pub+"UnicodeData.txt");
        assert(p);
        for (int i=0; i<u3.size(); i++)
            p.count(u3.codepoint(i));
        assert(p.count("Ll")==1);
        assert(p.count("So")==2);
        assert(p.size() == 29);
        cout << "There are " << p.size() << " distinct properties.\n";
		*/
    }