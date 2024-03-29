#include <iostream>
#include <string>
int main(void)
{
    std::string str = "Hello, World!";
    std::string slice = str.substr(0, 5); 
    std::cout << slice;
}