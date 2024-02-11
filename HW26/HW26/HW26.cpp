#include "Vector2d.h"

int main()
{
    std::cout << "Testing Vector2d functionality:" << std::endl;

    Vector2d vec1(1.0f, 2.0f);
    Vector2d vec2(3.0f, 4.0f);
    std::cout << "Vector 1: " << vec1 << std::endl;
    std::cout << "Vector 2: " << vec2 << std::endl;

    Vector2d sum = vec1.operator+(vec2);
    Vector2d diff = vec1.operator-(vec2);
    std::cout << "Sum of vectors: " << sum << std::endl;
    std::cout << "Difference of vectors: " << diff << std::endl;

    float dotProduct = vec1.dotProduct(vec2);
    std::cout << "Dot product of vectors: " << dotProduct << std::endl;

    Vector2d negatedVec = vec1.negate();
    std::cout << "Negated vector: " << negatedVec << std::endl;

    float length = vec1();
    std::cout << "Length of vector 1: " << length << std::endl;

    vec1.scale(2.0f, 2.0f);
    std::cout << "Scaled vector 1: " << vec1 << std::endl;

    std::cout << "First component of vector 2: " << vec2[0] << std::endl;
    std::cout << "Second component of vector 2: " << vec2[1] << std::endl;

    Vector2d vec3(1.0f, 2.0f);
    VectorRelativeState relativeState = vec1.getRelativeState(vec3);
    std::cout << "Relative state between vector 1 and vector 3: ";
    switch (relativeState) {
    case VectorRelativeState::Identical:
        std::cout << "Identical";
        break;
    case VectorRelativeState::coDirected:
        std::cout << "Co-directed";
        break;
    case VectorRelativeState::OppositeDirected:
        std::cout << "Opposite-directed";
        break;
    case VectorRelativeState::AcuteAngle:
        std::cout << "Acute angle";
        break;
    case VectorRelativeState::ObtuseAngle:
        std::cout << "Obtuse angle";
        break;
    case VectorRelativeState::RightAngle:
        std::cout << "Right angle";
        break;
    }
    std::cout << std::endl;

    std::cout << "Number of vector objects created: " << Vector2d::getCount() << std::endl;

    std::cout << std::endl << "Testing Vector3d functionality:" << std::endl;
    Vector3d vec3d1(1.0f, 2.0f, 3.0f);
    Vector3d vec3d2(4.0f, 5.0f, 6.0f);
    std::cout << "Vector 1 (3D): (" << vec3d1.x << ", " << vec3d1.y << ", " << vec3d1.z << ")" << std::endl;
    std::cout << "Vector 2 (3D): (" << vec3d2.x << ", " << vec3d2.y << ", " << vec3d2.z << ")" << std::endl;

    Vector3d cross = vec3d1.crossProduct(vec3d2);
    std::cout << "Cross product of vectors: (" << cross.x << ", " << cross.y << ", " << cross.z << ")" << std::endl;

    return 0;
}
