//Logan Reed
//2017-04-28
//CS253 HW7
#ifndef P_H_INCLUDED
#define P_H_INCLUDED

#include<set>
#include<string>
#include<vector>
class P{
	public:
	P();				// default constructor
	P(const P &rhs);	// copy constructor
	P(const std::string filename); // filename constructor 
	P &operator=(const P &rhs);								// Assignment operator
	~P();				                                    // Destructor
	void readfile(const std::string filename);				//readfile method
	std::set<std::string> props()const;						// props
	void count(int codepoint);
	operator bool()const;
	int count(std::string)const;
	int size()const;
	bool empty()const;
	void clear();
	private:
	std::set<std::string> propsset;
	std::vector<std::string> properties;
	std::vector<int>propertyvalues;
	std::vector<int>count1;
	std::multiset<int> counting;
};

std::ostream &operator<<(std::ostream &, const P &);
#endif