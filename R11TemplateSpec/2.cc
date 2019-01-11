#include <iostream>
#include <map>
#include <iomanip>
#include <string>

using namespace std;

template <typename T>
class BarGraph {
  public:
    void operator+=(const T &datum) {
        data[datum]++;
    }
    void dump() const {
	for (const auto &val : data)
	    cout << right << setw(10) << val.first << ' '
		 << string(val.second, '*') << '\n';
        cout << '\n';
    }
    friend ostream& operator<<(ostream &os, const BarGraph<T> &b)
    {
        for (const auto &val : b.data)
            os << right << setw(10) << val.first << ' '
            << string(val.second, '*') << '\n';
            os << '\n';
        return os;
    }
  private:
    map<T, unsigned> data;
};

template <>
class BarGraph<bool> {
    unsigned false_count, true_count;
  public:
    BarGraph() : false_count(0), true_count(0) {
    }
    void operator+=(bool datum) {
	datum ? true_count++ : false_count++;
    }
    void dump() const {
        cout << "     false " << string(false_count, '*') << "\n"
                "      true " << string(true_count,  '*') << "\n\n";
    }

};


int main() {
    BarGraph<int> alpha;
    alpha += 12;
    alpha += 6;
    alpha += 4;
    alpha += 6;
    cout << alpha;

    BarGraph<double> beta;
    beta += 3.14;
    beta += 2.71828;
    beta += 6.023e23;
    beta += 2.71828;
    cout << beta << '\n';

    BarGraph<bool> gamma;
    gamma += false;
    gamma += true;
    gamma += false;
    gamma += true;
    gamma += true;
    //cout << gamma << '\n';

    BarGraph<char> delta;
    delta += 'G';
    delta += 'e';
    delta += 'o';
    delta += 'f';
    delta += 'f';
    //cout << delta << '\n';

    return 0;
}
