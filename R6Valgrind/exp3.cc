#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {    
    int x = 0;

    if (argc > 666)		// unlikely to occur
	x = 42;			// but the compiler is too dumb to know that
    
    if (x==0)
        cout << "x is zero\n";
    return 0;
}
