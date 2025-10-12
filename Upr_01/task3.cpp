#include <iostream>

class Line {
private:
    int len;

public:
    Line(int length) {
        if (length > 0) {
            len = length;
        } else {
            len = 0;
        }

        for (int i = 0; i < len; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    ~Line() {
        for (int i = 0; i < len; ++i) {
            std::cout << "\b \b";
        }
        std::cout << std::endl;
    }
};

int main() {
    int lineLength;

    std::cout << "Enter the desired length for the line: ";
    std::cin >> lineLength;

    std::cout << "Constructor draws the line -> ";

    Line myLine(lineLength);

    return 0;
}