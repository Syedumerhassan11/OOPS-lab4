#include <iostream>
#include <cmath>
using namespace std;

class Circle {
public:
    Circle(double radius) : radius(radius) {}
    double getArea() { return M_PI * radius * radius; }
    double getPerimeter() { return 2 * M_PI * radius; }
private:
    double radius;
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <radius>" << endl;
        return 1;
    }
    double radius = atof(argv[1]);
    Circle circle(radius);
    cout << "Area: " << circle.getArea() << endl;
    cout << "Perimeter: " << circle.getPerimeter() << endl;
    return 0;
}

