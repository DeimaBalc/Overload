#include "Mat3x3.h"
#include <cassert>
#include <iostream>
#include <iomanip>

void testVec3DBasicOperations() {
    std::cout << "\n=== Testing Vec3D Basic Operations ===\n";
    Vec3D v1(1, 2, 3);
    Vec3D v2(4, 5, 6);
    
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    
    Vec3D sum = v1 + v2;
    std::cout << "v1 + v2 = " << sum << std::endl;
    assert(sum.getV1() == 5 && sum.getV2() == 7 && sum.getV3() == 9);
    
    Vec3D diff = v2 - v1;
    std::cout << "v2 - v1 = " << diff << std::endl;
    assert(diff.getV1() == 3 && diff.getV2() == 3 && diff.getV3() == 3);
    
    Vec3D neg = -v1;
    std::cout << "-v1 = " << neg << std::endl;
    assert(neg.getV1() == -1 && neg.getV2() == -2 && neg.getV3() == -3);
    
    double dot = v1 ^ v2;
    std::cout << "v1 ^ v2 = " << dot << std::endl;
    assert(dot == 32);
}

void testVec3DScalarOperations() {
    std::cout << "\n=== Testing Vec3D Scalar Operations ===\n";
    Vec3D v1(1, 2, 3);
    std::cout << "v1: " << v1 << std::endl;
    
    Vec3D scaled = v1 * 2;
    std::cout << "v1 * 2 = " << scaled << std::endl;
    assert(scaled.getV1() == 2 && scaled.getV2() == 4 && scaled.getV3() == 6);
    
    scaled = 2 * v1;
    std::cout << "2 * v1 = " << scaled << std::endl;
    assert(scaled.getV1() == 2 && scaled.getV2() == 4 && scaled.getV3() == 6);
    
    Vec3D divided = v1 / 2;
    std::cout << "v1 / 2 = " << divided << std::endl;
    assert(divided.getV1() == 0.5 && divided.getV2() == 1 && divided.getV3() == 1.5);
}

void testMat3x3Operations() {
    std::cout << "\n=== Testing Mat3x3 Operations ===\n";
    Mat3x3 m1(Vec3D(1,2,3), Vec3D(4,5,6), Vec3D(7,8,9));
    Mat3x3 m2(Vec3D(9,8,7), Vec3D(6,5,4), Vec3D(3,2,1));
    
    std::cout << "Matrix m1:\n" << m1.toString() << std::endl;
    std::cout << "Matrix m2:\n" << m2.toString() << std::endl;
    
    std::cout << "m1 + m2:\n" << (m1 + m2).toString() << std::endl;
    std::cout << "m1 * m2:\n" << (m1 * m2).toString() << std::endl;
    std::cout << "m1 * 2:\n" << (m1 * 2).toString() << std::endl;
}

void testMatrixVectorOperations() {
    std::cout << "\n=== Testing Matrix-Vector Operations ===\n";
    Mat3x3 m1(Vec3D(1,2,3), Vec3D(4,5,6), Vec3D(7,8,9));
    Vec3D v1(1, 2, 3);
    
    std::cout << "Matrix m1:\n" << m1.toString() << std::endl;
    std::cout << "Vector v1: " << v1 << std::endl;
    
    Vec3D mv = m1 * v1;
    std::cout << "m1 * v1 = " << mv << std::endl;
    
    Vec3D vm = v1 * m1;
    std::cout << "v1 * m1 = " << vm << std::endl;
}

void testIncrementOperations() {
    std::cout << "\n=== Testing Increment Operations ===\n";
    Vec3D v1(1, 2, 3);
    std::cout << "Initial v1: " << v1 << std::endl;
    
    ++v1;
    std::cout << "After ++v1: " << v1 << std::endl;
    
    Vec3D v2 = v1++;
    std::cout << "After v1++: " << v1 << std::endl;
    std::cout << "Value of v2 (from v1++): " << v2 << std::endl;
}

int main() {
    try {
        testVec3DBasicOperations();
        testVec3DScalarOperations();
        testMat3x3Operations();
        testMatrixVectorOperations();
        testIncrementOperations();
        
        std::cout << "\nAll tests completed successfully!\n";
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}