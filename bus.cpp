#include <iostream>
#include <string>
using namespace std;

class Bus
{

private:
    int capacity;
    string owner, busNumber;

public:
    Bus(string busNumber, string owner)
    {
        this->busNumber = busNumber;
        this->owner = owner;
        capacity = 0;
    }

    Bus()
    {
        busNumber = "";
        owner = "";
        capacity = 0;
    }

    Bus(const Bus &obj)
    {
        this->busNumber = obj.busNumber;
        this->owner = obj.owner;
        this->capacity = obj.capacity;
    }

    ~Bus()
    {
        cout << "Destructor is executed!";
    }

    void setBusNumber(string busNumber)
    {
        this->busNumber = busNumber;
    }

    void setOwner(string owner)
    {
        this->owner = owner;
    }

    void setCapacity(int capacity)
    {
        this->capacity = capacity > 0 ? capacity : this->capacity;
    }

    string getBusNumber()
    {
        return busNumber;
    }

    string getOwner()
    {
        return owner;
    }

    int getCapacity()
    {
        return capacity;
    }

    void setBus(string busNumber, string owner, int capacity)
    {
        setBusNumber(busNumber);
        setOwner(owner);
        setCapacity(capacity);
    }

    void getBus()
    {
        cout << "Enter Bus Number : ";
        getline(cin, busNumber);
        cout << "Enter Owner Name : ";
        getline(cin, owner);
        cout << "Enter Bus Capacity : ";
        cin >> capacity;
        setBus(busNumber, owner, capacity);
        cin.ignore();
    }

    void putBus()
    {
        cout << busNumber << "\t\t" << owner << "\t" << capacity << endl;
    }

    void book()
    {
        setCapacity(capacity + 1);
    }

    void cancel()
    {
        setCapacity(capacity - 1);
    }
};

int main()
{

    int size = 2;
    Bus *bus = new Bus[5];

    for (int i = 0; i < size; i++)
    {
        bus[i].getBus();
    }

    cout << "Bus Number \tOwner \t\t Capacity" << endl;

    for (int i = 0; i < size; i++)
    {
        bus[i].putBus();
    }
}