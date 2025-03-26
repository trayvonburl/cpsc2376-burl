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

    cout << "\n The numbers in reverse order: ";
    for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}