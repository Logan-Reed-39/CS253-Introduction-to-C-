//Logan Reed
//2017-04-05
//CS253 HW6

#include "P.h"
#include<sstream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;


P::P(){
}
P::P(const P &rhs) :
	propsset(rhs.propsset),
	properties(rhs.properties),
	propertyvalues(rhs.propertyvalues),
	count1(rhs.count1),
	counting(rhs.counting)
	{}
P::P(const std::string filename)
{
	readfile(filename);
}
P &P::operator=(const P &rhs)
{
	propsset = rhs.propsset;
	properties = rhs.properties;
	propertyvalues= rhs.propertyvalues;
	count1 = rhs.count1;
	counting = rhs.counting;
	return *this;
}
P::~P()
{}
void P::readfile(const string propfile)
{
	if(!propsset.empty())
	{
		throw string("Already called propfile for another properties file");
	}
	ifstream in(propfile);
	if(!in)
	{
        ostringstream oss;
		oss << "can’t open " << propfile << ": " << strerror(errno);
		throw oss.str();
	}
	string line;
    int i = 0;
	while(getline(in, line))
	{
		string delimeter = ";";
		size_t position = line.find(delimeter);
		string hexdigits = line.substr(0, position);
		line.erase(0, position + delimeter.length());
		size_t secondposition = line.find(delimeter);
		line.erase(0, secondposition + delimeter.length());
		size_t thirdposition = line.find(delimeter);
		string prop = line.substr(0, thirdposition);
		int decval = stoi(hexdigits, nullptr, 16);					//decimal value of hex
        i++;
        propsset.insert(prop);
		properties.push_back(prop);									//holds property string
		propertyvalues.push_back(decval);							//holds property decimal value
		

	}
}
set<string> P::props()const
{
	return propsset;
}
void P::count(int codepoint)
{
	if(propsset.empty())
	{
		throw string("Readfile hasn't been called yet!");
	}
	counting.insert(codepoint);
}
int P::count(string property)
{
	int decval = 0;
	for(size_t i = 0; i < properties.size(); i++)
	{
		if(properties.at(i) == property)
		decval += counting.count(propertyvalues.at(i));
	}
	return decval;
}
int P::size()const
{
	return propsset.size();
}
bool P::empty() const 
{
	return propsset.empty();
}
void P::clear()
{
	propsset.clear();
	properties.clear();
	propertyvalues.clear();
	count1.clear();
	counting.clear();
}
