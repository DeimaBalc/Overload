#include <iostream>
#include <cassert>
#include "Mat3x3.h"

void testuotiVisusOperatorius() {
    std::cout << "\n=== Visų Operatorių Testavimas ===\n";
    
    // Pradinės matricos
    Mat3x3 m1(Vec3D(1,2,3), Vec3D(4,5,6), Vec3D(7,8,9));
    Mat3x3 m2(Vec3D(9,8,7), Vec3D(6,5,4), Vec3D(3,2,1));
    Mat3x3 temp;

    std::cout << "Pradinės matricos:\n" << m1.toString() << "\n" << m2.toString() << std::endl;

    // Priskyrimo operatoriai
    std::cout << "\n--- Priskyrimo operatoriai ---\n";
    temp = m1;
    std::cout << "m = m1:\n" << temp.toString() << std::endl;
    
    temp += m2;
    std::cout << "m += m2:\n" << temp.toString() << std::endl;
    
    temp -= m2;
    std::cout << "m -= m2:\n" << temp.toString() << std::endl;
    
    // Aritmetiniai operatoriai
    std::cout << "\n--- Aritmetiniai operatoriai ---\n";
    std::cout << "m1 + m2:\n" << (m1 + m2).toString() << std::endl;
    std::cout << "m1 - m2:\n" << (m1 - m2).toString() << std::endl;
    std::cout << "m1 * m2:\n" << (m1 * m2).toString() << std::endl;
    
    // Skaliarinės operacijos
    std::cout << "\n--- Skaliarinės operacijos ---\n";
    std::cout << "m1 * 2:\n" << (m1 * 2.0).toString() << std::endl;
    
    try {
        std::cout << "m1 / 2:\n" << (m1 / 2.0).toString() << std::endl;
        std::cout << "m1 / 0:\n" << (m1 / 0.0).toString() << std::endl;
    } catch (VekDalybosIsNulioIsimtis e) {
        std::cout << "Pagauta išimtis: " << e.what() <<" : failas " << e.koksFailas() <<  
          ", eilute: " << e.kelintaEilute() << std::endl;
    }

    // Specialūs operatoriai
    std::cout << "\n--- Specialūs operatoriai ---\n";
    std::cout << "Determinantas (~m1): " << ~m1 << std::endl;
    
    try {
        std::cout << "Inversija (!m1):\n" << (!m1).toString() << std::endl;
    } catch (MatDeterminantasNulis e) {
        std::cout << "Pagauta išimtis: " << e.what() <<" : failas " << e.koksFailas() <<  
        ", eilute: " << e.kelintaEilute() << std::endl;
    }

    // Prefiksinis/Postfiksinis didinimas/mažinimas
    std::cout << "\n--- Didinimo/Mažinimo operatoriai ---\n";
    std::cout << "++m1:\n" << (++m1).toString() << std::endl;
    std::cout << "m1++:\n" << (m1++).toString() << std::endl;
    std::cout << "--m1:\n" << (--m1).toString() << std::endl;
    std::cout << "m1--:\n" << (m1--).toString() << std::endl;

    // Palyginimo operatoriai
    std::cout << "\n--- Palyginimo operatoriai ---\n";
    std::cout << "m1 < m2: " << (m1 < m2) << std::endl;
    std::cout << "m1 > m2: " << (m1 > m2) << std::endl;
    std::cout << "m1 <= m2: " << (m1 <= m2) << std::endl;
    std::cout << "m1 >= m2: " << (m1 >= m2) << std::endl;
    std::cout << "m1 == m2: " << (m1 == m2) << std::endl;
    std::cout << "m1 != m2: " << (m1 != m2) << std::endl;

    // Išimčių testavimas
    std::cout << "\n--- Išimčių testavimas ---\n";
    try {
        std::cout << "Bandoma pasiekti elementą (3,3): " << m1(3,3) << std::endl;
    } catch (MatIndexOutOfBounds e) {
        std::cout << "Pagauta išimtis: " << e.what() <<" : failas " << e.koksFailas() <<  
          ", eilute: " << e.kelintaEilute() << std::endl;
    }

    // Kėlimas laipsniu
    std::cout << "\n--- Kėlimas laipsniu ---\n";
    std::cout << "m1^2:\n" << (m1 ^ 2).toString() << std::endl;
    
    // Transponavimas
    std::cout << "\n--- Transponavimas ---\n";
    std::cout << "Transponuota m1:\n" << m1.transpos().toString() << std::endl;
}

int main() {
   
    testuotiVisusOperatorius();
    std::cout << "\nVisi testai sėkmingai įvykdyti!\n"; 
    
    /*    try {
        
    } catch (const std::exception& e) {
        std::cerr << "Netikėta klaida: " << e.what() << std::endl;
        return 1;
    }*/
    return 0;
}