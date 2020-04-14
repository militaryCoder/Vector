#pragma once

#include <iostream>

template<typename T>
class Coordinate {
    public:
    Coordinate() = default;
    Coordinate(T x, T y, T z)
    : m_x(x), m_y(y), m_z(z) {}
    Coordinate(const Coordinate &c) = default;

    T getX() const { return m_x; }
    T getY() const { return m_y; }
    T getZ() const { return m_z; }
    
    const Coordinate &operator+=(const Coordinate &R) {
        this->m_x += R.getX();
        this->m_y += R.getY();
        this->m_z += R.getZ();

        return *this;
    }

    template <typename U>
    const Coordinate &operator+=(const Coordinate<U> &R) {
        this->m_x += R.getX();
        this->m_y += R.getY();
        this->m_z += R.getZ();

        return *this;
    }
    
    const Coordinate &operator-=(const Coordinate &R) {
        this->m_x -= R.getX();
        this->m_y -= R.getY();
        this->m_z -= R.getZ();

        return *this;
    }

    template <typename U>
    const Coordinate &operator-=(const Coordinate<U> &R) {
        this->m_x -= R.getX();
        this->m_y -= R.getY();
        this->m_z -= R.getZ();

        return *this;
    }

    template <typename U>
    const Coordinate &operator*=(const U &val) {
        this->m_x *= val;
        this->m_y *= val;
        this->m_z *= val;

        return *this;
    }
    
    template <typename U>
    friend Coordinate<U> operator+(const Coordinate<U> &c1, const Coordinate<U> &c2);
    template <typename U>
    friend Coordinate<U> operator-(const Coordinate<U> &c1, const Coordinate<U> &c2);
    template <typename U, typename K>
    friend Coordinate<U> operator-(const Coordinate<U> &c1, const Coordinate<K> &c2);

    template <typename U>
    friend std::ostream &operator<<(std::ostream &out, const Coordinate<U> &C);

    private:
    T m_x;
    T m_y;
    T m_z;
};


template <typename T>
std::ostream &operator<<(std::ostream &out, const Coordinate<T> &C) {
    return out << "[" << C.m_x << "; " << C.m_y << "; " << C.m_z << "]";
}

template <typename T>
Coordinate<T> operator+(const Coordinate<T> &c1, const Coordinate<T> &c2) {
    Coordinate<T> result(0, 0, 0);
    result += c1;
    result += c2;

    return result;
}

template <typename T>
Coordinate<T> operator-(const Coordinate<T> &c1, const Coordinate<T> &c2) {
    Coordinate<T> result = c1;
    result -= c2;

    return result;
}

template <typename T, typename U>
Coordinate<T> operator-(const Coordinate<T> &c1, const Coordinate<U> &c2) {
    Coordinate<T> result = c1;
    result -= c2;

    return result;
}