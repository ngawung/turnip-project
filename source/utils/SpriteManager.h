#include <iostream>
#include <string>

using namespace std;

namespace NG {
    void print(string text) {
        std::cout << text << std::endl;
    }

    string hello(string a) {
        return "My name is " + a;
    }
}