//
// Created by asaf7 on 4/14/2023.
//

#include "Fraction.hpp"
#include <cmath>

//
int MAX_INT = numeric_limits<int>::max();
int MIN_INT = numeric_limits<int>::min();

namespace ariel {
    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("denominator can't be 0");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->value = std::round(static_cast<float>(numerator) / denominator * 1000.0) / 1000.0;
        this->reduce();
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
    }

    Fraction::Fraction(float value) {
        this->numerator = (int) (value * 1000);
        this->denominator = 1000;
        this->value = std::round(static_cast<float>(numerator) / denominator * 1000.0) / 1000.0;
        this->reduce();
        if (this->denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }
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

    float Fraction::getValue() const {
        return this->value;
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
        //check overflow
        if ((b.denominator > 0 && a.numerator > MAX_INT / b.denominator) ||
            (b.denominator < 0 && a.numerator < MAX_INT / b.denominator)) {
            throw std::overflow_error("overflow");
        }
        if ((a.denominator > 0 && b.numerator > MAX_INT / a.denominator) ||
            (a.denominator < 0 && b.numerator < MAX_INT / a.denominator)) {
            throw std::overflow_error("overflow");
        }
        //check underflow
        if ((b.denominator > 0 && a.numerator < MIN_INT / b.denominator) ||
            (b.denominator < 0 && a.numerator > MIN_INT / b.denominator)) {
            throw std::underflow_error("underflow");
        }
        if ((a.denominator > 0 && b.numerator < MIN_INT / a.denominator) ||
            (a.denominator < 0 && b.numerator > MIN_INT / a.denominator)) {
            throw std::underflow_error("underflow");
        }
        int numerator_a = a.numerator * b.denominator;
        int numerator_b = b.numerator * a.denominator;
        if ((numerator_a > 0 && numerator_b > MAX_INT - numerator_a) ||
            (numerator_a < 0 && numerator_b < MIN_INT - numerator_a)) {
            throw std::overflow_error("overflow");
        };
        return Fraction(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
    }

    Fraction operator+(const Fraction &a, const float &b) {
        Fraction temp = Fraction(b);
        return a + temp;
    }

    Fraction operator-(const Fraction &a, const Fraction &b) {
        //check overflow
        if (a.numerator > 0 && b.numerator < 0) {
            if (a.numerator > MAX_INT + b.numerator) {
                throw std::overflow_error("overflow");
            }
        } else if (a.numerator < 0 && b.numerator > 0) {
            if (a.numerator < MIN_INT + b.numerator) {
                throw std::overflow_error("overflow");
            }
        }
        return Fraction(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
    }

    Fraction operator*(const Fraction &a, const Fraction &b) {
        //check overflow
        if ((b.numerator > 0 && a.numerator > MAX_INT / b.numerator) ||
            (b.numerator < 0 && a.numerator < MAX_INT / b.numerator)) {
            throw std::overflow_error("overflow");
        }
        if ((b.denominator > 0 && a.denominator > MAX_INT / b.denominator) ||
            (b.denominator < 0 && a.denominator < MAX_INT / b.denominator))
            throw std::overflow_error("overflow");
        //check underflow
//        if ((b.numerator > 0 && a.numerator < MIN_INT / b.numerator) ||
//            (b.numerator < 0 && a.numerator > MIN_INT / b.numerator)) {
//            throw std::underflow_error("underflow");
//        }
//        if ((b.denominator > 0 && a.denominator < MIN_INT / b.denominator) ||
//            (b.denominator < 0 && a.denominator > MIN_INT / b.denominator)) {
//            throw std::underflow_error("underflow");
//        }



        return Fraction(a.numerator * b.numerator, a.denominator * b.denominator);
    }

    Fraction operator/(const Fraction &a, const Fraction &b) {
        if (b.numerator == 0) {
            throw std::runtime_error("denominator can't be 0");
        }
        //check overflow
        if ((b.denominator > 0 && a.numerator > MAX_INT / b.denominator) ||
            (b.denominator < 0 && a.numerator < MAX_INT / b.numerator)) {
            throw std::overflow_error("overflow");
        }
        if ((b.numerator > 0 && a.denominator > MAX_INT / b.numerator) ||
            (b.numerator < 0 && a.denominator < MAX_INT / b.numerator))
            throw std::overflow_error("overflow");
        //check underflow
//        if ((b.denominator > 0 && a.numerator < MIN_INT / b.denominator) ||
//            (b.denominator < 0 && a.numerator > MIN_INT / b.numerator)) {
//            throw std::underflow_error("underflow");
//        }
//        if ((b.numerator > 0 && a.denominator < MIN_INT / b.numerator) ||
//            (b.numerator < 0 && a.denominator > MIN_INT / b.numerator))
//            throw std::underflow_error("underflow");

        return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
    }

    bool operator==(const Fraction &a, const Fraction &b) {
//        return a.numerator * b.denominator == b.numerator * a.denominator;
        return a.value == b.value;
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
        int numerator; //temp numerator
        int denominator; //temp denominator
        if (!(is >> numerator >> denominator)) {
            throw std::runtime_error("invalid input");
        }
        if (denominator == 0) {
            throw std::runtime_error("denominator can't be 0");
        }
        fraction = Fraction(numerator, denominator);
        return is;
//        if (!(is >> fraction.numerator >> fraction.denominator)) {
//            throw std::runtime_error("invalid input");
//        }
//        if (fraction.denominator == 0) {
//            throw std::runtime_error("denominator can't be 0");
//        }
//        if (fraction.denominator < 0) {
//            fraction.numerator *= -1;
//            fraction.denominator *= -1;
//        }
//        float value = (float) fraction.numerator / fraction.denominator;
//        fraction.value = std::round(value * 1000.0) / 1000.0;
//
//        return is;
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
        float value2 = (float) numerator / denominator;
        this->value = std::round(value2 * 1000) / 1000;
        return *this;
    }

    Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        this->numerator += this->denominator;
        this->reduce();
        float value2 = (float) numerator / denominator;
        this->value = std::round(value2 * 1000) / 1000;
        return temp;
    }

    Fraction &Fraction::operator--() {
        this->numerator -= this->denominator;
        this->reduce();
        float value2 = (float) numerator / denominator;
        this->value = std::round(value2 * 1000) / 1000;

        return *this;
    }

    Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        this->numerator -= this->denominator;
        this->reduce();
        float value2 = (float) numerator / denominator;
        this->value = std::round(value2 * 1000) / 1000;
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