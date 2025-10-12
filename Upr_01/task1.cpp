#include <iostream>
#include <iomanip>
#include <string>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    bool setTime(int h, int m, int s) {
        if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
            hours = h;
            minutes = m;
            seconds = s;
            return true;
        }
        return false;
    }

    void print24HourFormat() const {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << std::endl;
    }

    void print12HourFormat() const {
        int displayHours = hours;
        std::string period = "AM";

        if (hours == 0) {
            displayHours = 12;
            period = "AM";
        } else if (hours == 12) {
            displayHours = 12;
            period = "PM";
        } else if (hours > 12) {
            displayHours = hours - 12;
            period = "PM";
        }

        std::cout << std::setfill('0') << std::setw(2) << displayHours << ":"
                  << std::setfill('0') << std::setw(2) << minutes << ":"
                  << std::setfill('0') << std::setw(2) << seconds << " "
                  << period << std::endl;
    }
};

int main() {
    Time myTime;
    int h, m, s;

    std::cout << "Enter time (hour minute second): ";
    std::cin >> h >> m >> s;

    if (myTime.setTime(h, m, s)) {
        std::cout << "\nValid time!\n";
        std::cout << "24-hour format: ";
        myTime.print24HourFormat();
        std::cout << "12-hour format: ";
        myTime.print12HourFormat();
    } else {
        std::cout << "\nInvalid time! Please enter values in the following ranges:\n";
        std::cout << "  Hour: 0-23\n  Minute: 0-59\n  Second: 0-59\n";
    }

    return 0;
}
