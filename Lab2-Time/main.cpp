#include <iostream>
#include "Duration.h"

int main() {
    Time t1(200);
    std::cout << t1 << std::endl; // 03m:20s

    Time t2;
    std::cout << "Enter time (hh:mm:ss): ";  //Not working in Qt creator but working in Web compiler
    std::cin >> t2;

    Time t3 = t2 - t1;
    int t3_seconds = t3;

    std::cout << "t2 - t1 = " << t3 << std::endl;
    std::cout << "In seconds: " << t3_seconds << std::endl;

    return 0;
}


