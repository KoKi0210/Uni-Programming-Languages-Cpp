#include <iostream> 
using namespace std;    

class truck; 
class car;

double calculateTravelTime(car c, double distance);
double calculateTravelTime(truck t, double distance);


class car {
    int passengers;
    int speed; 
public:
    car(int p, int s) { passengers = p; speed = s; }

    int sp_greater(truck t); 
    
    friend double calculateTravelTime(car c, double distance);
};


class truck {
    int weight;
    int speed; 
public:
    truck(int w, int s) { weight = w; speed = s; }

    friend int car::sp_greater(truck t);
    
    friend double calculateTravelTime(truck t, double distance);
}; 


int car::sp_greater(truck t)
{
    return speed - t.speed; 
}

double calculateTravelTime(car c, double distance) {
    if (c.speed == 0) {
        cout << "Car is not moving, cannot calculate time." << endl;
        return 0; 
    }
    return distance / c.speed;
}

double calculateTravelTime(truck t, double distance) {
    if (t.speed == 0) {
        cout << "Truck is not moving, cannot calculate time." << endl;
        return 0;
    }
    return distance / t.speed;
}

int main()
{
    int t;
    car c1(6, 55), c2(2, 120);
    truck t1(10000, 55), t2(20000, 72);

    cout << "Comparing c1 and t1:\n";
    t = c1.sp_greater(t1); 
    if (t < 0) cout << "Truck is faster.\n";
    else if (t == 0) cout << "Car and truck speed is the same.\n";
    else cout << "Car is faster.\n";

    cout << "\nComparing c2 and t2:\n";
    t = c2.sp_greater(t2); 
    if (t < 0) cout << "Truck is faster.\n";
    else if (t == 0) cout << "Car and truck speed is the same.\n";
    else cout << "Car is faster.\n";
    
    cout << "\n--- Calculating Travel Time ---" << endl;
    double testDistance = 500.0; 
    
    cout << "Calculating time to travel " << testDistance << " km...\n";
    
    double time_c2 = calculateTravelTime(c2, testDistance);
    cout << "Car 2 (at 120 km/h) will take: " << time_c2 << " hours." << endl;
    
    double time_t2 = calculateTravelTime(t2, testDistance);
    cout << "Truck 2 (at 72 km/h) will take: " << time_t2 << " hours." << endl;

    return 0;
} 