#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
    protected:
        float radius;
};

class Circle:public Shape
{
    public:

        Circle()
        {

        }
        Circle(float radius)
        {
            this->radius=radius;
        }

        float calculateArea()
        {
            return M_PI*radius*radius;
        }

        float getRadius()
        {
            return radius;
        }
};

int main()
{
    int choice,cir_choice,t=0;
    float radius;
    Circle cir[10];
    Circle *cir_dym = new Circle[10];
    start:
    cout << "Please Enter your choice" << endl;
    cout << "1. Input Data of new Circle" << endl <<
            "2. Caculate Radius of a Particular Circle" << endl <<
            "3. Exit"<< endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
        {
            cout << "Enter Radius of Circle" << endl;
            cin >> radius;
            cir[t++]=Circle(radius);
            goto start;
        }
        case 2:
        {
            cout << "Select Circle with required Dimensions" << endl;
            for(int i=0;i<t;i++)
            {
                cout << "Circle " << i+1 << " Radius " << cir[i].getRadius() << endl;
            }
            cout << "Please enter Circle number" << endl;
            cin >> cir_choice;
            cout << "Area is " << cir[--cir_choice].calculateArea()  << endl;
            goto start;
        }
        case 3:
        {
            break;
        }
    }
    return 0;
}
