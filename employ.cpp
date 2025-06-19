#include <iostream>
#include <fstream>

using namespace std;

class Employe
{

private:
    string name, department, position;
    int id;

public:
    void setName(string name)
    {
        this->name = name;
    }

    void setDepartment(string department)
    {
        this->department = department;
    }

    void setPosition(string position)
    {
        this->position = position;
    }

    void setId(int id)
    {
        this->id = id > 0 ? id : this->id;
    }

    string getName()
    {
        return name;
    }

    string getDepartment()
    {
        return department;
    }

    string getPosition()
    {
        return position;
    }

    int getId()
    {
        return id;
    }

    void setInfo(string name, int id, string department, string position)
    {
        setName(name);
        setId(id);
        setDepartment(department);
        setPosition(position);
    }

    void getInfo()
    {
        cout << "Enter Employe Name : ";
        getline(cin, name);

        cout << "Enter Employe ID : ";
        cin >> id;

        cin.ignore();

        cout << "Enter Employe Department : ";
        getline(cin, department);

        cout << "Enter Employe Position : ";
        getline(cin, position);

        setInfo(name, id, department, position);
    }

    void putInfo()
    {
        cout << name << "\t" << id << "\t" << department << "\t" << position << endl;
    }

    Employe(string name, int id, string department, string position)
    {
        this->name = name;
        this->id = id;
        this->department = department;
        this->position = position;
    }

    Employe(string name1, int id1) : name(name1), id(id1)
    {
        department = "";
        position = "";
    }

    Employe() : name(""), id(0), department(""), position("")
    {
    }

    Employe(const Employe &obj) : name(obj.name), id(obj.id), department(obj.department), position(obj.position)
    {
    }

    ~Employe()
    {
        cout << "Destructor executed" << endl;
    }
};

int main()
{
    int size = 2;
    Employe *employe = new Employe[size];

    for (int i = 0; i < size; i++)
    {
        employe[i].getInfo();
    }

    cout << "name \t\t id \t department \t\t position" << endl;

    for (int i = 0; i < size; i++)
    {
        employe[i].putInfo();
    }

    delete[] employe;
}