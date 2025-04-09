#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>


class Employee 
{
public:
    std::string name;
    int id;

    Employee(std::string name, int id) : name(name), id(id) {}

    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const 
    {
        std::cout << "ID: " << id << ", Name: " << name;
    }

    virtual ~Employee() = default;
};


class SalariedEmployee : public Employee 
{
public:
    double monthlySalary;
    SalariedEmployee(std::string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override { return monthlySalary; }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Type: Salaried, Monthly Salary: $" << std::fixed << std::setprecision(2) << calculateSalary() << std::endl;
    }
};


class HourlyEmployee : public Employee 
{
public:
    double hourlyRate;
    int hoursWorked;
    HourlyEmployee(std::string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override { return hourlyRate * hoursWorked; }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Type: Hourly, Hours Worked: " << hoursWorked << ", Hourly Rate: $"
            << std::fixed << std::setprecision(2) << hourlyRate << ", Salary: $"
            << calculateSalary() << std::endl;
    }
};


class CommissionEmployee : public Employee 
{
public:
    double baseSalary, salesAmount, commissionRate;
    CommissionEmployee(std::string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override { return baseSalary + (salesAmount * commissionRate); }
    void displayInfo() const override
    {
        Employee::displayInfo();
        std::cout << ", Type: Commission, Base Salary: $" << std::fixed << std::setprecision(2)
            << baseSalary << ", Sales: $" << salesAmount << ", Commission Rate: "
            << commissionRate * 100 << "%, Salary: $" << calculateSalary() << std::endl;
    }
};


std::vector<std::unique_ptr<Employee>> readEmployeesFromFile(const std::string& filename) 
{
    std::vector<std::unique_ptr<Employee>> employees;
    std::ifstream inputFile(filename);

    if (!inputFile) 
    {
        std::cerr << "Error." << std::endl;
        return employees;
    }

    std::string line;
    while (std::getline(inputFile, line)) 
    {
        std::istringstream iss(line);
        std::string type, name;
        int id;

        iss >> type >> id;
        std::getline(iss, name);
        name = name.substr(1); 

        if (type == "Salaried") 
        {
            double salary;
            iss >> salary;
            employees.push_back(std::make_unique<SalariedEmployee>(name, id, salary));
        }
        else if (type == "Hourly") 
        {
            double rate;
            int hours;
            iss >> rate >> hours;
            employees.push_back(std::make_unique<HourlyEmployee>(name, id, rate, hours));
        }
        else if (type == "Commission") 
        {
            double baseSalary, salesAmount, commissionRate;
            iss >> baseSalary >> salesAmount >> commissionRate;
            employees.push_back(std::make_unique<CommissionEmployee>(name, id, baseSalary, salesAmount, commissionRate));
        }
    }
    return employees;
}

int main() 
{
    auto employees = readEmployeesFromFile("employees.txt");

    for (const auto& employee : employees) 
    {
        employee->displayInfo();
    }

    return 0;
}