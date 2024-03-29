// #include <iostream> //preprocessor directory
// int main(){
//     [[maybe_unused]] int x = 5;
//     int z {5};
//     double y;// std::cout << "Hello World" << std::endl;
//     // std::cout << y << x; // character out // cntrl c + k , k + u
//     int a{};
//     //std::cin >> a;
//     //std::cout << a;
//     //std::cout << a;
//     std::cout << sizeof(int);

//     return 0; /*multi-line comment*/
// }

#include <iostream>
using namespace std;
int main(){
    int x,y;
    cout 
        << "Enter the first number : ";
    cin 
        >> x;

    cout 
        // << "\n" 
        << "Enter the second number : ";
    cin >> y;

    cout 
        << x << " + " << y << " = " << x + y
        << "\n" << x << " - " << y << " = " << x - y;
    return 0;
}
