#include <string>
#include<math.h>
// Some horrible hash functions

class Hasher {
  public:
    unsigned operator()(int n) {
	return n % 8;
    }

    unsigned operator()(const std::string &s) {
	unsigned sum = 42;
	for (char c : s)
	    sum += c;
	return sum;
    }
    unsigned operator()(double &s) {
 	return fmod(s, 500.1) + 3.12;
    }
};

