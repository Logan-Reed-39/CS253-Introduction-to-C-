//Logan Reed
//2017-02-21
//CS253 HW3
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
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
bool isValid(set<string> &options, string &option)
{
	if (options.count(option) > 0)
	{
		return true;
	}
	return false;
}

int main(int argc, char *argv[]) {
    if(argc == 1)
    {
        cerr << "No arguments given!" << "\n";
        exit(1);
    }
	vector<string> wantedoptions;			//This stores the options entered by the user into a vector of strings
	vector<int> hexvals;
	string line;
	const char *a = "-all";
	vector<string> propvals;
	set<string> alloptions;
	int index = 1;
	vector<int> count;
	multiset<string> properties;			//List of counted properties
	set<string> zeroproperties;				// A set containing all the properties with 0 occurances
	multiset<string> arguments;
	
	
	while((argv[index])[0] == '-')			
	{
		string myCppString = argv[index]+1;
		wantedoptions.push_back(myCppString);
		index++;
		arguments.insert(myCppString);
	}
	duplicated(arguments, argv);

	if(argv[index][0] != '/')
	{
		cerr << "No properties file detected\n";
		exit(1);
	}
	
	ifstream in(argv[index]);
	if(!in)
	{
		cerr << "Can't open " << argv[index] << "\n";
		exit(1);
	}
	while(getline(in, line))
	{
		string oneline;
		oneline +=line.at(3);
		oneline +=line.at(4);								//Oneline is the Property in the file
		string hexval;
		hexval +=line.at(0);
		hexval +=line.at(1);								//Hexval is the hexval for the oneline property 
		int decval = stoi(hexval, nullptr, 16);				//Hexval is converted to an int
		alloptions.insert(oneline);							// To check for valid arguments 
		if(strcmp(argv[1], a) == 0)							//If want all properties
		{
			hexvals.push_back(decval);						//Add the decimal value to the hexvals vector
			propvals.push_back(oneline);					//Add the property to the properties 
		}
		else
		{
			for(size_t j = 0; j < wantedoptions.size(); j++)
			{
				if(wantedoptions.at(j) == oneline)				//If the property is one the user entered
				{
				hexvals.push_back(decval);
				propvals.push_back(oneline);
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
			if(isValid(alloptions, wantedoptions[i]) == false)
			{
				cerr << argv[0] << ": " << wantedoptions[i] << " is not a valid option." << '\n';
				exit(1);
			}
		}
	}

	for(int filenum = index + 1; filenum < argc; filenum++)		//The rest of the args should be files to scan
	{
		
		ifstream scan(argv[filenum]);
		if(!scan)
		{
			cerr << argv[0] << ": can't read " << argv[filenum] << '\n';
			exit(1);
		}
		char c;													//Convert the character in question to an int
		while(scan.get(c))
		{
			unsigned int id = c;
			int ic = c;
			if((ic < 0 )|| (ic > 127))
			{
				cerr << argv[filenum] << " contains the character " << hex << id << " that is out of range." << '\n';
				exit(1);
			}
																	
			for(size_t i = 0; i < hexvals.size(); i++)
			{
				if(hexvals[i] == ic)											//If this is a character with a property we want to count
				{												
					properties.insert(propvals[i]);								//Add the corresponding property to our list 
																				// of counted properties
				}
			}
		}
		scan.close();

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
