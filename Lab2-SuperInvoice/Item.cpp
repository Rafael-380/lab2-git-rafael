#include "Item.h"
#include <iomanip>

Item::Item(const std::string& name, double unit_net_price, char vat_type, int quantity)
    : name_(name), unit_net_price_(unit_net_price), vat_type_(vat_type), quantity_(quantity) {}

double Item::get_vat_rate() const {
    switch (vat_type_) {
    case 'A': return 0.23;
    case 'B': return 0.08;
    case 'C': return 0.0;
    default:  return 0.0; // valor por defeito se for inválido
    }
}

double Item::get_net_price() const {
    return unit_net_price_ * quantity_;
}

double Item::get_total_price() const {
    return get_net_price() * (1 + get_vat_rate());
}

const std::string& Item::get_name() const {
    return name_;
}

char Item::get_vat_type() const {
    return vat_type_;
}

int Item::get_quantity() const {
    return quantity_;
}

double Item::get_unit_net_price() const {
    return unit_net_price_;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << std::fixed << std::setprecision(2);
    os << std::setw(2) << "" << std::left << std::setw(15) << item.name_ << " | "
       << std::right << std::setw(4) << item.unit_net_price_ << "  "
       << item.vat_type_ << " | "
       << std::setw(3) << item.quantity_ << " | "
       << std::setw(6) << item.get_net_price() << " | "
       << std::setw(6) << item.get_total_price();
    return os;
}
