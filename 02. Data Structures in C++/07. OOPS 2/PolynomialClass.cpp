#include <iostream>
using namespace std;


class Polynomial {
    public:

    int *degCoeff;
    int capacity;

// Default constructor
    Polynomial() {
        degCoeff = new int[5];
        capacity = 5;
        for (int i=0; i<5; i++) {
            degCoeff[i] = 0;
        }
    }

// Copy constructor
    Polynomial(Polynomial const &p) {
        //   Shallow copy
        //this->degCoeff = p.degCoeff;
        //   Deep copy
        this->degCoeff = new int[p.capacity];
        for (int i=0; i<p.capacity; i++) {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

// setCoefficient
    void setCoefficient(int degree, int coeff) {
        if (degree >= capacity) {
            int size = 2*capacity;
            while (degree >= size) {
                size *= 2;
            }
            int *newdegCoeff = new int[size];
            for(int i=0; i<capacity; i++) {
                newdegCoeff[i] = this->degCoeff[i];
            }
            for(int i=capacity; i<size; i++) {
                newdegCoeff[i] = 0;
            }
            capacity = size;
            delete this->degCoeff;
            this->degCoeff = newdegCoeff;
        }
        this->degCoeff[degree] = coeff;
    }

// Overload "+" operator
    Polynomial operator + (Polynomial const &p) {
        Polynomial p1;
        int i=0, j=0;
        while(i<this->capacity && j<p.capacity) {
            int deg = i;
            int coeff = this->degCoeff[i] + p.degCoeff[i];
            p1.setCoefficient(deg, coeff);
            i++;
            j++;
        }
        while(i < this->capacity) {
            p1.setCoefficient(i, this->degCoeff[i]);
            i++;
        }
        while(j < p.capacity) {
            p1.setCoefficient(j, p.degCoeff[j]);
            j++;
        }
        return p1;
    }

// Overload "-" operator
    Polynomial operator - (Polynomial const &p) {
        Polynomial p1;
        int i=0, j=0;
        while(i<this->capacity && j<p.capacity) {
            int deg = i;
            int coeff = this->degCoeff[i] - p.degCoeff[j];
            p1.setCoefficient(deg, coeff);
            i++;
            j++;
        }
        while(i < this->capacity) {
            p1.setCoefficient(i, this->degCoeff[i]);
            i++;
        }
        while(j < p.capacity) {
            p1.setCoefficient(j, (-1)*(p.degCoeff[j]) );
            j++;
        }
        return p1;
    }

    int getCoefficient(int degree) {
        if (degree >= this->capacity) {
            return 0;
        }
        else {
            return this->degCoeff[degree];
        }
    }
// Overload "*" operator
    Polynomial operator * (Polynomial const &p) {
        Polynomial p1;
        for (int i=0; i<this->capacity; i++) {
            for (int j=0; j<p.capacity; j++) {
                int deg = i+j;
                int coeff = p1.getCoefficient(deg) + (this->degCoeff[i] * p.degCoeff[j]);
                p1.setCoefficient(deg, coeff);
            }
        }
        return p1;
    }

// Overload "=" operator (Copy assignment operator)
    void operator = (Polynomial const &p) {
        delete []this->degCoeff;
        this->degCoeff = new int[p.capacity];
        for (int i=0; i<p.capacity; i++) {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

// print
    void print() {
        for (int i=0; i<this->capacity; i++) {
            if (this->degCoeff[i] != 0) {
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};



int main() {
    int count1, count2, choice;
// Polynomial first  
    cin >> count1;
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    for (int i=0; i<count1; i++) {
        cin >> degree1[i];
    }
    for (int i=0; i<count1; i++) {
        cin >> coeff1[i];
    }
    Polynomial first;
    for (int i=0; i<count1; i++) {
        first.setCoefficient(degree1[i], coeff1[i]);
    }
// Polynomial second
    cin >> count2;
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    for (int i=0; i<count2; i++) {
        cin >> degree2[i];
    }
    for (int i=0; i<count2; i++) {
        cin >> coeff2[i];
    }
    Polynomial second;
    for (int i=0; i<count2; i++) {
        second.setCoefficient(degree2[i], coeff2[i]);
    }
// Switch case
    cin >> choice;
    switch(choice) {
        case 1:    // Add
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
        case 2:    // Substract
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
        case 3:    // Multiply
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4:    // Copy constructor
        {
            Polynomial third(first);
            if (third.degCoeff == first.degCoeff) {
                cout << "False" << endl;
            }
            else {
                cout << "True" << endl;
            }
            break;
        }
        case 5:    // Copy assignment operator
        {
            Polynomial fourth(first);
            if (fourth.degCoeff == first.degCoeff) {
                cout << "False" << endl;
            }
            else {
                cout << "True" << endl;
            }
            break;
        }
    }
    return 0;
}