//Logan Reed
//2017-05-05
//CS253 HW8
#ifndef U_H_INCLUDED
#define U_H_INCLUDED

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cassert>

class U{
	public:
	U();				// default constructor 
	U(const U &rhs);	// copy constructor
	U(const std::string filename); // filename constructor
    template<typename t2>
	U(t2 a, t2 b)
    {
        append(std::string(a,b));
    }
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

    int front()const;
    int back()const;
	~U();				// Destructor
    /*class iterator {
		public:
            iterator() : offset(0){}// Default constructor
            iterator(const U &u1, int offset1) : u(u1), offset(offset1){}
            iterator(const iterator &rhs) : offset(rhs.offset){}  // Copy constructor
            iterator &operator=(const iterator &rhs){       // Assignment operator
             offset = rhs.offset;   
            }
            ~iterator();                                    // Destructor
            bool operator==(const iterator &rhs) const {       // it == it
                return offset ==rhs.offset;
            }
            bool operator!=(const iterator &rhs) const {       // it != it
                return !(*this == rhs);	
            }
            iterator &operator++() {	                    // Preincrement
                assert(u);
                offset++;
                return *this;
            }
            iterator operator++(int) {	                     // Postincrement
                const auto save = *this;
                ++*this;			
                return save;
            }
            iterator &operator--() {	                    // Predecrement
                assert(u);
                offset--;
                return *this;
            }
            iterator operator--(int) {	                     // Postdecrement
                const auto save = *this;
                --*this;			
                return save;
            }
            int operator*()const
            {
                return codepoint(offset);
            }
        private:
            int offset;
            U u;
    };
    */
    using iterator = std::vector<unsigned int>::const_iterator;
    iterator begin()const;
    iterator end()const;
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
	std::vector<unsigned int> readfilevals;               // vector of int values to consecutively addto
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
