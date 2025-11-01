#include <iostream>
using namespace std;

class pr2;

class pr1 {
private:
    int printing;

public:
     pr1() { printing = 0; }
     void setPrint(int status) {printing = status;}

     friend bool inuse(pr1 p1, pr2 p2);
};

class pr2 {
private:
    int printing;

public: 
    pr2() { printing = 0; } 
    void setPrint(int status) {printing = status;}

    friend bool inuse(pr1 p1, pr2 p2);
};

bool inuse(pr1 p1_obj, pr2 p2_obj) {
    if (p1_obj.printing !=0 || p2_obj.printing !=0)
    {
        return true;
    }else{
        return false;
    }
}

int main() {
    pr1 user1;
    pr2 user2;

    cout << "Initial state: ";
    if (inuse(user1, user2)) {
        cout << "Printer is IN USE." << endl;
    } else {
        cout << "Printer is FREE." << endl;
    }

    user1.setPrint(1);
    cout << "User 1 starts printing: ";
    if (inuse(user1, user2)) {
        cout << "Printer is IN USE." << endl;
    } else {
        cout << "Printer is FREE." << endl;
    }

    user1.setPrint(0);
    user2.setPrint(1);
    cout << "User 2 starts printing: ";
    if (inuse(user1, user2)) {
        cout << "Printer is IN USE." << endl;
    } else {
        cout << "Printer is FREE." << endl;
    }

    user2.setPrint(0);
    cout << "Final state (both free): ";
    if (inuse(user1, user2)) {
        cout << "Printer is IN USE." << endl;
    } else {
        cout << "Printer is FREE." << endl;
    }

    return 0;
}