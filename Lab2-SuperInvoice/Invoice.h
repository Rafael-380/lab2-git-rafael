#ifndef INVOICE_H
#define INVOICE_H

#include "Item.h"
#include <vector>
#include <iostream>

class Invoice {
public:
    Invoice(long long seller_nip, long long buyer_nip);

    void add_item(const Item& item);

    friend std::ostream& operator<<(std::ostream& os, const Invoice& invoice);

private:
    long long seller_nip_;
    long long buyer_nip_;
    std::vector<Item> items_;
};

#endif // INVOICE_H
