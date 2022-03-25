#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

struct MyContainer {
    MyContainer(const std::initializer_list<int>& v) {
        std::cout << "MyContainer(const std::initializer_list<int>& v)\n";
        for (const auto& x : v) {

        }
    }

    explicit MyContainer(int initial_size) {
        std::cout << "explicit MyContainer(int initial_size)\n";
    }
};

struct mymap {
    int& operator[](const std::string& key) {
    }

    int& at(const std::string& key) const {
    }
};

void checkKey(const std::map<std::string,int>& m) {
    //auto v = m["blabla"]; // operator[] is not const!
    auto v = m.at("blabla"); // at method is used fetch value from a const map
}

int main() {
    using std::string, std::cout, std::stringstream, std::vector, std::map;

    MyContainer alpha{1,2,3,4,5,6,7};
    MyContainer beta{1}; // by default, initializer-list takes precedence
    MyContainer gamma(1); // Calls the MyContainer(int) constructor

    return 0;

    string msg{"Hello world"};
    msg += "!";
    msg += 67.2f; // this becomes an int (67) -> char !!
    cout << msg << '\n';

    stringstream ss;
    ss << "Hello world" << "!" << 67.2f;
    cout << ss.str() << '\n';

    // Vector
    vector<int> v;
    vector<int> v2{1,2,3,4,5,6,7,8};
    cout << v.size();
    for (const auto& i : v2) {
        cout << i << '\n';
    }
    v.push_back(5);
    v.pop_back();
    
    // Map
    map<string,int> mymap;
    mymap["somekey"] = 6;
    mymap["otherkey"] = 7;
    if (mymap["blabla"]) { // This creates a new key pair if it does not exist!
    }
    if (mymap.count("somekey")) {
        // somekey exists
    }



    for (const auto& kv : mymap) {
        cout << kv.first << "->" << kv.second <<'\n';
    }

 
}