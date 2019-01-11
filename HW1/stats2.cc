//Logan Reed
//2017-01-28
//CS253 HW1

#include <iostream>
using namespace std;
int numletters()
{
	char d;
	int lettercount1 = 0;
	while(cin.get(d))
	{
		    if((d >= 'A' && d <= 'Z') ||
           (d >= 'a' && d <= 'z'))
        {
            lettercount1++;
        }
	}
	return lettercount1;
}
int numnumbers()
{
	char e;
	int numnum = 0;
	while(cin.get(e))
	{
		if(e >= '0' && e <= '9')
		{
			numnum++;
		}
	}
	return numnum;
}


int main() {
    int punctcount = 0;
    int numcontrol = 0;
    int numspaces = 0;
    int numsymbols = 0;

	cout << "Control: " << numcontrol << "\n";
	cout << "Letter: " << numletters() << "\n";
    cout << "Number: " << numnumbers() << "\n";
    cout << "Punctuation: " << punctcount << "\n";
    cout << "Symbol: " << numsymbols << "\n";
    cout << "Space: " << numspaces << "\n";
    /*while(cin.get(c))
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

        else if((c == '?') || (c == '@') ||
           (c >= '[' && c <= ']') ||
           (c == '_'))
        {
            punctcount++;
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
	*/



    return 0;
}
