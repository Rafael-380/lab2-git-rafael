#ifndef DURATION_H
#define DURATION_H

#include <iostream>

class Time {
public:
    Time(int seconds = 0);           // construtor padrão
    Time(int h, int m, int s);       // construtor por horas/min/seg

    void set(int h, int m, int s);   // definir tempo
    int to_seconds() const;          // conversão para segundos

    Time operator+(const Time& other) const;
    Time operator-(const Time& other) const;
    Time operator*(int scalar) const;

    operator int() const;            // conversão para int (segundos)

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    friend std::istream& operator>>(std::istream& is, Time& t);

private:
    int seconds_;
};

#endif // DURATION_H
