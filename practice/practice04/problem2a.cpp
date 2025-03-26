#include <iostream>
#include <string>

using namespace std;


void greet(string name = "Guest", string prefix = "Hello") 
{
    cout << prefix << ", " << name << "!" << endl;
}


void showMenu() 
{
    cout << "1. Default Greeting\n";
    cout << "2. Greet by Name\n";
    cout << "3. Custom Greeting\n";
}

int main() 
{
    int choice;
    string name, prefix;

    while (true) 
    {
        showMenu();
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) 
        {
            
            greet();
        }
        else if (choice == 2) 
        {
            cout << "Enter name: ";
            cin >> name;
            greet(name);
        }
        else if (choice == 3) 
        {
          
            cout << "Enter greeting prefix: ";
            cin >> prefix;
            cout << "Enter name: ";
            cin >> name;
            greet(name, prefix); 
        }
        else 
        {
            cout << "Invalid, choose 1, 2, or 3.\n";
            continue;  
        }

        char repeat;
        cout << "Another greeting? (y/n): ";
        cin >> repeat;
        if (repeat != 'y' && repeat != 'Y') 
        {
            break;
        }
    }

    cout << "You used Trayvon's Greeting System!\n";
    return 0;
}