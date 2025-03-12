#include <string>
#include <iostream>
#include <cassert>
#include "Mat3x3.h"


std::string Vec3D::to_string() const {
    return "(" + std::to_string(v1) + "," + std::to_string(v2) + "," + std::to_string(v3) + ")";
}

Vec3D Vec3D::operator+(const Vec3D& c2) const {
    return Vec3D(v1 + c2.v1, v2 + c2.v2, v3 + c2.v3);
}

Vec3D Vec3D::operator-(const Vec3D& c2) const {
    return Vec3D(v1 - c2.v1, v2 - c2.v2, v3 - c2.v3);
}

Vec3D Vec3D::operator-() const {
    return Vec3D(-v1, -v2, -v3);
}

double Vec3D::operator^(const Vec3D& v) const {
    return v1 * v.v1 + v2 * v.v2 + v3 * v.v3;
}

Vec3D operator*(double num, const Vec3D& v) {
    return Vec3D(v.v1 * num, v.v2 * num, v.v3 * num);
}

Vec3D operator*(const Vec3D& v, double num) {
    return num * v;
}

Vec3D operator*(const Vec3D& v, const Vec3D& u) {
    return Vec3D(
        v.v2 * u.v3 - v.v3 * u.v2,
        v.v3 * u.v1 - v.v1 * u.v3,
        v.v1 * u.v2 - v.v2 * u.v1
    );
}


Vec3D Vec3D::operator/(double k) const {
    if (k == 0) throw std::invalid_argument("Division by zero");
    return Vec3D(v1 / k, v2 / k, v3 / k);
}

Vec3D& Vec3D::operator++() {
    ++v1; ++v2; ++v3;
    return *this;
}
    
Vec3D Vec3D::operator++(int) {
    Vec3D temp(*this);
    operator++();
    return temp;
}
    
std::ostream& operator<<(std::ostream& os, const Vec3D& v) {
    return os << v.to_string();
}

Vec3D& Vec3D::operator=(const Vec3D& kitas) {
    if (this != &kitas) {
        v1 = kitas.v1;
        v2 = kitas.v2;
        v3 = kitas.v3;
    }
    return *this;
}


Mat3x3& Mat3x3::operator=(const Mat3x3& kitas) {
    if (this != &kitas) {
        eil1 = kitas.eil1;
        eil2 = kitas.eil2;
        eil3 = kitas.eil3;
    }
    return *this;
}

Mat3x3 Mat3x3::operator+(const Mat3x3& m) const {
    return Mat3x3(eil1 + m.eil1, eil2 + m.eil2, eil3 + m.eil3);
}

Mat3x3 Mat3x3::operator-(const Mat3x3& m) const {
    return Mat3x3(eil1 - m.eil1, eil2 - m.eil2, eil3 - m.eil3);
}

Mat3x3 Mat3x3::operator*(const Mat3x3& m) const {
    Vec3D stulp1(m.eil1.getV1(), m.eil2.getV1(), m.eil3.getV1());
    Vec3D stulp2(m.eil1.getV2(), m.eil2.getV2(), m.eil3.getV2());
    Vec3D stulp3(m.eil1.getV3(), m.eil2.getV3(), m.eil3.getV3());

    return Mat3x3(
        Vec3D(eil1 ^ stulp1, eil1 ^ stulp2, eil1 ^ stulp3),
        Vec3D(eil2 ^ stulp1, eil2 ^ stulp2, eil2 ^ stulp3),
        Vec3D(eil3 ^ stulp1, eil3 ^ stulp2, eil3 ^ stulp3)
    );
}

Vec3D Mat3x3::operator*(const Vec3D& v) const {
    return Vec3D(eil1 ^ v, eil2 ^ v, eil3 ^ v);
}

Mat3x3 Mat3x3::operator*(double k) const {
    return Mat3x3(eil1 * k, eil2 * k, eil3 * k);
}

Mat3x3 Mat3x3::operator/(double k) const {
    if (k == 0) throw std::invalid_argument("Division by zero");
    return *this * (1.0/k);
}

std::string Mat3x3::toString() const {
    return "[\n" + eil1.to_string() + "\n" + 
                    eil2.to_string() + "\n" + 
                    eil3.to_string() + "\n]";
}

Mat3x3 Mat3x3::operator-() const {
    return Mat3x3(-eil1, -eil2, -eil3);
}

double Mat3x3::operator()(int i, int j) const {
    if (i == 0 && j == 0) return eil1.getV1();
    if (i == 0 && j == 1) return eil1.getV2();
    if (i == 0 && j == 2) return eil1.getV3();
    if (i == 1 && j == 0) return eil2.getV1();
    if (i == 1 && j == 1) return eil2.getV2();
    if (i == 1 && j == 2) return eil2.getV3();
    if (i == 2 && j == 0) return eil3.getV1();
    if (i == 2 && j == 1) return eil3.getV2();
    if (i == 2 && j == 2) return eil3.getV3();
    throw std::invalid_argument("Invalid index");
}

Vec3D operator*(const Vec3D& v, const Mat3x3& m) {
    Vec3D stulp1(m.getEil1().getV1(), m.getEil2().getV1(), m.getEil3().getV1());
    Vec3D stulp2(m.getEil1().getV2(), m.getEil2().getV2(), m.getEil3().getV2());
    Vec3D stulp3(m.getEil1().getV3(), m.getEil2().getV3(), m.getEil3().getV3());
    
    return Vec3D(
        v ^ stulp1,  
        v ^ stulp2,  
        v ^ stulp3   
    );
}

