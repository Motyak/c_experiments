#include <sstream>
#include <iostream>

// T must overload `std::ostream& operator<<(std::ostream&, const T&)`
template<class T>
std::string join(T container, std::string delim) {
    std::ostringstream oss;
    auto it = std::begin(container);
    auto end = std::end(container);

    oss << *it;
    for(++it; it != end; ++it)
        oss << delim << *it;

    return oss.str();
}

struct Person {
    std::string name;
    size_t age;

    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        return os << p.name;
    }
};

int main()
{
    auto persons = {
        Person{"Peter", 12},
        Person{"Charlie", 34},
        Person{"Tango", 56},
    };

    std::cout << join(persons, ", ") << std::endl;
}

// Peter, Charlie, Tango
