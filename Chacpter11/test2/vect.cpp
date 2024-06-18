
//
// Created by dell on 2024/6/11.
//
#include "vect.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);


    void Vector::set_x(double n1, double n2) {
        x = n1 * cos(n2);
    }

    void Vector::set_y(double n1, double n2) {
        y = n1 * sin(n2);
    }


    Vector::Vector() {
        x = y = 0.0;
        mode = RECT;
    }

    Vector::Vector(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        } else if (form == POL)
        {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        } else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }

    void Vector::reset(double n1, double n2, Mode form) {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
        } else if (form == POL)
        {
            set_x(n1, n2 / Rad_to_deg);
            set_y(n1, n2 / Rad_to_deg);
        } else
        {
            cout << "Incorrect 3rd argument to Vector() -- ";
            cout << "vector set to 0\n";
            x = y = 0.0;
            mode = RECT;
        }
    }
    Vector::~Vector(){

    }

    double Vector::Magval() const {
        return sqrt(x * x + y * y);
    }

    double Vector::Angval() const {

        if (x == 0.0 && y == 0.0)
            return 0.0;
        else
            return atan2(y, x);

    }

    void Vector::polar_mode() {
        mode = POL;
    }

    void Vector::rect_mode() {
        mode = RECT;
    }

    Vector Vector::operator+(const Vector &b) const {
        return Vector(x + b.x, y + b.y);
    }

    Vector Vector::operator-(const Vector &b) const {
        return Vector(x - b.x, y - b.y);
    }

    Vector Vector::operator-() const {
        return Vector(-x, -y);
    }

    Vector Vector::operator*(double n) const {
        return Vector(n * x, n * y);
    }

    Vector operator*(double  n, const Vector & a){
        return a * n;
    }

    std::ostream & operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.Magval() << ", "
               << v.Angval() * Rad_to_deg << ")";
        }
        else
            os << "Vector object mode is invalid";
        return os;
    }

}