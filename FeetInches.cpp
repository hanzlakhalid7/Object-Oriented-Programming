#include "iostream"

using namespace std;

class FeetInches
{
private:
    int feet;   // To hold a number of feet
    int inches; // To hold a number of inches

    // Private member function to simplify the values in feet and inches
    void simplify()
    {
        if (inches >= 12)
        {
            feet += (inches / 12);
            inches = inches % 12;
        }
        else if (inches < 0)
        {
            feet -= ((abs(inches) / 12) + 1);
            inches = 12 - (abs(inches) % 12);
        }
    }

public:
    // Constructor
    FeetInches(int f = 0, int i = 0)
    {
        feet = f;
        inches = i;
        simplify();
    }

    // Copy constructor
    FeetInches(const FeetInches &right)
    {
        feet = right.feet;
        inches = right.inches;
        simplify();
    }

    // Mutator function to set feet
    void setFeet(int f)
    {
        feet = f;
    }

    // Mutator function to set inches
    void setInches(int i)
    {
        inches = i;
        simplify();
    }

    // Accessor function to get feet
    int getFeet() const
    {
        return feet;
    }

    // Accessor function to get inches
    int getInches() const
    {
        return inches;
    }

    // Overloaded + operator
    FeetInches operator+(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches + right.inches;
        temp.feet = feet + right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded - operator
    FeetInches operator-(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches - right.inches;
        temp.feet = feet - right.feet;
        temp.simplify();

        return temp;
    }

    // Overloaded * operator
    FeetInches operator*(const FeetInches &right)
    {
        FeetInches temp;

        temp.inches = inches * right.inches;
        temp.feet = feet * right.feet;
        temp.simplify();
        return temp;
    }

    // Overloaded prefix ++ operator
    FeetInches operator++()
    {
        ++inches;
        simplify();

        return *this;
    }

    // Overloaded postfix ++ operator
    FeetInches operator++(int)
    {
        FeetInches temp(feet, inches);

        inches++;
        simplify();

        return temp;
    }

    // Overloaded prefix -- operator
    FeetInches operator--()
    {
        --inches;
        simplify();

        return *this;
    }

    // Overloaded postfix -- operator
    FeetInches operator--(int)
    {
        FeetInches temp(feet, inches);

        inches--;
        simplify();

        return temp;
    }

    // Overloaded > operator
    bool operator>(const FeetInches &right) const
    {
        bool status;

        if (feet > right.feet)
            status = true;
        else if (feet == right.feet && inches > right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded < operator
    bool operator<(const FeetInches &right) const
    {
        return !(*this > right);
    }

    // Overloaded >= operator
    bool operator>=(const FeetInches &right) const
    {
        bool status;

        if (feet >= right.feet)
            status = true;
        else if (feet == right.feet && inches >= right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded <= operator
    bool operator<=(const FeetInches &right) const
    {
        return !(*this >= right);
    }

    // Overloaded == operator
    bool operator==(const FeetInches &right) const
    {
        bool status;

        if (feet == right.feet && inches == right.inches)
            status = true;
        else
            status = false;

        return status;
    }

    // Overloaded != operator
    bool operator!=(const FeetInches &right) const
    {
        return !(*this == right);
    }

    // Friend function to overload << operator for output
    friend ostream &operator<<(ostream &, const FeetInches &);

    // Friend function to overload >> operator for input
    friend istream &operator>>(istream &, FeetInches &);
};

// Overloaded << operator
ostream &operator<<(ostream &cout, const FeetInches &obj)
{
    cout << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

    return cout;
}

// Overloaded >> operator
istream &operator>>(istream &cin, FeetInches &obj)
{
    cout << "Enter Feet:\t";
    cin >> obj.feet;

    cout << "Enter Inches:\t";
    cin >> obj.inches;

    return cin;
}

class RoomDimension
{
private:
    FeetInches width, lenght;

public:
    // costructor
    RoomDimension(FeetInches &len, FeetInches &wid) : lenght(len), width(wid)
    {
    }

    // setter
    void setLength(int lenF, int lenI)
    {
        lenght.setFeet(lenF);
        lenght.setInches(lenI);
    }
    void setWidth(int widF, int widI)
    {
        width.setFeet(widF);
        width.setInches(widI);
    }
    // getters
    FeetInches getLength() const
    {
        return lenght;
    }
    FeetInches getWidth() const
    {
        return width;
    }

    float area_of_room()
    {
        FeetInches area = lenght * width;
        float areaf = (area.getFeet() + area.getInches() / 100);
        return areaf;
    }
    void display_dimensions()
    {
        cout << "Lenght : " << this->lenght << "\t" << "Width : " << this->width << endl;
    }
};
class RoomCarpet
{
private:
    RoomDimension roomSize;
    float costPerSquareFeet;

public:
    RoomCarpet(RoomDimension roomS, float price) : roomSize(roomS), costPerSquareFeet(price)
    {
    }
    void setRoomSize(RoomDimension roomS)
    {
        roomSize = roomS;
    }
    void setCostPerSquareFeet(float price)
    {
        this->costPerSquareFeet = price;
    }
    RoomDimension getRoomSize() const
    {
        return roomSize;
    }
    float getCostPerSquareFeet(float price) const
    {
        return costPerSquareFeet;
    }
    float total_cost()
    {
        float tc;
        tc = costPerSquareFeet * this->roomSize.area_of_room();
        return tc;
    }
};
int main()
{
    FeetInches length, width;
    cin >> length;
    cin >> width;
    RoomDimension obj(length, width);
    float price;
    cout << "Enter price per square feet : ";
    cin >> price;
    RoomCarpet r(obj, price);
    cout << "Total cost of the carpet : " << r.total_cost() << endl;
}