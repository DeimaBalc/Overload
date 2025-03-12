#include <string>
#include <iostream>

class Mat3x3;

class Vec3D {
private:
    double v1;
    double v2;
    double v3;
 
public:
    Vec3D(double v1 = 0, double v2 = 0, double v3 = 0) : v1(v1), v2(v2), v3(v3) { }
    Vec3D(const Vec3D& kitas) : v1(kitas.v1), v2(kitas.v2), v3(kitas.v3) { }

    double getV1() const { return v1; }
    double getV2() const { return v2; }
    double getV3() const { return v3; }

    std::string to_string() const;

    Vec3D operator+(const Vec3D& c2) const;
    Vec3D operator-(const Vec3D& c2) const;
    Vec3D operator-() const;
    double operator^(const Vec3D& v) const;
    
    friend Vec3D operator*(double num, const Vec3D& v);
    friend Vec3D operator*(const Vec3D& v, double num);
    friend Vec3D operator*(const Vec3D& v, const Vec3D& u);
    friend Vec3D operator*(const Vec3D& v, const Mat3x3& m);
    friend std::ostream& operator<<(std::ostream& os, const Vec3D& v);

    Vec3D operator/(double k) const;
    Vec3D& operator++() ;
    Vec3D operator++(int);
    Vec3D& operator=(const Vec3D& kitas) ;
};

class Mat3x3 {
private:
    Vec3D eil1;
    Vec3D eil2;
    Vec3D eil3;

public:
    Mat3x3(const Vec3D& e1 = Vec3D(), 
           const Vec3D& e2 = Vec3D(), 
           const Vec3D& e3 = Vec3D()) 
        : eil1(e1), eil2(e2), eil3(e3) {}

    const Vec3D& getEil1() const { return eil1; }
    const Vec3D& getEil2() const { return eil2; }
    const Vec3D& getEil3() const { return eil3; }

    Mat3x3& operator=(const Mat3x3& kitas);
    Mat3x3 operator+(const Mat3x3& m) const;
    Mat3x3 operator-(const Mat3x3& m) const;
    Mat3x3 operator*(const Mat3x3& m) const;
    Vec3D operator*(const Vec3D& v) const;
    Mat3x3 operator*(double k) const;
    Mat3x3 operator/(double k) const;
    std::string toString() const;
    Mat3x3 operator-() const;

    double operator()(int i, int j) const;
};