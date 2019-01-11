//Logan Reed
//2017-01-28
//CS253 HW2

#include <iostream>
#include <fstream>
using namespace std;
void scanning(ifstream &a, int &cnt, int &let, int &num, int &punct, int &symb, int &spaces)
{
		char c;
		while(a.get(c))
		{
			if((c <= 31) || (c == 127))
			{
				cnt++;
			}
			else if(c == ' ')
			{
				spaces++;
			}
			else if((c >= '!' && c <= '#')
				|| (c == ':') || (c == ';'))
			{
				punct++;
			}
		
			else if((c == '$') || (c == '+') ||
			(c >= '<' && c <= '>'))
			{
				symb++;
			}
			else if((c >= '%' && c <= '*')
			|| (c >= ',' && c <= '/'))
			{
				punct++;
			}
			else if(c >= '0' && c <= '9')
			{
				num++;
			}
			else if((c == '?') || (c == '@') ||
			(c >= '[' && c <= ']') ||
			(c == '_'))
			{
				punct++;
			}
			else if((c >= 'A' && c <= 'Z') ||
			(c >= 'a' && c <= 'z'))
			{
				let++;
			}

			else if(c == '^' || (c == '`') ||
			c == '|' || c == '~')
			{
				symb++;
        
			}
			else if(c == '{' || c == '}')
			{
				punct++;
			}
		}
}


int main(int argc, char *argv[]) {
	int controls = 0;
	int letters = 0;
	int numbers = 0;
	int punctuations = 0;
	int symbols = 0;
	int spaces = 0;
	if(argc < 2)
	{
		cerr << "No files are given\nProgram name is: " << argv[0] << '\n';
		exit(0);
	}
	for(int i = 1; i < argc; i++)
	{
		ifstream in(argv[i]);
		if (!in) {
			cerr << "Can’t read one of the files\nProgram name is: " << argv[0] << '\n' 
				<< "File that can't be read: " << argv[i] << '\n';
			exit(0);
		}
		scanning(in, controls, letters, numbers, punctuations, symbols, spaces);
	}
	cout << "Control: " << controls << "\n";
    cout << "Letter: " << letters << "\n";
    cout << "Number: " << numbers << "\n";
    cout << "Punctuation: " << punctuations << "\n";
    cout << "Symbol: " << symbols << "\n";
    cout << "Space: " << spaces << "\n";

		
	return 0;	
}
