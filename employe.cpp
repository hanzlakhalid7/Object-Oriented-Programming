#include <iostream>
using namespace std;
class Employee
{
private:
    string firstName, lastName, ssn;

public:
    Employee(string firstName, string lastName, string ssn)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->ssn = ssn;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }

    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void setSsn(string ssn)
    {
        this->ssn = ssn;
    }
    string getFirstName() const
    {
        return this->firstName;
    }

    string getLastName() const
    {
        return this->lastName;
    }
    string getSsn() const
    {
        return this->ssn;
    }
    virtual void print() const
    {
        cout << "Name of Employe is : " << firstName << " " << lastName << endl;
        cout << "Social security number of Employe is : " << ssn << endl;
    }
    virtual double earning() = 0;
    ~Employee()
    {
    }
};
class SalariedEmployee : public Employee
{
private:
    double weekelySalary;

public:
    SalariedEmployee(double weekelySalary, string firstName, string lastName, string ssn) : Employee(firstName, lastName, ssn)
    {
        this->weekelySalary = weekelySalary < 0 ? 0 : weekelySalary;
    }
    void setWeekelySalary(double weekelySalary)
    {
        this->weekelySalary = weekelySalary < 0 ? 0 : weekelySalary;
    }
    double getWeekelySalary() const
    {
        return weekelySalary;
    }
    void print() const override
    {
        Employee::print();
        cout << "Weekely salary of employe is : " << weekelySalary << endl;
    }
    double earning() override
    {
        return weekelySalary;
    }
    ~SalariedEmployee()
    {
    }
};

class HourlyEmployee : public Employee
{
private:
    double wage, hours;

public:
    HourlyEmployee(double wage, double hours, string firstName, string lastName, string ssn) : Employee(firstName, lastName, ssn)
    {
        this->hours = hours < 0 ? 0 : hours;
        this->wage = wage < 0 ? 0 : wage;
    }
    void setHours(double hours)
    {
        this->hours = hours < 0 ? 0 : hours;
    }
    void setWage(double wage)
    {
        this->wage = wage < 0 ? 0 : wage;
    }
    double getHours() const
    {
        return hours;
    }
    double getWage() const
    {
        return wage;
    }
    void print() const override
    {
        Employee::print();
        cout << "Hours of employe are : " << hours << endl;
        cout << "Wage per hour is : " << wage << endl;
    }
    double earning() override
    {
        return hours * wage;
    }
    ~HourlyEmployee()
    {
    }
};

class CommissionEmployee : public Employee
{
private:
    double grossSale, commissionRate;

public:
    CommissionEmployee(double grossSale, double commissionRate, string firstName, string lastName, string ssn) : Employee(firstName, lastName, ssn)
    {
        this->commissionRate = commissionRate < 0 ? 0 : commissionRate;
        this->grossSale = grossSale < 0 ? 0 : grossSale;
    }
    void setcommissionRate(double commissionRate)
    {
        this->commissionRate = commissionRate < 0 ? 0 : commissionRate;
    }
    void setgrossSale(double grossSale)
    {
        this->grossSale = grossSale < 0 ? 0 : grossSale;
    }
    double getcommissionRate() const
    {
        return commissionRate;
    }
    double getgrossSale() const
    {
        return grossSale;
    }
    void print() const override
    {
        Employee::print();
        cout << "Commission Rate of employe are : " << commissionRate << endl;
        cout << "Gross sale is : " << grossSale << endl;
    }
    double earning() override
    {
        return commissionRate * grossSale;
    }
    ~CommissionEmployee()
    {
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
    double baseSalry;

public:
    BasePlusCommissionEmployee(double baseSalry, double grossSale, double commissionRate, string firstName, string lastName, string ssn) : CommissionEmployee(grossSale, commissionRate, firstName, lastName, ssn)
    {
        this->baseSalry = baseSalry < 0 ? 0 : baseSalry;
    }
    void setBaseSalry(double baseSalry)
    {
        this->baseSalry = baseSalry < 0 ? 0 : baseSalry;
    }
    double getBaseSalry() const
    {
        return baseSalry;
    }
    void print() const override
    {
        CommissionEmployee::print();
        cout << "Base salary of employe is : " << baseSalry << endl;
    }
    double earning() override
    {
        return (CommissionEmployee::earning() + baseSalry);
    }
    ~BasePlusCommissionEmployee()
    {
    }
};

int main()
{
    SalariedEmployee a(80000, "Talha", "Bakhat", "123");
    HourlyEmployee b(80, 20, "Abdul", "Hanan", "1234");
    CommissionEmployee c(800, 200, "Muhammad", "Baig", "12345");
    BasePlusCommissionEmployee d(40000, 2000, 100, "Hanzla", "Khalid", "123456");
    // Employee *p[4] = {&a, &b, &c, &d};
    // a.setFirstName("Km");
    // for (auto n : p)
    // {
    //     n->print();
    //     cout << "Total earning is : " << n->earning() << endl;
    // }
    // for (auto n : p)
    // {
    //     n->print();
    //     cout << "Total earning is : " << n->earning() << endl;
    // }
    // d.print();
    // c = d;
    // c.print();
    d.Employee::print(); // this will print the Employee class data form child class
}