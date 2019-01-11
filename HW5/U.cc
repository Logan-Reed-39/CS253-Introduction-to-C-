//Logan Reed
//2017-03-17
//CS253 HW5

#include "U.h"
#include<fstream>
#include<string>
#include<sstream>
#include<cerrno>
#include<cstring>
using namespace std;


U::U(){
    accumdata = "";
    countersize = 0;
    getrangedvalues = "";
    getfull = "";
}
U::U(const U &rhs) :
	accumdata(rhs.accumdata),
    readfilevals(rhs.readfilevals),
    getrangedvalues(rhs.getrangedvalues),
	countersize(rhs.countersize),
	propsset(rhs.propsset),
	getfull(rhs.getfull),
	fullstrings(rhs.fullstrings),
	properties(rhs.properties),
	propertyvalues(rhs.propertyvalues),
	count1(rhs.count1)
	{}
	
U::U(const string propfilename, const string litdata)
{
	char p;
	char x;
	char y;
	char z;
	propfile(propfilename);
	int finalone;
	unsigned int i = 0;
	while(i < litdata.length())
	{
		p = litdata.at(i);
		int ip = p;
		if((ip >= 0x0000) && (ip <= 0x007F))
        {
            //Char in lowest range
            readfilevals.push_back(ip);
            i++;
			finalone = ip;
            getfull = p;
			fullstrings.push_back(getfull);                
        }
        else if((ip & 0xE0) == 0xc0)
        {
				ostringstream sst1;
                int firstfive = (p & 0b00011111);
                x = litdata.at(i+1);
				isValidByte234(x);
				int secondcharval = (int)x;
				int secondsix = (secondcharval & 0b00111111);
                firstfive = firstfive << 6;
                finalone = (firstfive | secondsix);
				readfilevals.push_back(finalone);
				i+=2;
                //make new stringstream
				sst1 << p << x;
				getfull = sst1.str();
				fullstrings.push_back(getfull);	
        }
        else if((ip & 0xF0) == 0xe0)
        {
				int firstfour2 = (ip & 0b00001111);
				x = litdata.at(i+1);
				isValidByte234(x);
				int secondcharval2 = (int)x;
				int secondsix2 = (secondcharval2 & 0b00111111);
				y = litdata.at(i+2);
				isValidByte234(y);
				int thirdcharval = (int)y;
				int thirdsix = (thirdcharval & 0b00111111);
				firstfour2 = firstfour2 << 12;
                secondsix2 = secondsix2 << 6;
				finalone = (firstfour2 | secondsix2 | thirdsix);
				readfilevals.push_back(finalone);
				i+=3;
                ostringstream sst2;
				sst2 << p << x << y;
				getfull = sst2.str();
				fullstrings.push_back(getfull);

        }
        else if((ip & 0xF8) == 0xf0)
        {
			//In fourth range!
            int firstthree = (ip & 0b00000111);
            x = litdata.at(i+1);
			isValidByte234(x);
            int secondcharval3 = (int)x;
            int secondsix3 = (secondcharval3 & 0b00111111);
            y = litdata.at(i+2);
			isValidByte234(y);
            int thirdcharval2 = (int)y;
            int thirdsix2 = (thirdcharval2 & 0b00111111);
            z = litdata.at(i+3);
			isValidByte234(z);
            int fourthcharval = (int)z;
            int fourthsix = (fourthcharval & 0b00111111);
			firstthree = firstthree << 18;
            secondsix3 = secondsix3 << 12;
            thirdsix2 = thirdsix2 << 6;
            finalone = (firstthree | secondsix3 | thirdsix2 | fourthsix);
			readfilevals.push_back(finalone);
			i+=4;
			ostringstream sst3;
			sst3 << p << x << y << z;
			getfull = sst3.str();
			fullstrings.push_back(getfull);	
		}
		else
		{
			throw string("Invalid byte in file: ")+litdata;			//If byte doesn't fall in range of any of these values														
																			// then it's invalid
		}
		for(unsigned int p = 0; p < propertyvalues.size(); p++)
		{
			if(propertyvalues[p] == finalone)
			{
				count1.at(p)++;
			}
		}

	}

	
}
U &U::operator=(const U &rhs) {
    accumdata = rhs.accumdata;
    readfilevals = rhs.readfilevals;
    getrangedvalues = rhs.getrangedvalues;
	countersize = rhs.countersize;
    propsset = rhs.propsset;
	getfull = rhs.getfull;
	fullstrings = rhs.fullstrings;
	properties = rhs.properties;
	propertyvalues = rhs.propertyvalues;
	count1 = rhs.count1;
    return *this;
}
U::~U() {
}
void U::readfile(const string filename)
{
    ifstream scan(filename);
    if(!scan)
    {
        ostringstream oss;
		oss << "can’t open " << filename << ": " << strerror(errno);
		throw oss.str();;
    }
	char c;
    while(scan.get(c))
    {
		int finalone;
        int charval = (int)c;
        if((charval >= 0x0000) && (charval <= 0x007F))
        {

            //Char in lowest range
            finalone = c;
            readfilevals.push_back(finalone);
			countersize++;
			getfull = c;
			fullstrings.push_back(getfull);  
			
        }
        else if((c & 0xE0) == 0xc0)
        {

                int firstfive = (charval & 0b00011111);
				char d;
                scan.get(d);
				isValidByte234(d);
				int secondcharval = (int)d;
				int secondsix = (secondcharval & 0b00111111);
                firstfive = firstfive << 6;
                finalone = (firstfive | secondsix);
				countersize+=2;
				readfilevals.push_back(finalone);
				ostringstream sst4;
				sst4 << c << d;
				getfull = sst4.str();
				fullstrings.push_back(getfull);
				
				
        }
        else if((c & 0xF0) == 0xe0)
        {

				int firstfour2 = (charval & 0b00001111);
				char d;
				scan.get(d);
				isValidByte234(d);
				int secondcharval2 = (int)d;
				int secondsix2 = (secondcharval2 & 0b00111111);
				char e;
				scan.get(e);
				isValidByte234(e);
				int thirdcharval = (int)e;
				int thirdsix = (thirdcharval & 0b00111111);
				firstfour2 = firstfour2 << 12;
                secondsix2 = secondsix2 << 6;
				finalone = (firstfour2 | secondsix2 | thirdsix);
				countersize+=3;
				readfilevals.push_back(finalone);
				ostringstream sst5;
				sst5 << c << d << e;
				getfull = sst5.str();
				fullstrings.push_back(getfull);
			
                
        }
        else if((c & 0xF8) == 0xf0)
        {
                //In fourth range!
                int firstthree = (charval & 0b00000111);
				char d;
                scan.get(d);
				isValidByte234(d);
                int secondcharval3 = (int)d;
                int secondsix3 = (secondcharval3 & 0b00111111);
				char e;
                scan.get(e);
				isValidByte234(e);
                int thirdcharval2 = (int)e;
                int thirdsix2 = (thirdcharval2 & 0b00111111);
				char f;
                scan.get(f);
				isValidByte234(f);
                int fourthcharval = (int)f;
                int fourthsix = (fourthcharval & 0b00111111);
                firstthree = firstthree << 18;
                secondsix3 = secondsix3 << 12;
                thirdsix2 = thirdsix2 << 6;
                finalone= (firstthree | secondsix3 | thirdsix2 | fourthsix);
				countersize+=4;
				readfilevals.push_back(finalone);
				ostringstream sst6;
				sst6 << c << d << e << f;
				getfull = sst6.str();
				fullstrings.push_back(getfull);
			
				
        }
        else
		{
			throw string("Invalid byte in file: ") + filename;						//If byte doesn't fall in range of any of these values														
																			// then it's invalid
		}
		for(unsigned int p = 0; p < propertyvalues.size(); p++)					//Take count
		{
			if(propertyvalues[p] == finalone)
			{
				count1.at(p)++;
			}
		}

    }
	scan.close();
}

void U::propfile(const string propfile)
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
		count1.push_back(0);										//holds count of properties

	}

	
	

}
int U::size()const
{
	return readfilevals.size();
}
string U::get()const{
	return get(0, size()); 
}

string U::get(int index) const{
	return get(index, index+1);
}

string U::get(int start, int end) const{
	if((start < 0) || (end < start))
	{
		throw string("ERROR: Given incorrect indices, either negative or not in order");
	}
	unsigned int end2 = end;
	if(end2 > fullstrings.size())
	{
		throw string("ERROR: end index out of bounds");
	}
	string partial;
	for(int i = start; i < end; i++)
	{
		partial += fullstrings[i];
	}
	return partial;
}

int U::propcount(string prop)const{
	int decval = 0;
	for(size_t i = 0; i < properties.size(); i++)
	{
		if(properties.at(i) == prop)
		decval += count1.at(i);
	}
	return decval;

}

set<string> U::props() const{
	return propsset;
}

void U::isValidByte234(char &d)
{
	if((d & 0xc0) != 0x80)
	{
		throw string("Invalid byte in file to read");
	}
}
