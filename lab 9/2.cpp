#include <iostream>
#include <string>
using namespace std;

class Smartdevice {
public:
    virtual void turnon() = 0;
    virtual void turnoff() = 0;
    virtual bool getstatus() = 0;
    virtual ~Smartdevice() {}
};

class Lightbulb : public Smartdevice {
    bool ison;
    int brightness;

public:
    Lightbulb() : ison(false), brightness(0) {}

    void turnon() override {
        ison = true;
        brightness = 100;
    }

    void turnoff() override {
        ison = false;
        brightness = 0;
    }

    bool getstatus() override {
        return ison;
    }
};

class Thermostat : public Smartdevice {
    bool ison;
    double temperature;

public:
    Thermostat() : ison(false), temperature(22.0) {}

    void turnon() override {
        ison = true;
        temperature = 21.5;
    }

    void turnoff() override {
        ison = false;
    }

    bool getstatus() override {
        return ison;
    }
};

int main() {
    Lightbulb bulb;
    Thermostat thermostat;

    Smartdevice* devices[] = { &bulb, &thermostat };

    for (int i = 0; i < 2; i++) {
        devices[i]->turnon();
        cout << (devices[i]->getstatus() ? "Device is on" : "Device is off") << endl;
    }

    cout << endl << "Turning off devices..." << endl << endl;

    for (int i = 0; i < 2; i++) {
        devices[i]->turnoff();
        cout << (devices[i]->getstatus() ? "Device is on" : "Device is off") << endl;
    }

    return 0;
}
