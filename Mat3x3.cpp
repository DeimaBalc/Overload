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
    if (k == 0.0) 
	    throw VekDalybosIsNulioIsimtis(__LINE__, __FILE__);
    return Vec3D(v1 / k, v2 / k, v3 / k);
}

Vec3D Vec3D::operator++() {
    ++v1; ++v2; ++v3;
    return *this;
}
    
Vec3D Vec3D::operator++(int) {
    Vec3D temp(*this);
    operator++();
    return temp;
}

Vec3D Vec3D::operator--() {
    --v1; --v2; --v3;
    return *this;
}
    
Vec3D Vec3D::operator--(int) {
    Vec3D temp(*this);
    operator--();
    return temp;
}
    
std::ostream& operator<<(std::ostream& os, const Vec3D& v) {
    return os << v.to_string();
}

std::istream& operator>>(std::istream& is, Vec3D& v) { 
    double v1, v2, v3;
    
    std::cout << "Iveskite vektoriaus koordinates (x, y, z): ";

    is >> v1 >> v2 >> v3;

    v = Vec3D(v1, v2, v3);
    
    return is;
}

std::istream& operator>>(std::istream& is, Mat3x3& m) { 
    double x, y, z;
    Vec3D v1, v2, v3;
    
    std::cout << "Iveskite 1 vektoriaus koordinates (x, y, z): ";

    is >> x >> y >> z;
    v1 = Vec3D(x, y, z);

    std::cout << "Iveskite 2 vektoriaus koordinates (x, y, z): ";

    is >> x >> y >> z;
    v2 = Vec3D(x, y, z);

    std::cout << "Iveskite 3 vektoriaus koordinates (x, y, z): ";

    is >> x >> y >> z;
    v3 = Vec3D(x, y, z);

    m = Mat3x3(v1, v2, v3);
    
    return is;
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
    if (k == 0.0) 
	    throw VekDalybosIsNulioIsimtis(__LINE__, __FILE__);
    return Mat3x3(eil1 * 1/k, eil2 * 1/k, eil3* 1/k);
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
    
    if (i < 0 || i > 2 || j < 0 || j > 2) { 
	    throw MatIndexOutOfBounds(__LINE__, __FILE__);
    }
    if (i == 0 && j == 0) return eil1.getV1();
    if (i == 0 && j == 1) return eil1.getV2();
    if (i == 0 && j == 2) return eil1.getV3();
    if (i == 1 && j == 0) return eil2.getV1();
    if (i == 1 && j == 1) return eil2.getV2();
    if (i == 1 && j == 2) return eil2.getV3();
    if (i == 2 && j == 0) return eil3.getV1();
    if (i == 2 && j == 1) return eil3.getV2();
    if (i == 2 && j == 2) return eil3.getV3();
    
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

//PAPILDYMAS

Vec3D Vec3D::operator%(const Vec3D& v) const {
    return Vec3D(
        v2 * v.v3 - v3 * v.v2,  // i 
        v3 * v.v1 - v1 * v.v3,  // j
        v1 * v.v2 - v2 * v.v1   // k 
    );
}

Vec3D& Vec3D::operator%= (const Vec3D& v) { 
    *this = *this % v;
    return *this;
} 

bool Vec3D::operator== (const Vec3D& v) const { //==
     if(v1 == v.v1 && v2 == v.v2 && v3 == v.v3) { return true; } else { return false; };
}

bool Vec3D::operator!= (const Vec3D& v) const { //!=
     if(v1 != v.v1 && v2 != v.v2 && v3 != v.v3) { return true; } else { return false; };
}

Mat3x3& Mat3x3::operator+=(const Mat3x3& m) {
    *this = *this + m;
    return *this;
}//matricos sudetis

Mat3x3& Mat3x3::operator-=(const Mat3x3& m) {
    *this = *this - m;
    return *this;
}//matricos atimtis

Mat3x3& Mat3x3::operator*=(const Mat3x3& m) {

    *this = *this * m;
    return *this;

}//matricos sandauga

Mat3x3& Mat3x3::operator*=(const Vec3D& v) {

    *this = *this * v;
    return *this;

}//matricos ir vektoriaussandauga 

Mat3x3& Mat3x3::operator*=(double k) {

    *this = *this * k;
    return *this;

}//matricos ir skaiciaus sandauga


Mat3x3& Mat3x3::operator/=(double k) {
    *this = *this / k;
    return *this;
}//matricos dalyba is skaičiaus

Mat3x3 Mat3x3::operator/(const Mat3x3 m ) const{

        return (*this) * !m;
}

Mat3x3& Mat3x3::operator/=(const Mat3x3 m) {
    *this = *this / m;
    return *this;
}//matricos dalyba is skaičiaus

Mat3x3 Mat3x3::operator^(int n) {
        
    Mat3x3 temp = *this; //laikinas kintamasis
    //if (n < 0)
    if (n == 0) return Mat3x3(Vec3D(1, 0, 0), Vec3D(0, 1, 0), Vec3D(0, 0, 1)); 
    for(int i = 1; i< n; i++){
        
        temp *= *this;

        std::cout << "Mat3x3: " << temp.toString()<< std::endl;
    }

    return temp;

}//Kelimas laipsniu

Mat3x3& Mat3x3::operator^=(int n) {
    *this = *this ^ n;
    return *this;
}// kelimas laipsniu

Mat3x3 Mat3x3::operator!() const {
    //determinantas
    double det = ~(*this);
    
    if (det == 0) {
	    throw MatDeterminantasNulis(__LINE__, __FILE__);
    }

    //adjunktai
    double c11 = (*this)(1,1) * (*this)(2,2) - (*this)(1,2) * (*this)(2,1);
    double c12 = -((*this)(1,0) * (*this)(2,2) - (*this)(1,2) * (*this)(2,0));
    double c13 = (*this)(1,0) * (*this)(2,1) - (*this)(1,1) * (*this)(2,0);
    
    double c21 = -((*this)(0,1) * (*this)(2,2) - (*this)(0,2) * (*this)(2,1));
    double c22 = (*this)(0,0) * (*this)(2,2) - (*this)(0,2) * (*this)(2,0);
    double c23 = -((*this)(0,0) * (*this)(2,1) - (*this)(0,1) * (*this)(2,0));
    
    double c31 = (*this)(0,1) * (*this)(1,2) - (*this)(0,2) * (*this)(1,1);
    double c32 = -((*this)(0,0) * (*this)(1,2) - (*this)(0,2) * (*this)(1,0));
    double c33 = (*this)(0,0) * (*this)(1,1) - (*this)(0,1) * (*this)(1,0);

    
    return Mat3x3(
        Vec3D(c11/det, c21/det, c31/det),
        Vec3D(c12/det, c22/det, c32/det),
        Vec3D(c13/det, c23/det, c33/det)
    );
}

double Mat3x3::operator~() const{

    return (*this)(0,0) * ((*this)(1,1) * (*this)(2,2) - (*this)(1,2) * (*this)(2,1))
                - (*this)(0,1) * ((*this)(1,0) * (*this)(2,2) - (*this)(1,2) * (*this)(2,0))
                + (*this)(0,2) * ((*this)(1,0) * (*this)(2,1) - (*this)(1,1) * (*this)(2,0));
}//determinantas


Mat3x3 Mat3x3::transpos()  {
    return Mat3x3(
        Vec3D((*this)(0,0), (*this)(1,0), (*this)(2,0)),  // first row becomes first column
        Vec3D((*this)(0,1), (*this)(1,1), (*this)(2,1)),  // second row becomes second column
        Vec3D((*this)(0,2), (*this)(1,2), (*this)(2,2))   // third row becomes third column
    );
}



Mat3x3 Mat3x3::operator++() const { //++
    return Mat3x3(eil1 + 1, eil2 + 1, eil3 + 1);
} //++ skaičius

Mat3x3 Mat3x3::operator++(int) const { //++ skaičius
    return Mat3x3(eil1 + 1, eil2 + 1, eil3 + 1);
} //++ skaičius 

Mat3x3 Mat3x3::operator--() const { //--
    return Mat3x3(eil1 - 1, eil2 - 1, eil3 - 1);
} //-- skaičius

Mat3x3 Mat3x3::operator--(int) const { //-- skaičius
    return Mat3x3(eil1 - 1, eil2 - 1, eil3 - 1);
} //-- skaičius

double Mat3x3::sum() const {
    return (*this)(0,0) + (*this)(0,1) + (*this)(0,2) +
           (*this)(1,0) + (*this)(1,1) + (*this)(1,2) +
           (*this)(2,0) + (*this)(2,1) + (*this)(2,2);
}


bool Mat3x3::operator<(const Mat3x3& m) const {
    return this->sum() < m.sum();
}

bool Mat3x3::operator>(const Mat3x3& m) const {
    return m < *this;
}

bool Mat3x3::operator<=(const Mat3x3& m) const {
    return !(m < *this);
}

bool Mat3x3::operator>=(const Mat3x3& m) const {
    return !(*this < m);
}


bool Mat3x3::operator==(const Mat3x3& m) const { //==
    if(eil1 == m.eil1 && eil2 == m.eil2 && eil3 == m.eil3) { return true; } else { return false; };
}

bool Mat3x3::operator!=(const Mat3x3& m) const { //!=
    if(eil1 != m.eil1 && eil2 != m.eil2 && eil3 != m.eil3) { return true; } else { return false; };
}

