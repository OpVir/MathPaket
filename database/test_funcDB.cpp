#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
#include <variant>
#include <any>
#include "funcDB.hpp"

using namespace database;
// Примеры функций
int add(int a, int b) { return a + b; }
double multiply(double a, double b) { return a * b; }
std::string greet(const std::string& name) { return "Hello, " + name + "!"; }
void printMessage() { std::cout << "Hello from void function!" << std::endl; }

int main() {
    FuncContainer myContainer;
    std::function<int(int, int)> func;
    func = add;
    myContainer.set<int, int, int>(std::string("myFunc"), func);
    auto myFunc = myContainer.get<int, int, int>("myFunc");
    std::cout<<myFunc(3, 4)<<std::endl;
    try
    {
            auto errorFunc = myContainer.get<int, int, int>("abracadabra");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::system("pause");
    return 0;
}