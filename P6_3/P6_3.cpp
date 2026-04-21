#include <iostream>
using namespace std;

class Fuel
{
protected:
    string type;
public:
    Fuel()
    {
        type = "Unknown";
    }
    Fuel(string t) : type(t) {}
};

class Brand
{
protected:
    string name;
public:
    Brand()
    {
        name = "Unknown";
    }
    Brand(string n) : name(n) {}
};

class Car : public Fuel, public Brand
{
private:
    string model;
public:
    Car() : Fuel(), Brand()
    {
        model = "Unknown";
    }
    Car(string t, string n, string m) : Fuel(t), Brand(n), model(m) {}
    void displayInfo()
    {
        cout << "Car Model: " << model << endl;
        cout << "Brand: " << name << endl;
        cout << "Fuel Type: " << type << endl;
    }

};

int main()
{
    int choice,t=0;
    Car car[10];
start:
    cout << "Enter your choice" << endl;
    cout << "1. Input Car Details" << endl;
    cout << "2. Display Car Details" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
    case 1:
    {
        cout << "Enter fuel type, brand name and model name" << endl;
        string fuelType, brandName, modelName;
        cin >> fuelType >> brandName >> modelName;
        car[t++]= Car(fuelType, brandName, modelName);
        goto start;
    }
    case 2:
    {
        for(int i=0; i<t; i++)
        {
            car[i].displayInfo();
            cout << endl;
        }
        goto start;
    }
    case 3:
    {
        cout << "Exiting..." << endl;
        break;
    }
    default:
    {
        cout << "Invalid choice. Please try again." << endl;
        goto start;
    }
    }
    return 0;
}
