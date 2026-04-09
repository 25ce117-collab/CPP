#include<iostream>
#include<cmath>
using namespace std;

class Point
{
    int x,y;

public:
    Point(int a=0,int b=0)
    {
        x=a;
        y=b;
    }

    Point* move(int dx,int dy)
    {
        x+=dx;
        y+=dy;
        return this;
    }

    void show()
    {
        cout<<x<<" "<<y<<endl;
    }

    double dist()
    {
        return sqrt(x*x+y*y);
    }

    void setPos(int a,int b)
    {
        x=a;
        y=b;
    }

    void reset()
    {
        x=0;
        y=0;
    }
};

void change(Point* p)
{
    p->move(5,5);
}

int main()
{
    Point p(1,1);

    p.move(2,3)->move(-1,2)->move(1,1);
    p.show();

    cout<<p.dist()<<endl;

    change(&p);
    p.show();

    p.reset();
    p.show();

    return 0;
}
