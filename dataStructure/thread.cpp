#include <iostream>
using namespace std;
class Employee{
    private:
    string name;
    int paymentPerHour;
    public:
    Employee(string name, int paymentPerHour)
    {
        this->name = name;
        this->paymentPerHour = paymentPerHour;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    void setPaymentPerHour(int paymentPerHour){
        this->paymentPerHour = paymentPerHour;
    }
    int getPaymentPerHour(){
        return paymentPerHour;
    }
    virtual int calculateSalary() = 0;
};
class PartTimeEmployee:public Employee{
    private:
    int workingHours;
    public:
    PartTimeEmployee(string name, int paymentPerHour, int workingHours):Employee(name, paymentPerHour){
        this->workingHours = workingHours;
    }
    int calculateSalary(){
        return this->workingHours * Employee::getPaymentPerHour();
    }
};
class FullTimeEmployee:Employee{
    public:
    FullTimeEmployee(string name, int paymentPerHour):Employee(name, paymentPerHour){

    }
    int calculateSalary(){
        return 8 * Employee::getPaymentPerHour();
    }
};