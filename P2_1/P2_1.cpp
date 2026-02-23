#include <iostream>
using namespace std;

class Rectangle
{
    int rectangle_id;
    float length,breadth;
    public:
        void area();
        void perimeter();
        void update_dimensions();
        void display_rectangle();
        void set_rectangle_data(int id);
};

void Rectangle::area()
{
    cout << "Area is: " << length*breadth << endl;
}

void Rectangle::perimeter()
{
    cout << " Perimeter is " <<  2*(length+breadth) << endl;
}

void Rectangle::update_dimensions()
{
    cout << "Enter New Length" << endl;
    cin >> length;
    cout << "Enter New Breadth" << endl;
    cin >> breadth;
}

void Rectangle::display_rectangle()
{
    cout << " Rectangle ID " << rectangle_id << " Length " << length << " Breadth " << breadth << endl;
}

void Rectangle::set_rectangle_data(int id)
{
    rectangle_id = id;
    cout << "Enter Length" << endl;
    cin >> length;
    cout << "Enter Breadth" << endl;
    cin >> breadth;
}

int main()
{
    int choice,i,rect_no_input,t=0;
    Rectangle rect[10];
    menu:
    cout << "Welcome!" << endl
         << "1. Add Rectangle" << endl
         << "2. Change Rectangle Dimensions" << endl
         << "3. Display Rectangles" << endl
         << "4. Calculate Area" << endl
         << "5. Calculate Perimeter" << endl
         << "6. Exit" << endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            rect[t].set_rectangle_data(t);
            t++;
            goto menu;
        case 2:
            cout << "Please Enter Your Rectangle ID" << endl;
            cin >> rect_no_input;
            rect[rect_no_input].update_dimensions();
            goto menu;
        case 3:
            for(i=0;i<t;i++)
            {
                rect[i].display_rectangle();
            }
            goto menu;
        case 4:
            cout << "Please Enter Your Rectangle ID" << endl;
            cin >> rect_no_input;
            rect[rect_no_input].area();
            goto menu;
        case 5:
            cout << "Please Enter Your Rectangle ID" << endl;
            cin >> rect_no_input;
            rect[rect_no_input].perimeter();
            goto menu;
        case 6:
            break;
        default:
            cout << "Invalid Choice, Please try again!" << endl;
            goto menu;
    }
    return 0;
}
