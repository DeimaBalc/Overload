#include <string>
#include <iostream>
#include <stdexcept> 

/////////////-IŠIMTYS-/////////////
class VekDalybosIsNulioIsimtis : public std::runtime_error {
    private:
         std::string eilute;
         std::string failas;
    
    public:
        VekDalybosIsNulioIsimtis(int  eilute, const char* failas) :
            std::runtime_error("Dalyba iš nulio: "), eilute(std::to_string(eilute)), failas(failas){}
        
        std::string koksFailas(){
           return failas;
        }    
         
        std::string kelintaEilute(){
           return std::string(eilute);
        }    
    
 };

class MatDeterminantasNulis : public std::invalid_argument {
    private:
        std::string eilute;
        std::string failas;
    public:
        MatDeterminantasNulis(int eilute, const char* failas) 
            : std::invalid_argument("Matrica neturi inversijos (determinantas = 0)"), eilute(std::to_string(eilute)), failas(failas){}
        
        std::string koksFailas(){
            return failas;
        }    
            
        std::string kelintaEilute(){
            return std::string(eilute);
        }  
};



class MatIndexOutOfBounds : public std::out_of_range {
    private:
    std::string eilute;
    std::string failas;
public:
    MatIndexOutOfBounds(int eilute, const char* failas) 
        : std::out_of_range("Netinkami indeksai i,j <=2"), eilute(std::to_string(eilute)), failas(failas){}
    
    std::string koksFailas(){
        return failas;
    }    
        
    std::string kelintaEilute(){
        return std::string(eilute);
    }  
};
//////////////////////////////////

class Mat3x3;

class Vec3D {
private:
    double v1;
    double v2;
    double v3;
 
public:
    Vec3D(double v1 = 0, double v2 = 0, double v3 = 0) : v1(v1), v2(v2), v3(v3) { } //Konstruktorius su parametrais
    Vec3D(const Vec3D& kitas) : v1(kitas.v1), v2(kitas.v2), v3(kitas.v3) { } //Kopijos konstruktorius

    double getV1() const { return v1; }
    double getV2() const { return v2; } //Getteriai
    double getV3() const { return v3; }

    std::string to_string() const; //Išvestis

    Vec3D operator+(const Vec3D& c2) const; //Vektoriaus sudetis
    Vec3D operator-(const Vec3D& c2) const; //Vektoriaus atimtis
    Vec3D operator-() const; //Vektoriaus neigimas
    double operator^(const Vec3D& v) const; //Skaliarinė sandauga

    Vec3D operator%(const Vec3D& v) const; //Vektorinė sandauga

    Vec3D& operator%= (const Vec3D& v);

    

    bool operator== (const Vec3D& v) const;
    bool operator!= (const Vec3D& v) const;
    
    friend Vec3D operator*(double num, const Vec3D& v); //Daugyba iš skaičiaus
    friend Vec3D operator*(const Vec3D& v, double num); //Daugyba iš skaičiaus
    friend Vec3D operator*(const Vec3D& v, const Vec3D& u); //Vektroius iš vektoriaus
    friend Vec3D operator*(const Vec3D& v, const Mat3x3& m); //Vektoriaus iš matricos
    friend std::ostream& operator<<(std::ostream& os, const Vec3D& v); //Išvestis
    friend std::istream& operator>>(std::istream& is, Vec3D& v); //ivestis

    Vec3D operator/(double k) const; //Dalyba iš skaičiaus
    Vec3D operator++() ; //+1
    Vec3D operator++(int); //postfixinis

    Vec3D operator--() ; //+1
    Vec3D operator--(int); //postfixinis

    Vec3D& operator=(const Vec3D& kitas) ;
};

class Mat3x3 {
private:
    Vec3D eil1;
    Vec3D eil2;
    Vec3D eil3;

public:
    Mat3x3(const Vec3D& e1 = Vec3D(), 
           const Vec3D& e2 = Vec3D(),  //constructor su parametrais
           const Vec3D& e3 = Vec3D()) 
        : eil1(e1), eil2(e2), eil3(e3) {}

    const Vec3D& getEil1() const { return eil1; }
    const Vec3D& getEil2() const { return eil2; }
    const Vec3D& getEil3() const { return eil3; }

//kokiu negalima perkrauti? - . , .*, ::. ?:, sizeof, typeid, #, ##

    Mat3x3& operator=(const Mat3x3& kitas); //priskyrimas
    Mat3x3 operator+(const Mat3x3& m) const; //sudetis

    Mat3x3& operator+=(const Mat3x3& m);
    Mat3x3& operator-=(const Mat3x3& m);

    Mat3x3 operator-(const Mat3x3& m) const;//atimtis
    Mat3x3 operator*(const Mat3x3& m) const; //daugyba

    Mat3x3& operator*=(const Mat3x3& m);

    Vec3D operator*(const Vec3D& v) const; //daugyba is vektoriaus

    Mat3x3& operator*=(const Vec3D& v);

    Mat3x3 operator*(double k) const;

    Mat3x3& operator*=(double k);

    Mat3x3 operator/(double k) const; //dalyba is skaičiaus
    
    Mat3x3& operator/=(double k);

    Mat3x3 operator/(const Mat3x3 m ) const;

    Mat3x3& operator/=(const Mat3x3 m);

    


    Mat3x3 operator^(int n);

    Mat3x3& operator^=(int n);
    Mat3x3 operator!() const;

    double operator~() const;

    Mat3x3 transpos();

    

    Mat3x3 operator++() const;

    Mat3x3 operator++(int) const;

    Mat3x3 operator--() const;

    Mat3x3 operator--(int) const;

    double sum() const;

    
    bool operator<(const Mat3x3& m) const;

    bool operator>(const Mat3x3& m) const;
    bool operator<=(const Mat3x3& m) const;
    bool operator>=(const Mat3x3& m) const;


    bool operator==(const Mat3x3& m) const;
    
    bool operator!=(const Mat3x3& m) const;

    
    //Dar galima perkrauti |, &, &&, ||, <<, >>, <<=, >>=, &=, |=, []
    
    friend std::istream& operator>>(std::istream& is, Mat3x3& m); //ivestis

    std::string toString() const;  // semicolon added
    Mat3x3 operator-() const;      // semicolon added
    double operator()(int i, int j) const;//matricos elementas
};