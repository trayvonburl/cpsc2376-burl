#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    vector<int> numbers;
    int num;
    char choice;

  
    cout << "Enter integers (type 'exit' to stop):" << endl;
    while (true) 
    {
        cout << "Enter a number: ";
        if (cin >> num) 
        {
            numbers.push_back(num);
        }
        else 
        {
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter an integer or 'exit' to stop." << endl;
            continue;
        }

        cout << "Do you want to enter another number? (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') 
        {
            break;
        }
    }

    cout << "\n Your Numbers entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;

    
    int evenSum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) 
    {
        if (*it % 2 == 0) 
        {
            evenSum += *it;
        }
    }

    cout << "Sum of even numbers: " << evenSum << endl;

    return 0;
}