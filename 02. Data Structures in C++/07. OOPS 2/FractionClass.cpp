#include <iostream>
using namespace std;

class Fraction {
    private:
    int numerator, denominator;

    public:
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int d) {
        denominator = d;
    }

    void print() const {
        cout << this->numerator << " / " << this->denominator << endl;
    }

    void simplify() {
        int gcd = 1;
        int m = min(numerator, denominator);
        for (int i=1; i<m; i++) {
            if (numerator%i == 0  &&  denominator%i == 0) {
                gcd = i;
            }
        }
        this->numerator /= gcd;
        this->denominator /= gcd;
    }

    Fraction add (Fraction const &F) {
        int denom = this->denominator * F.denominator;
        int x = denom / this->denominator;
        int y = denom / F.denominator;
        int num = (x*this->numerator) + (y*F.numerator);
        Fraction fNew(num, denom);
        fNew.simplify();
        return fNew;
    }

    Fraction multiply (Fraction const &F) {
        int num = this->numerator * F.numerator;
        int denom = this->denominator * F.denominator;
        Fraction fNew(num, denom);
        fNew.simplify();
        return fNew;
    }

    Fraction operator + (Fraction const &F) {
        int denom = this->denominator * F.denominator;
        int x = denom / this->denominator;
        int y = denom / F.denominator;
        int num = (x*this->numerator) + (y*F.numerator);
        Fraction fNew(num, denom);
        fNew.simplify();
        return fNew;
    }

    Fraction operator * (Fraction const &F) {
        int num = this->numerator * F.numerator;
        int denom = this->denominator * F.denominator;
        Fraction fNew(num, denom);
        fNew.simplify();
        return fNew;
    }

    bool operator == (Fraction const &F) {
        return (numerator==F.numerator && denominator==F.denominator);
    }

    // Pre-increment
    Fraction& operator ++ () {
        numerator = numerator + denominator;
        simplify();
        return *this;
    }

    // Post-increment
    Fraction operator ++ () {
        Fraction FNew(numerator, denominator);
        numerator = numerator + denominator;
        simplify();
        fNew.simplify();
        return FNew;
    }

    Fraction& operator += (Fraction const &F) {
        int lcm = denominator * F.denominator;
        int x = lcm / denominator;
        int y = lcm / F.denominator;
        int num = x*numerator + y*F.numerator;
        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
};