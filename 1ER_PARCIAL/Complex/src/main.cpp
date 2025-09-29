#include <iostream>
#include "Complex.hpp"

using namespace std;

int main() {
    // Create complex numbers
    Complex a(Cartesian(2, 3));   // 2 + 3i
    Complex b(Polar(5, 0.9273));  // r=5, theta≈53° -> 3 + 4i

    // Test basic operations with Complex
    Complex sum = a + b;
    Complex diff = a - b;
    Complex prod = a * b;
    Complex quot = a / b;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;

    // Test operations with real numbers
    Complex addReal = a + 2;
    Complex subReal = a - 1.5;
    Complex mulReal = a * 3;
    Complex divReal = a / 2;

    cout << "a + 2 = " << addReal << endl;
    cout << "a - 1.5 = " << subReal << endl;
    cout << "a * 3 = " << mulReal << endl;
    cout << "a / 2 = " << divReal << endl;

    // Test assignment operations
    Complex c(a);
    c += b;
    cout << "c after c += b: " << c << endl;
    c -= b;
    cout << "c after c -= b: " << c << endl;
    c *= b;
    cout << "c after c *= b: " << c << endl;
    c /= b;
    cout << "c after c /= b: " << c << endl;

    // Test polar functions
    cout << "a module: " << a.getModule() << endl;
    cout << "a phase: " << a.getPhase() << endl;

    // Modify polar coordinates
    a.setModule(10);
    a.setPhase(1.0472); // ~60 degrees
    cout << "a after changing module and phase: " << a << endl;

    // Test conjugate
    Complex conjA = a.conjugate();
    cout << "Conjugate of a: " << conjA << endl;

    return 0;
}