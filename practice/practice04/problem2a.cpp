#include <iostream>
#include <string>
#include <deque>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

template <typename T>
T performOperation(T a, T b, char operation) 
{
    switch (operation) 
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) throw std::invalid_argument("Can't divide by zero!");
        return a / b;
    default: throw std::invalid_argument("Invalid operation.");
    }
}

double getNumberFromInput(const string& input) 
{
    try 
    {
     
        return stod(input);
    }
    catch (...) 
    {
        throw std::invalid_argument("Invalid, enter a valid number.");
    }
}

int main()
{
    try 
    {
        string firstInput, secondInput;
        char operation;

        
        deque<double> results;

        
        auto start = high_resolution_clock::now();

        
        cout << "Enter the first number: ";
        getline(cin, firstInput);
        cout << "Enter the second number: ";
        getline(cin, secondInput);
        cout << "Enter the operation: ";
        cin >> operation;

        
        double firstNumber = getNumberFromInput(firstInput);
        double secondNumber = getNumberFromInput(secondInput);

       
        double result;
        if (firstNumber == static_cast<int>(firstNumber) && secondNumber == static_cast<int>(secondNumber)) 
        {
            int intFirst = static_cast<int>(firstNumber);
            int intSecond = static_cast<int>(secondNumber);
            result = performOperation(intFirst, intSecond, operation);
        }
        else 
        {
            result = performOperation(firstNumber, secondNumber, operation);
        }

        
        results.push_back(result);

        
        cout << fixed << setprecision(2) << "Result: " << result << endl;

        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);

        cout << "Operation took " << duration.count() << " microseconds." << endl;

       
        cout << "\nPrevious results:" << endl;
        for (const auto& res : results) 
        {
            cout << fixed << setprecision(2) << res << endl;
        }
    }
    catch (const std::exception& e) 
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}