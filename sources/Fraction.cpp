//
// Created by asaf7 on 4/14/2023.
//

#include "Fraction.hpp"

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("denominator can't be 0");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->value = (float) numerator / denominator;
        this->reduce();
         if(this->denominator < 0){
            this->numerator *= -1;
            this->denominator *= -1;
       }
    }

    Fraction::Fraction(float value) {
        this->numerator = (int) (value * 1000);
        this->denominator = 1000;
        this->value = (float) numerator / denominator;
        this->reduce();


    }

    Fraction::Fraction() {
        this->value = 0;
        this->numerator = 0;
        this->denominator = 1;
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    void Fraction::setNumerator(int numerator) {
        this->numerator = numerator;
    }

    void Fraction::setDenominator(int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("denominator can't be 0");
        }
        this->denominator = denominator;
    }

    void Fraction::reduce() {
        int gcd = std::__gcd(this->numerator, this->denominator);
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    //implement the operators
    Fraction operator+(const Fraction &a, const Fraction &b) {
        return Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);

    }

    Fraction operator+(const Fraction &a, const float &b) {
        Fraction temp = Fraction(b);
        return a + temp;
    }

    Fraction operator-(const Fraction &a, const Fraction &b) {
        return Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
    }

    Fraction operator*(const Fraction &a, const Fraction &b) {
        return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    Fraction operator/(const Fraction &a, const Fraction &b) {
        if (b.numerator == 0) {
            throw std::runtime_error("denominator can't be 0");
        }
        return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
    }

    bool operator==(const Fraction &a, const Fraction &b) {
        return a.numerator * b.denominator == b.numerator * a.denominator;
    }

    bool operator!=(const Fraction &a, const Fraction &b) {
        return a.numerator * b.denominator != b.numerator * a.denominator;
    }

    bool operator>(const Fraction &a, const Fraction &b) {
        return a.value > b.value;
    }

    bool operator<(const Fraction &a, const Fraction &b) {
        return a.value < b.value;
    }

    bool operator>=(const Fraction &a, const Fraction &b) {
        return a.value >= b.value;
    }

    bool operator<=(const Fraction &a, const Fraction &b) {
        return a.value <= b.value;
    }

    ostream &operator<<(ostream &os, const Fraction &fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }

    istream &operator>>(istream &is, Fraction &fraction) {

        is >> fraction.numerator;
        is >> fraction.denominator;
        if (fraction.denominator == 0) {
            throw std::runtime_error ("denominator can't be 0");
        }
        if (fraction.denominator < 0) {
            fraction.numerator *= -1;
            fraction.denominator *= -1;
        }
        fraction.value = (float) fraction.numerator / fraction.denominator;
        return is;
    }

    Fraction operator+(const float &a, const Fraction &b) {
        Fraction temp = Fraction(a);
        return temp + b;
    }

    Fraction operator-(const float &a, const Fraction &b) {
        Fraction temp = Fraction(a);
        return temp - b;

    }

    Fraction operator*(const float &a, const Fraction &b) {
        Fraction temp = Fraction(a);
        return temp * b;
    }

    Fraction operator/(const float &a, const Fraction &b) {
        Fraction temp = Fraction(a);
        return temp / b;
    }

    bool operator==(const float &a, const Fraction &b) {
        Fraction temp = Fraction(a);
        return temp == b;
    }

    bool operator!=(const float &a, const Fraction &b) {
        return a * b.denominator != b.numerator;
    }

    bool operator>(const float &a, const Fraction &b) {
        return a * b.denominator > b.numerator;
    }

    bool operator<(const float &a, const Fraction &b) {
        return a < b.value;
    }

    bool operator>=(const float &a, const Fraction &b) {
        return a >= b.value;
    }

    bool operator<=(const float &a, const Fraction &b) {
        return a <= b.value;
    }


    Fraction &Fraction::operator++() {
        this->numerator += this->denominator;
        this->reduce();
        this->value = (float) numerator / denominator;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        this->numerator += this->denominator;
        return temp;
    }

    Fraction &Fraction::operator--() {
        this->numerator -= this->denominator;
        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        this->numerator -= this->denominator;
        return temp;
    }

    Fraction operator-(const Fraction &a, const float &b) {
        Fraction temp = Fraction(b);
        return a - temp;

    }

    Fraction operator*(const Fraction &a, const float &b) {

        Fraction temp = Fraction(b);
        return a * temp;
    }

    Fraction operator/(const Fraction &a, const float &b) {
        Fraction temp = Fraction(b);
        return a / temp;
    }

    bool operator==(const Fraction &a, const float &b) {
        Fraction temp = Fraction(b);
        return a == temp;
    }

    bool operator!=(const Fraction &a, const float &b) {
        return 1;

    }

    bool operator>(const Fraction &a, const float &b) {

        return a.value > b;
    }

    bool operator<(const Fraction &a, const float &b) {

        return a.value < b;
    }

    bool operator>=(const Fraction &a, const float &b) {

        return a.value >= b;
    }

    bool operator<=(const Fraction &a, const float &b) {

        return a.value <= b;
    }


} // ariel