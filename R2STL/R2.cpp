#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <fstream>

using namespace std;
  

int main(){

    vector<int> in;
    int n;
    cin >> n;
    while(n != 0)
    {
        in.push_back(n);
        cin >> n;
    }
    cout << "Entered 0 so done." << "\n";
    for(auto val : in)
    {
        cout << val << '\n';
    }
    ifstream in2("/etc/resolv.conf");
    string temp;
    char c;
    while(in2.get(c))
    {
        temp = temp + c;
    }
    cout << "String: "<<  temp;
    multiset<char> ms;
    for(unsigned int i = 0; i < temp.size(); i++)
    {
        ms.insert(temp.at(i));
    }
    for(auto val : ms)
    {
        cout << val;
    }
    set<char> s;
    for(unsigned int i = 0; i < ms.size(); i++)
    {
        s.insert(ms.at(i));
    }
    
    

        
    
    return 0;
}
