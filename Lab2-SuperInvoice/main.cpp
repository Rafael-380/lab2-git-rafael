#include <iostream>
#include "Invoice.h"

int main() {
    Invoice inv(7770003699, 1234567890);

    inv.add_item(Item("M3 screw", 0.37, 'A', 100));
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));

    std::cout << std::endl << inv << std::endl;

    return 0;
}
