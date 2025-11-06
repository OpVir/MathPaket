#include <iostream>
#include <string>
#include "database/funcDB.hpp"

using namespace database;
// Примеры функций
int add(int a, int b) { return a + b; }
double multiply(double a, double b) { return a * b; }
std::string greet(const std::string& name) { return "Hello, " + name + "!"; }
void printMessage() { std::cout << "Hello from void function!" << std::endl; }

int main() {
    
    std::system("pause");
    return 0;
}