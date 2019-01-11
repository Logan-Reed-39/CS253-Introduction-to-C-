//Logan Reed
//2017-04-05
//CS253 HW6
#ifndef U_H_INCLUDED
#define U_H_INCLUDED

#include<iostream>
#include<string>
#include<map>
#include<vector>

class U{
	public:
	U();				// default constructor 
	U(const U &rhs);	// copy constructor
	U(const std::string filename); // filename constructor 
	U &operator=(const U &rhs);								// Assignment operator
	~U();				                                    // Destructor
	void readfile(const std::string filename);				//readfile method
	void append(std::string created);						//append, check if correct
	std::string get()const;										
	std::string get(int index) const;
	std::string get(int start, int end) const;
	int codepoint(int index)const;							//codepoint method
	int size()const;
	bool empty()const;
	void clear();
	private:
	std::vector<int> readfilevals;                   // vector of int values to consecutively addto
	std::vector<int>propertyvalues;
	std::vector<std::string> fullstrings;
	std::vector<int>count1;
	void isValidByte234(char &d);
};

#endif