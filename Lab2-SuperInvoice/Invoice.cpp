#include "Invoice.h"
#include <iomanip>

Invoice::Invoice(long long seller_nip, long long buyer_nip)
    : seller_nip_(seller_nip), buyer_nip_(buyer_nip) {}

void Invoice::add_item(const Item& item) {
    items_.push_back(item);
}

std::ostream& operator<<(std::ostream& os, const Invoice& invoice) {
    os << "------------------VAT invoice------------------\n";
    os << "===============================================\n";
    os << "Seller: " << invoice.seller_nip_ << "      Buyer: " << invoice.buyer_nip_ << "\n\n";
    os << "                       c.j. VAT  il.     net     total\n";

    double total_net = 0.0;
    double total_gross = 0.0;

    int index = 1;
    for (const auto& item : invoice.items_) {
        os << index << ". " << item << "\n";
        total_net += item.get_net_price();
        total_gross += item.get_total_price();
        ++index;
    }

    os << "\n------------------------------------ TOTAL ----\n";
    os << std::right << std::setw(35) << std::fixed << std::setprecision(2)
       << total_net << " | " << total_gross << "\n";

    return os;
}
