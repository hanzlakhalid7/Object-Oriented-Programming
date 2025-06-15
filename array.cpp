#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int *arr;

public:
    Array()
    {
        this->size = 5;
        this->arr = new int[size]{};
        /*for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }*/
    }
    Array(const int size, const int arr[])
    {
        this->size = size;
        this->arr = new int[this->size]{};
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
    }
    Array(const int size)
    {
        this->size = (size > 0) ? size : 5;
        this->arr = new int[this->size]{};
        /* for (int i = 0; i < this->size; i++)
         {
             this->arr[i] = 0;
         }*/
    }
    Array(const Array &obj)
    {
        this->size = obj.size;
        this->arr = new int[this->size]{};
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = obj.arr[i];
        }
    }
    ~Array()
    {
        delete[] arr;
    }

    void setSize(const int size)
    {
        this->size = (size > 0) ? size : 5;
    }
    void setArr(const int arr[])
    {
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
    }

    int *getArr() const
    {
        return arr;
    }
    int getSize() const
    {
        return size;
    }

    int operator[](int index) const
    {
        if (index >= 0 && index < size)
        {
            return this->arr[index];
        }
        throw out_of_range{"out of bound"};
    }
    int &operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return this->arr[index];
        }
        throw out_of_range{"out of bound"};
    }

    Array &operator=(const Array &obj)
    {
        if (this != &obj && this->size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }
    friend ostream &operator<<(ostream &cout, const Array &obj)
    {
        for (int i = 0; i < obj.getSize(); i++)
        {
            cout << obj[i] << "\t";
        }
    }
    friend istream &operator>>(istream &cin, Array &obj)
    {
        cout << "Enter size : ";
        cin >> obj.size;
        obj.setSize(obj.size);
        for (int i = 0; i < obj.size; i++)
        {
            cout << "Enter " << i << " index : ";
            cin >> obj[i];
        }
    }
};

int main()
{
    Array obj;
    try
    {
        cout << obj[6];
    }
    catch (const exception &ex)
    {
        cout << ex.what();
    }
    cin >> obj;
    cout << obj << endl;
    return 0;
}