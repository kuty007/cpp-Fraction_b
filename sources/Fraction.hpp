//
// Created by asaf7 on 4/14/2023.
//
#include <iostream>
using namespace std;
#ifndef CPP_FRACTION_A_FRACTION_H
#define CPP_FRACTION_A_FRACTION_H

namespace ariel {

    class Fraction {
    private:
        int numerator;
        int denominator;
        float value;
    public:
        Fraction(int numerator, int denominator);
        Fraction(float value);
        Fraction();
        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int numerator);
        void setDenominator(int denominator);
        void reduce();
        Fraction& operator++();
        Fraction& operator--();
        Fraction operator++(int);
        Fraction operator--(int);
        friend Fraction operator+(const Fraction& frac_a, const Fraction& frac_b);
        friend Fraction operator+(const Fraction& frac_a, const float& float_b);
        friend Fraction operator-(const Fraction& frac_a, const Fraction& frac_b);
        friend Fraction operator*(const Fraction& frac_a, const Fraction& frac_b);
        friend Fraction operator/(const Fraction& frac_a, const Fraction& frac_b);
        friend bool operator==(const Fraction& frac_a, const Fraction& frac_b);
        friend bool operator!=(const Fraction& frac_a, const Fraction& frac_b);
        friend bool operator>(const Fraction& frac_a, const Fraction& frac_b);
        friend bool operator<(const Fraction& frac_a, const Fraction& frac_b);
        friend bool operator>=(const Fraction& frac_a, const Fraction& frac_b);
        friend bool operator<=(const Fraction& frac_a, const Fraction& frac_b);
        friend ostream& operator<<(ostream& ost, const Fraction& fraction);
        friend istream& operator>>(istream& ist, Fraction& fraction);
        //do all the operators with float
        friend  Fraction operator+(const float& float_b, const Fraction& frac_b);
        friend  Fraction operator-(const float& float_b, const Fraction& frac_b);
        friend  Fraction operator*(const float& float_b, const Fraction& frac_b);
        friend  Fraction operator/(const float& float_b, const Fraction& frac_b);
        friend bool operator==(const float& float_b, const Fraction& frac_b);
        friend bool operator!=(const float& float_b, const Fraction& frac_b);
        friend bool operator>(const float& float_b, const Fraction& frac_b);
        friend bool operator<(const float& float_b, const Fraction& frac_b);
        friend bool operator>=(const float& float_b, const Fraction& frac_b);
        friend bool operator<=(const float& float_b, const Fraction& frac_b);
        //do all the operators with Fraction and float
        friend  Fraction operator-(const Fraction& frac_a, const float& float_b);
        friend  Fraction operator*(const Fraction& frac_a, const float& float_b);
        friend  Fraction operator/(const Fraction& frac_a, const float& float_b);
        friend bool operator==(const Fraction& frac_a, const float& float_b);
        friend bool operator!=(const Fraction& frac_a, const float& float_b);
        friend bool operator>(const Fraction& frac_a, const float& float_b);
        friend bool operator<(const Fraction& frac_a, const float& float_b);
        friend bool operator>=(const Fraction& frac_a, const float& float_b);
        friend bool operator<=(const Fraction& frac_a, const float& float_b);


    };

} // ariel

#endif //CPP_FRACTION_A_FRACTION_H
