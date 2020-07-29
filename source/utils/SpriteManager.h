#include <iostream>
#include <string>

using namespace std;

namespace NG {
    void print(std::string text) {
        std::cout << text << std::endl;
    }

    std::string hello(std::string a) {
        return "My name is " + a;
    }
}