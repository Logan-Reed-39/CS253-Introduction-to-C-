//Logan Reed
//2017-01-28
//CS253 HW1

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
		int lettercount = 0;
		int punctcount = 0;
		int numcontrol = 0;
		int numspaces = 0;
		int numsymbols = 0;
		int numnum = 0;
		char c;
		while(cin.get(c))
		{
			if(c <= 31 || c == 127)
			{
				numcontrol++;
			}
			else if(c == ' ')
			{
				numspaces++;
			}
			else if((c >= '!' && c <= '#')
				|| (c == ':') || (c == ';'))
			{
				punctcount++;
			}
		
			else if((c == '$') || (c == '+') ||
			(c >= '<' && c <= '>'))
			{
				numsymbols++;
			}
			else if((c >= '%' && c <= '*')
			|| (c >= ',' && c <= '/'))
			{
				punctcount++;
			}
			else if(c >= '0' && c <= '9')
			{
				numnum++;
			}
			else if((c == '?') || (c == '@') ||
			(c >= '[' && c <= ']') ||
			(c == '_'))
			{
				punctcount++;
			}
			else if((c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z'))
			{
				lettercount++;
			}

			else if(c == '^' || (c == '`') ||
			c == '|' || c == '~')
			{
				numsymbols++;
        
			}
			else if(c == '{' || c == '}')
			{
				punctcount++;
			}
		}
	cout << "Control: " << numcontrol << "\n";
    cout << "Letter: " << lettercount << "\n";
    cout << "Number: " << numnum << "\n";
    cout << "Punctuation: " << punctcount << "\n";
    cout << "Symbol: " << numsymbols << "\n";
    cout << "Space: " << numspaces << "\n";
		

    return 0;
}
