//Logan Reed
//2017-02-28
//CS253 HW4

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cstring>
#include <stdlib.h>
using namespace std;

void duplicated(multiset<string> &arguments, char *argv[])
{
	for(auto val: arguments)
	{
		if(arguments.count(val) > 1)
		{
			cerr << argv[0] << ": Duplicate property asked for. Exiting program" << "\n";
			exit(1);
		}
	}
}
bool isValidOption(set<string> &options, string &option)
{
	if (options.count(option) > 0)
	{
		return true;
	}
	return false;
}
void isValidPropertyFile(string &hexdigits, size_t &position)
{
	if(position == 0)
	{
		cerr << "Not correct format for a property file" << "\n";
	}
	if((hexdigits.length() < 4) || (hexdigits.length() > 6))
	{
		cerr << "Not correct format for a properties file." << "\n";
		exit(1);
	}
}
void isValidByte234(char &d)
{
	if((d & 0xc0) != 0x80)
	{
		cerr << hex << (int)d << " is not a valid bit." << "\n";
		exit(1);
	}
}

int main(int argc, char *argv[])
{
	const char *a = "-all";
	int index = 1;
	string line;
	string prop;
	set<string> alloptions;
	vector<string> wantedoptions;
	multiset<string> arguments;
	multiset<string> properties;
	vector<string> propvals;
	vector<string> hexvals;
	vector<int> inthexvals;
	string hexdigits;
	set<string> zeroproperties;		// A set containing all the properties with 0 occurances
	if(argc == 1)
	{
		cerr << argv[0] << ": No arguments!" << '\n';
		exit(1);
	}
	while((argv[index])[0] == '-')			
	{
		string myCppString = argv[index]+1;
		wantedoptions.push_back(myCppString);
		arguments.insert(myCppString);
		index++;
		if(index == argc)
		{
			cerr << argv[0] << ": No properties file given!" << "\n";
			exit(1);
		}
	}

	duplicated(arguments, argv);
	ifstream in(argv[index]);
	if(!in)
	{
		cerr << argv[0] << ": Can't open " << argv[index] << "\n"; 					//Checks if can read property file
		exit(1);
	}
	
	while(getline(in, line))
	{
		string delimeter = ";";
		size_t position = line.find(delimeter);
		hexdigits = line.substr(0, position);
		isValidPropertyFile(hexdigits, position);
		line.erase(0, position + delimeter.length());
		size_t secondposition = line.find(delimeter);
		line.erase(0, secondposition + delimeter.length());
		size_t thirdposition = line.find(delimeter);
		prop = line.substr(0, thirdposition);
		alloptions.insert(prop);
		int decval = stoi(hexdigits, nullptr, 16);	
		if(strcmp(argv[1], a) == 0)
		{
			inthexvals.push_back(decval);
			propvals.push_back(prop);
			hexvals.push_back(hexdigits);
		}
		else
		{
			for(size_t i = 0; i < wantedoptions.size(); i++)
			{
				if(wantedoptions[i] == prop)
				{
					hexvals.push_back(hexdigits);
					propvals.push_back(prop);
					inthexvals.push_back(decval);
				}
			}
		}
	}
	in.close();
	if(index + 1 == argc)
	{
		cerr << argv[0] << ": No files given to scan." << '\n';
		exit(1);
	}
	if(strcmp(argv[1], a) != 0)
	{
		for(size_t i = 0; i < wantedoptions.size(); i++)
		{
			if(isValidOption(alloptions, wantedoptions[i]) == false)
			{
				cerr << argv[0] << ": " << wantedoptions[i] << " is not a valid option." << '\n';
				exit(1);
			}
		}
	}
	for(int filenum = index + 1; filenum < argc; filenum++)	//The rest of the args should be files to scan
	{
		
		ifstream scan(argv[filenum]);
		if(!scan)
		{
			cerr << argv[0] << ": can't read " << argv[filenum] << '\n';
			exit(1);
		}
		char c;
        char d;
		char e;
		char f;
		while(scan.get(c))
		{
			
            int charval = (int)c;
  
			if((charval >= 0x0000) && (charval <= 0x007F))
			{
																			//Char in lowest range
				int ic = c;
				for(size_t i = 0; i < inthexvals.size(); i++)
				{
					if(inthexvals[i] == ic)									//If this is a character with a property we want to count
					{			
						properties.insert(propvals[i]);	//Add the corresponding property to our list 
					}														// of counted properties	
				}
			}
			else if((c & 0xE0) == 0xc0)
			{
                int firstfive = (charval & 0b00011111);
                scan.get(d);
				isValidByte234(d);
				int secondcharval = (int)d;
				int secondsix = (secondcharval & 0b00111111);
                firstfive = firstfive << 6;
                int finalone = (firstfive | secondsix);
				for(size_t i = 0; i < inthexvals.size(); i++)
				{
					if(inthexvals[i] == finalone)		//If this is a character with a property we want to count
					{			
						properties.insert(propvals[i]);	//Add the corresponding property to our list 
					}														// of counted properties	
				}


			}
				
			else if((c & 0xF0) == 0xe0)
			{
				int firstfour2 = (charval & 0b00001111);
				scan.get(d);
				isValidByte234(d);
				int secondcharval2 = (int)d;
				int secondsix2 = (secondcharval2 & 0b00111111);
				scan.get(e);
				isValidByte234(e);
				int thirdcharval = (int)e;
				int thirdsix = (thirdcharval & 0b00111111);
				firstfour2 = firstfour2 << 12;
                secondsix2 = secondsix2 << 6;
				int finalone2 = (firstfour2 | secondsix2 | thirdsix);
                for(size_t i = 0; i < inthexvals.size(); i++)
				{
					if(inthexvals[i] == finalone2)		//If this is a character with a property we want to count
					{			
						properties.insert(propvals[i]);	//Add the corresponding property to our list 
					}														// of counted properties	
				}
			}
				
            else if((c & 0xF8) == 0xf0)
			{
																		//In fourth range!
                int firstthree = (charval & 0b00000111);
                scan.get(d);
				isValidByte234(d);
                int secondcharval3 = (int)d;
                int secondsix3 = (secondcharval3 & 0b00111111);
                scan.get(e);
				isValidByte234(e);
                int thirdcharval2 = (int)e;
                int thirdsix2 = (thirdcharval2 & 0b00111111);
                scan.get(f);
				isValidByte234(f);
                int fourthcharval = (int)f;
                int fourthsix = (fourthcharval & 0b00111111);
                firstthree = firstthree << 18;
                secondsix3 = secondsix3 << 12;
                thirdsix2 = thirdsix2 << 6;
                int finalone3 = (firstthree | secondsix3 | thirdsix2 | fourthsix);
				char p = finalone3;
                for(size_t i = 0; i < inthexvals.size(); i++)
				{
					if(inthexvals[i] == finalone3)		//If this is a character with a property we want to count
					{			
						properties.insert(propvals[i]);	//Add the corresponding property to our list 
					}														// of counted properties	
				}
				

                
            }
			else
			{
				cerr << (hex) << showbase <<(int)c << " is an invalid byte." << "\n";						//If byte doesn't fall in range of any of these values
				exit(1);																// then it's invalid
			}
		}
	}
		if(strcmp(argv[1], a) == 0)													// To print all options if that is asked for
		{
			for(auto val: alloptions)
			{
				cout << val << ": " << properties.count(val) << '\n';
			}
			return 0;
		}
	for(auto val : properties)
	{
		if(strcmp(argv[1], a) != 0)							//If not want all properties
		{
			for(size_t i = 0; i < wantedoptions.size(); i++)  		//Loop through wanted options
			{
				if(val == wantedoptions[i])							//If the property 
				{
					wantedoptions.erase(wantedoptions.begin() + i);
				}
			}
		}
		
		
		if(properties.count(val) > 0)
		{
			cout << val << ": " << properties.count(val) << '\n';
		}
		properties.erase(val);
	}
	for(size_t i = 0; i < wantedoptions.size(); i++)
	{
		if(!wantedoptions[i].empty())
		{
			zeroproperties.insert(wantedoptions[i]);
		}
	}
	for(auto val : zeroproperties)
	{
		cout << val << ": 0" << '\n';
	}
		

	

	return 0;
}
