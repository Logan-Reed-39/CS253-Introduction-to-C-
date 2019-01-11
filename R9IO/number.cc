#include <iostream>
#include <sstream>
using namespace std;

class Number {
  public:
    Number() : value(0) {}
    Number(int v) : value(v) {}
    Number &operator=(int n) { value = n; return *this; }
    operator int() const { return value; }
  private:
    int value;
    
    
};

istream &operator>>(istream &is, Number &rhs) {
    int n;
    std::string s;
    if(is >> n)
    {
        rhs = n;
        return is;
    }
    is.clear();
    if(is >> s)
    {
        //is >> s;
        if(s == "one")
        {
            rhs = 1;
            //is >> n;
        }
        if(s == "two")
        {
            rhs = 2;
            //is >> n;
        }
        if(s == "three")
        {
            rhs = 3;
            //is >> n;
        }
        else if(s == "four")
        {
            rhs = 4;
            //is >> n;
        }
        else if(s == "five")
        {
            rhs = 5;
            //is >> n;
        }
    }
    //rhs = n;
    return is;
}


int main() {
    Number n = 666;
    istringstream ss("12 34 three 789 five");

    while (ss >> n)
	cout << n << ' ';
    cout << '\n';
}
