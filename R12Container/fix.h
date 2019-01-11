// This class is certainly inadequate.  It has no include guards, is missing
// several ctors, has no assignment operator, etc.
#include<iostream>

template <typename T, int N>
class fix {
  public:
    typedef unsigned int size_type;
    typedef T *iterator;
    size_type size() const {
	return N;
    }
    T &operator[] (size_type index) {
	if((index > N) || (index < 0))
    {
        std::cerr << "Index out of bound!\n";
        exit(1);
    }
    return data[index];
    }
    iterator begin() {
	return &data[0];
    }
    iterator end() {
	return &data[N];
    }
  private:
    T data[N];
};
