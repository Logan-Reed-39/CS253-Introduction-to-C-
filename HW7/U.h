//Logan Reed
//2017-04-28
//CS253 HW7
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
	U &operator=(const std::string &s);						// String assignment operator
	U operator+(const U &rhs)const;							//UU concat
	U operator+(const std::string &rhs)const;				//US concat
	U &operator+=(const U &rhs);							//UU append
	U &operator+=(const std::string &rhs);					//US append
	std::string operator[](int index)const;
	operator bool()const;
	bool operator==(const U &) const;
	bool operator==(const std::string &) const; 
	bool operator!=(const U &) const;
	bool operator!=(const std::string &) const;
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
	std::string file;
	void isValidByte234(char &d);
};
	
std::ostream &operator<<(std::ostream &, const U &);
bool operator==(const std::string &lhs, const U &rhs);
bool operator!=(const std::string &lhs, const U &rhs);
U operator+(const std::string &s, const U &rhs); //SU concat
#endif