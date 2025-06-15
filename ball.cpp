#include <iostream>

using namespace std;

class Ball
{
private:
    int id, quantity;
    string name;
    float price;

public:
    // constructors of the ball adt
    Ball(int id, string name, int quantity, float price)
    {
        this->id = id > 0 ? id : 0;
        this->name = "";
        this->quantity = quantity > 0 ? quantity : 0;
        this->price = price > 0 ? price : 0;
    }

    Ball(int id, string name, int quantity)
    {
        this->id = id > 0 ? id : 0;
        this->name = "";
        this->quantity = quantity > 0 ? quantity : 0;
        this->price = 0;
    }

    Ball(const Ball &obj)
    {
        this->id = obj.id;
        this->name = obj.name;
        this->quantity = obj.quantity;
        this->price = obj.price;
    }

    ~Ball()
    {
        cout << "Destructor has been executed!!!...." << endl;
    }

    // setter of the ball adt

    void setId(int id)
    {
        this->id = id > 0 ? id : this->id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setQuantity(int quantity)
    {
        this->quantity = quantity > 0 ? quantity : this->quantity;
    }
    void setPrice(float price)
    {
        this->price = price > 0 ? price : this->price;
    }

    // getter of the ball adt

    int getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    int getQuantity() const
    {
        return quantity;
    }
    float getPrice() const
    {
        return price;
    }

    // set the ball dat in the prvate data member

    void setBall(int id, string name, int quantity, float price)
    {
        setId(id);
        setName(name);
        setQuantity(quantity);
        setPrice(price);
    }

    // get the ball data from the console

    void getBall()
    {
        int id, quantity;
        string name;
        float price;
        cout << "Enter ball id : ";
        cin >> id;
        cout << "Enter brand name : ";
        cin >> name;
        cout << "Enter quantity : ";
        cin >> quantity;
        cout << "Enter price per unit : ";
        cin >> price;
        setBall(id, name, quantity, price);
    }

    // display the ball data on the consloe

    void putBall() const
    {
        cout << "Ball id : " << this->id << endl;
        cout << "Brand name is : " << this->name << endl;
        cout << "Quantity is : " << this->quantity << endl;
        cout << "Price per unit is : " << this->price << endl;
    }

    // function is for calculating the total price if the quantity is greater then 1

    float getTotalPrice()
    {
        if (this->quantity >= 1)
            return this->quantity * this->price;
        return 0;
    }

    bool isSame(const Ball &obj) const
    {
        if (this->id == obj.id && this->name == obj.name && this->quantity == obj.quantity && this->price == obj.price)
            return true;
        return false;
    }

    void updateName(Ball arr[], const int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (this->id == arr[i].id)
            {
                arr[i].name = this->name;
            }
        }
    }

    Ball maxPriceBall(const Ball arr[], const int size) const
    {
        float max = -1;
        int index;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].price > max)
            {
                max = arr[i].price;
                index = i;
            }
        }
        return arr[index];
    }

    void getAverage(const Ball arr[], const int size)
    {
        float sum = 0, average;
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].price <= 50)
            {
                sum += arr[i].price;
                count++;
            }
        }
        average = sum / count;
        this->price = average;
    }
};

int main()
{
    const int size = 5;
    float totalPrice;

    Ball obj1(12, "adidas", 10, 50);
    Ball obj[size] = {Ball(12, "adidas", 10, 50), Ball(13, "abcd", 10, 50), Ball(14, "xyz", 10, -1), Ball(15, "uyt", 9, 70), Ball(16, "pqrs", 15, 80)};

    for (int i = 0; i < size; i++)
    {
        cout << "-------------------------------------" << endl;

        obj[i].putBall();

        if (obj1.isSame(obj[i]))
        {
            cout << "Balls are equal " << endl;
        }
        else
        {
            cout << "Balls are not equal" << endl;
        }

        totalPrice = obj[i].getTotalPrice();
        cout << "Total price of the ball is : " << totalPrice << endl;
        cout << "-------------------------------------" << endl;
    }

    obj1.maxPriceBall(obj, size).putBall();
    cout << "-------------------------------------" << endl;

    obj1.getAverage(obj, size);
    obj1.putBall();
    cout << "-------------------------------------" << endl;
}