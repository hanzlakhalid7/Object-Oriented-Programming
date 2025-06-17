#include <iostream>
#include <math.h>

using namespace std;

class Cuboid
{
private:
    float height, width, depth;

public:
    // costructors of the cuboid adt

    Cuboid()
    {
        height = width = depth = 1;
    }

    Cuboid(float height, float width, float depth)
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);
    }

    Cuboid(float height, float width)
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);
    }

    Cuboid(const Cuboid &obj)
    {
        height = obj.height;
        width = obj.width;
        depth = obj.depth;
    }

    // destructors of the cuboid adt

    ~Cuboid()
    {
        cout << "Destructors has executed!!!" << endl;
    }

    // setter of the cuboid adt

    void setHeight(float height)
    {
        this->height = height > 0 && height < 35 ? height : 1;
    }

    void setWidth(float width)
    {
        this->width = width > 0 && width < 35 ? width : 1;
    }

    void setDepth(float depth)
    {
        this->depth = depth > 0 && depth < 35 ? depth : 1;
    }

    // getter of the cuboid adt

    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }

    float getdepth()
    {
        return depth;
    }

    // member function setCuboid for set data

    void setCuboid(float height, float width, float depth)
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);
    }

    // member function getCuboid for get data from console

    void getCuboid()
    {
        cout << "Enter height of the cuboid : ";
        cin >> height;
        cout << "Enter width of the cuboid : ";
        cin >> width;
        cout << "Enter depth of the cuboid : ";
        cin >> depth;

        setCuboid(height, width, depth);
    }

    // member function putCuboid display information

    void putCuboid()
    {
        cout << "Height of the cuboid is : " << height << endl;
        cout << "Width of the cuboid is : " << width << endl;
        cout << "Depth of the cuboid is : " << depth << endl;
    }

    // member function getSurfaceArea generate surface area

    float getSurfaceArea(float height, float width, float depth)
    {
        return (2 * (height * width) + 2 * (height * depth) + 2 * (width * depth));
    }

    // member function is used to generate volume of cuboid

    float getVolume(float height, float width, float depth)
    {
        return height * width * depth;
    }

    // member function is used to generate space diagonal of cuboid

    float getSpaceDiagonal(float height, float width, float depth)
    {
        return sqrt((height * height) + (width * width) + (depth * depth));
    }

    // member function that display all info of the cuboid

    void putCuboidsInfo()
    {
        putCuboid();
        cout << "Surface area of the cuboid : " << getSurfaceArea(height, width, depth) << endl;
        cout << "Surface volume of the cuboid : " << getVolume(height, width, depth) << endl;
        cout << "Surface space diagonal of the cuboid : " << getSpaceDiagonal(height, width, depth) << endl;
    }
};

int main()
{
    const int size = 5;
    Cuboid *obj = new Cuboid[size];

    for (int i = 0; i < size; i++)
    {
        (obj[i]).getCuboid();
        (obj + i)->getCuboid();
    }

    for (int i = 0; i < size; i++)
    {
        obj[i].putCuboidsInfo();
    }
    delete[] obj;
}