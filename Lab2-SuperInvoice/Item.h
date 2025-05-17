#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
public:
    Item(const std::string& name, double unit_net_price, char vat_type, int quantity);

    double get_net_price() const;          // Quantidade * Preco individual
    double get_vat_rate() const;           // Percentagem de IVA
    double get_total_price() const;        // Preco total com IVA
    const std::string& get_name() const;
    char get_vat_type() const;
    int get_quantity() const;
    double get_unit_net_price() const;

    friend std::ostream& operator<<(std::ostream& os, const Item& item);

private:
    std::string name_;
    double unit_net_price_;
    char vat_type_; // 'A' = 23%, 'B' = 8%, 'C' = 0%
    int quantity_;
};

#endif // ITEM_H
