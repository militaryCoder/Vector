#include <cmath>

#include "Vector.hpp"
#include "Coordinate.hpp"

void Vector::add(const Vector &another) {
    m_coordinate += another.getCoordinate();
}

void Vector::setCoordinate(const Coordinate<double> &C) {
    m_coordinate = C;
}

Coordinate<double> Vector::getCoordinate() const {
    return m_coordinate;
}

void Vector::setLength(const double &val) {
    m_length = val;
}

double Vector::getLength() const {
    return m_length;
}

Vector &Vector::operator=(const Vector &other) {
    this->m_length = other.getLength();
    this->m_coordinate = other.getCoordinate;

    return *this;
}