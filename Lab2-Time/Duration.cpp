#include "Duration.h"
#include <iomanip>

Time::Time(int seconds) : seconds_(seconds) {}

Time::Time(int h, int m, int s) {
    seconds_ = h * 3600 + m * 60 + s;
}

void Time::set(int h, int m, int s) {
    seconds_ = h * 3600 + m * 60 + s;
}

int Time::to_seconds() const {
    return seconds_;
}

Time Time::operator+(const Time& other) const {
    return Time(seconds_ + other.seconds_);
}

Time Time::operator-(const Time& other) const {
    return Time(seconds_ - other.seconds_);
}

Time Time::operator*(int scalar) const {
    return Time(seconds_ * scalar);
}

Time::operator int() const {
    return seconds_;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
    int total = t.seconds_;
    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = total % 60;

    if (h > 0) os << std::setw(2) << std::setfill('0') << h << "h:";
    os << std::setw(2) << std::setfill('0') << m << "m:"
       << std::setw(2) << std::setfill('0') << s << "s";

    return os;
}

std::istream& operator>>(std::istream& is, Time& t) {
    int h = 0, m = 0, s = 0;
    char ch;
    is >> h >> ch >> m >> ch >> s;  // formato esperado: 10:12:01
    t.set(h, m, s);
    return is;
}
