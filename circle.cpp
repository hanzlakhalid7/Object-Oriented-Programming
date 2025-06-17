#include <iostream>
#include <math.h>

using namespace std;

class Circle
{
private:
    int x, y;
    float radius;
    static double pi;

public:
    // setters for the circle adt

    void setX(int x)
    {
        this->x = x >= -50 && x <= 50 ? x : 0;
    }

    void setY(int y)
    {
        this->y = y >= -50 && y <= 50 ? y : 0;
    }

    void setRadius(float radius)
    {
        this->radius = radius >= 1 && radius <= 10 ? radius : 5;
    }

    // getters for the circle adt

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    float getRadius()
    {
        return radius;
    }

    static double getPi()
    {
        return Circle::pi;
    }
    // constructors of circle adt

    Circle()
    {
        setX(x);
        setY(y);
        setRadius(radius);
    }

    Circle(int x, int y, float radius)
    {
        setX(x);
        setY(y);
        setRadius(radius);
    }

    Circle(int x, int y)
    {
        setX(x);
        setY(y);
        setRadius(radius);
    }

    Circle(int x, float radius)
    {
        setX(x);
        setY(y);
        setRadius(radius);
    }

    Circle(const Circle &obj)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    // destructors of circle adt

    ~Circle()
    {
        cout << "Destructors is executed!!!....." << endl;
    }

    // member function for set values in private data member

    void setCircle(int x, int y, float radius)
    {
        setX(x);
        setY(y);
        setRadius(radius);
    }

    // member function for set values in private data member

    void getCircle()
    {
        cout << "Enter x component : ";
        cin >> x;
        cout << "Enter y component : ";
        cin >> y;
        cout << "Enter radius : ";
        cin >> radius;
        setCircle(x, y, radius);
    }

    // member function for display content on console

    void putCircle()
    {
        cout << "x component is : " << x << endl;
        cout << "y component is : " << y << endl;
        cout << "radius component is : " << radius << endl;
    }

    //  member function for generater area

    float getArea()
    {
        return pi * radius * radius;
    }

    // member function for generate diameter

    float getDiameter()
    {
        return radius * 2;
    }

    // member function for generater circumference

    float getCircumference()
    {
        return 2 * pi * radius;
    }

    // display all info

    void displayAllinfo()
    {
        putCircle();
        cout << "area of circle is : " << getArea() << endl;
        cout << "diameter of circle is : " << getDiameter() << endl;
        cout << "circumference of circle is : " << getCircumference() << endl;
    }

    // operators for the adt circle

    Circle operator+(const Circle &obj) const
    {
        return Circle(this->x + obj.x, this->y + obj.y, this->radius + obj.radius);
    }

    Circle operator-(const Circle &obj) const
    {
        return Circle(this->x - obj.x, this->y - obj.y, this->radius - obj.radius);
    }

    bool operator==(const Circle &obj) const
    {
        return (this->x == obj.x && this->y == obj.y && this->radius == obj.radius);
    }

    // search function in circle adt

    int search(const Circle obj[], const int size) const
    {
        for (int i = 0; i < size; i++)
        {
            if (*this == obj[i])
            {
                return i;
            }
        }
        return -1;
    }

    // update only radius in the array of the objects

    void updateObject(Circle obj[], const int size, int update)
    {
        for (int i = 0; i < size; i++)
        {
            obj[i].setRadius(update);
        }
    }
    static bool compare(Circle a[], Circle b[])
    {
        // here you can write any logic what you want
        return 1;
    }
};
double Circle::pi = 3.1415926;

int main()
{
    int size = 2;
    Circle obj(1, 1, 1), obj1(1, 1, 1), obj2(1, 2, 3);
    Circle *p = new Circle[size];

    // for verifying some concepts of static functions
    // cout << Circle::getPi() << endl;
    // Circle a[4], b[2];
    // int z = Circle::compare(a, b);
    // cout << z << endl;

    for (int i = 0; i < size; i++)
    {
        p[i].getCircle();
    }

    for (int i = 0; i < size; i++)
    {
        p[i].displayAllinfo();
    }

    if (obj == obj1)
    {
        cout << "object and object1 are equal" << endl;
    }
    else
    {
        cout << "object and object1 are not equal" << endl;
    }

    if (obj == obj2)
    {
        cout << "object and object2 are equal" << endl;
    }
    else
    {
        cout << "object and object2 are not equal" << endl;
    }

    int n = obj.search(p, size);

    if (n == -1)
    {
        cout << "Object is not found" << endl;
    }
    else
    {
        cout << "object is found at " << n << " index" << endl;
    }
    delete[] p;
    // Circle obj1, obj2, obj3;
    // Circle obj[3] = {Circle(1, 2, 3.0), Circle(1, 4, 5.8), Circle(1, 2, 3)};
}