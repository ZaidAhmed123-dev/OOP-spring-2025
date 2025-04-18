#include <iostream>
#include <memory>

using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() const = 0;
    virtual ~Activity() = default;
};

class Running : public Activity {
private:
    double distance;
    double time;
public:
    Running(double d, double t) : distance(d), time(t) {}

    double calculateCaloriesBurned() const override {
        return distance * 60.0;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;
public:
    Cycling(double s, double t) : speed(s), time(t) {}

    double calculateCaloriesBurned() const override {
        return 8.0 * 70.0 * time;
    }
};

int main() {
    shared_ptr<Activity> run = make_shared<Running>(5.0, 30);
    shared_ptr<Activity> cycle = make_shared<Cycling>(20.0, 1.0);

    cout << "Calories burned (Running): " << run->calculateCaloriesBurned() << " kcal\n";
    cout << "Calories burned (Cycling): " << cycle->calculateCaloriesBurned() << " kcal\n";

    return 0;
}
