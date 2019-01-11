#include <iostream>
#include <string>
using namespace std;


int main() {
    string myString;
    getline(cin, myString);
    //cout << hex << uppercase << (int)myString.at(0);
    for(int i = 0; i < myString.length(); i++)
    {
        //if(hex << uppercase <<  (int)myString.at(i) )
        cout <<"Index: " << i << "Hex Value: " << hex << uppercase <<(int)myString.at(i) << endl;
    }
/*char mychar = ';';
    cout << hex << uppercase << (int)mychar << endl;
    return 0;
*/
}
