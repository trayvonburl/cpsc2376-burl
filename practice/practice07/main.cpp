#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include "employee.h"

int main() 
{
    std::vector<std::unique_ptr<Employee>> employees; // Vector of unique_ptr to avoid memory leaks

    // Open the file containing employee data
    std::ifstream file("employees.txt");
    if (!file) {
        std::cerr << "Error opening!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) 
    {
        std::istringstream ss(line);
        std::string type;
        int id;
        std::string name;

        ss >> type >> id;
        std::getline(ss, name);

        
        if (!name.empty() && name[0] == ' ') 
        {
            name.erase(name.begin());
        }

        if (type == "Salaried") 
        {
            double salary;
            ss >> salary;
            employees.push_back(std::make_unique<SalariedEmployee>(name, id, salary));
        }
        else if (type == "Hourly") 
        {
            double hourlyRate;
            int hoursWorked;
            ss >> hourlyRate >> hoursWorked;
            employees.push_back(std::make_unique<HourlyEmployee>(name, id, hourlyRate, hoursWorked));
        }
        else if (type == "Commission") 
        {
            double baseSalary, salesAmount, commissionRate;
            ss >> baseSalary >> salesAmount >> commissionRate;
            employees.push_back(std::make_unique<CommissionEmployee>(name, id, baseSalary, salesAmount, commissionRate));
        }
        else 
        {
            std::cerr << "No Known type: " << type << std::endl;
        }
    }

    file.close();

    for (const auto& employee : employees) 
    {
        employee->displayInfo();
    }

    return 0;
}