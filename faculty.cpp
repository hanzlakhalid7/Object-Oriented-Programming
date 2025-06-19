#include <iostream>

using namespace std;

class Faculty
{
private:
    int id;
    string firstName, lastName, qualification;
    float salary;

public:
    // COSTRUCTORS OF THE FACULTY ADT

    // default costructors

    Faculty()
    {
        id = 0;
        firstName = "";
        lastName = "";
        qualification = "";
        salary = -1;
    }

    // parametrized costructor1

    Faculty(int id, string firstName, string lastName, string qualification)
    {
        this->id = (id >= 1001 && id <= 1065) ? id : 0;
        this->firstName = firstName;
        this->lastName = lastName;
        this->qualification = qualification;
        this->salary = (salary >= 20000.0 && salary <= 100000.0) ? salary : -1;
    }

    // parametrized costructor2

    Faculty(int id, string firstName, string qualification)
    {
        this->id = (id >= 1001 && id <= 1065) ? id : 0;
        this->firstName = firstName;
        this->lastName = "";
        this->qualification = qualification;
        this->salary = (salary >= 20000.0 && salary <= 100000.0) ? salary : -1;
    }

    // parametrized costructor3

    Faculty(int id, string firstName, string lastName, string qualification, float salary)
    {
        this->id = (id >= 1001 && id <= 1065) ? id : 0;
        this->firstName = firstName;
        this->lastName = lastName;
        this->qualification = qualification;
        this->salary = (salary >= 20000.0 && salary <= 100000.0) ? salary : -1;
    }

    // copy costructor of adt

    Faculty(const Faculty &obj)
    {
        this->id = id;
        this->firstName = firstName;
        this->lastName = lastName;
        this->qualification = qualification;
        this->salary = salary;
    }

    // destructors of the faculaty adt

    ~Faculty()
    {
        cout << "Destructors is executed!!!...." << endl;
    }

    // setter functions of faculty adt

    void setId(int id)
    {
        this->id = (id >= 1001 && id <= 1065) ? id : this->id;
    }

    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }

    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }

    void setQualification(string qualification)
    {
        this->qualification = qualification;
    }

    void setSalary(float salary)
    {
        this->salary = (salary >= 20000.0 && salary <= 100000.0) ? salary : this->salary;
    }

    // getter function for faculty adt

    int getId() const
    {
        return id;
    }

    string getFirstName() const
    {
        return firstName;
    }

    string getLastName() const
    {
        return lastName;
    }

    string getQualification() const
    {
        return qualification;
    }

    float getSalary() const
    {
        return salary;
    }

    // member function of the faculty adt that set all private data member

    void set(int id, string firstName, string lastName, string qualification, float salary)
    {
        setId(id);
        setFirstName(firstName);
        setLastName(lastName);
        setQualification(qualification);
        setSalary(salary);
    }

    // member function that read data from console

    void read()
    {
        int id;
        string firstName, lastName, qualification;
        float salary;
        cout << "Enter id : ";
        cin >> id;
        cout << "Enter first name : ";
        cin >> firstName;
        cout << "Enter last name : ";
        cin >> lastName;
        cin.ignore();
        cout << "Enter qualification : ";
        getline(cin, qualification);
        cout << "Enter salary : ";
        cin >> salary;
        set(id, firstName, lastName, qualification, salary);
    }

    // member function is used for displaying data on console

    void write() const
    {
        cout << "id of faculty is : " << getId() << endl;
        cout << "first name of faculty is : " << getFirstName() << endl;
        cout << "last name of faculty is : " << getLastName() << endl;
        cout << "qualification of faculty is : " << getQualification() << endl;
        cout << "salary of faculty is : " << getSalary() << endl;
    }

    // function is used for check degree is post graduate or not

    bool isPostGraduate() const
    {
        if (qualification == "MS" || qualification == "ms" || qualification == "Phd" || qualification == "PHD")
        {
            return true;
        }

        return false;
    }

    // salary after tax calculation

    float getTakeHomeSalary() const
    {
        if (salary >= 20000)
        {
            float tax = (salary * 7) / 100;
            return salary - tax;
        }
        return -1;
    }

    //  salary greater then 200000

    bool isJoined() const
    {
        if (salary >= 20000)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    const int size = 1;
    Faculty *obj = new Faculty[size];

    for (int i = 0; i < size; i++)
    {
        (*(obj + i)).read();
    }

    for (int i = 0; i < size; i++)
    {
        cout << "-------------------------------------------------------" << endl;
        obj[i].write();

        if (obj[i].isPostGraduate())
        {
            cout << "Excellent you are post graduate!!!...." << endl;
        }
        else
        {
            cout << "You are not post graduate" << endl;
        }

        if (obj[i].getTakeHomeSalary() == -1)
        {
            cout << "Your salary is less the 20000" << endl;
        }
        else
        {
            cout << "Your salary after tax deduction is : " << obj[i].getTakeHomeSalary();
        }

        if (obj[i].isJoined())
        {
            cout << "Congratulation your slary is greater than 20000" << endl;
        }
        else
        {
            cout << "Your salary is less then 20000" << endl;
        }

        cout << "-------------------------------------------------------" << endl;
    }

    delete[] obj;
}