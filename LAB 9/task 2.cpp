#include <iostream>
#include <string>
using namespace std;

class SmartDevice {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual string getStatus() = 0;
    virtual ~SmartDevice() {}
};

class LightBulb : public SmartDevice {
private:
    bool isOn;
    int brightness;

public:
    LightBulb() : isOn(false), brightness(0) {}

    void turnOn() override {
        isOn = true;
        brightness = 75;
        cout << "LightBulb is turned ON." << endl;
    }

    void turnOff() override {
        isOn = false;
        brightness = 0;
        cout << "LightBulb is turned OFF." << endl;
    }

    string getStatus() override {
        return "LightBulb is " + string(isOn ? "ON" : "OFF") +
               ", Brightness: " + to_string(brightness) + "%";
    }
};

class Thermostat : public SmartDevice {
private:
    bool isOn;
    double temperature;

public:
    Thermostat() : isOn(false), temperature(20.0) {}

    void turnOn() override {
        isOn = true;
        temperature = 22.0;
        cout << "Thermostat is turned ON." << endl;
    }

    void turnOff() override {
        isOn = false;
        cout << "Thermostat is turned OFF." << endl;
    }

    string getStatus() override {
        return "Thermostat is " + string(isOn ? "ON" : "OFF") +
               ", Temperature: " + (isOn ? to_string(temperature) + "°C" : "N/A");
    }
};

int main() {
    LightBulb bulb;
    Thermostat thermostat;

    bulb.turnOn();
    thermostat.turnOn();

    cout << bulb.getStatus() << endl;
    cout << thermostat.getStatus() << endl;

    bulb.turnOff();
    thermostat.turnOff();

    cout << bulb.getStatus() << endl;
    cout << thermostat.getStatus() << endl;

    return 0;
}
