//Logan Reed
//2017-03-17
//CS253 HW5
#ifndef U_H_INCLUDED
#define U_H_INCLUDED


#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
class U {
	public:
	U();				// default constructor 
	U(const U &rhs);	// copy constructor
	U(const std::string propfilename, const std::string litdata);			// Test constructor
	U &operator=(const U &rhs);								// Assignment operator
	~U();				                                    // Destructor
	void readfile(const std::string filename);				//ASK ABOUT CONSTNESS
	void propfile(const std::string properties);
	int size()const;
	std::string get()const;
	std::string get(int index) const;
	std::string get(int start, int end) const;
	int propcount(std::string)const;
	std::set<std::string> props()const;
	private:
	std::string accumdata;								// accumulated data
    std::vector<int> readfilevals;                   // vector of int values to consecutively addto
    std::string getrangedvalues;
    void isValidByte234(char &d);
	int countersize;
    std::set<std::string> propsset;
    std::string getfull;
	std::vector<std::string> fullstrings;
	std::vector<std::string> properties;
	std::vector<int>propertyvalues;
	std::vector<int>count1;

};

#endif /*U_H_INCLUDED */
