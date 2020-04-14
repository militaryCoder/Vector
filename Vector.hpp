#pragma once

#include <cmath>

#include "Coordinate.hpp"

class Vector {
    public:
    Vector() {}
    Vector(double x, double y, double z, double l) {
        m_coordinate.x = x;
        m_coordinate.y = y;
        m_coordinate.z = z;
        m_length = l;
    }
    Vector(const Coordinate<double> &c, const double &l) : m_coordinate(c), m_length(l) {}
    Vector(const Vector &rv) = default;

    Vector &operator=(const Vector &other);
    
    template <typename T>
    const Vector &operator*=(const T &val);

    void add(const Vector &another);

    void setCoordinate(const Coordinate<double> &C);
    Coordinate<double> getCoordinate() const;

    void setLength(const double &val);
    double getLength() const;

    private:
    double m_length;
    Coordinate<double> m_coordinate;
};


template <typename T>
const Vector &Vector::operator*=(const T &val) {
    this->m_length *= val;
    this->m_coordinate *= val;

    return *this;
}

template <typename T>
Vector operator*(const Vector &left, const T &right) {
    Vector newV = left;
    newV.m_length *= std::abs(right);
    newV.m_coordinate *= right;

    return newV;
}