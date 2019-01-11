#include <iostream>

using namespace std;

#include "foo.h"
#include "bar.h"

int main() {
    cout << "Hi from " << __func__ << " at " __FILE__ ":" << __LINE__ << '\n';
    foo();
    bar();
    return 0;
}
