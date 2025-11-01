#include <iostream> 
#include <cmath>    

using namespace std;

class Rectangle {
private:
    double width, height;
public:
    Rectangle(); 
    double getArea(); 
    double getArea(double* perimeter); 
    void show(const char* name); 
    ~Rectangle() {
        cout << "\n\nDestructing object Rectangle!\n";
    }
};

Rectangle::Rectangle() {
    do {
        cout << "\n\nEnter two positive values for the sides of the rectangle:\n";
        cin >> width >> height;
    } while (!((width > 0) && (height > 0)));
}

double Rectangle::getArea() {
    double p, s;
    p = 2 * width + 2 * height; 
    s = width * height;
    return s;
}

double Rectangle::getArea(double* p) {
    double pp = 2 * width + 2 * height;
    *p = pp; 
    double s;
    s = width * height;
    return s;
}

void Rectangle::show(const char* name) {
    cout << "Sides of the rectangle " << name << ":\n";
    cout << "width=" << width << ", height=" << height;
}

int main() {
    Rectangle rct1; 
    double p, s;
    rct1.show("rct1");
    cout << "\nThe area of rectangle1 is s=" << rct1.getArea();

    Rectangle rct2; 
    rct2.show("rct2");
    s = rct2.getArea(&p);
    cout << "\nThe area of rectangle2 is s=" << s << ", and the perimeter is p=" << p;

    return 0;
}