#include <iostream>
#include <iomanip>

using namespace std;


double convertTemperature(double temp, char scale = 'F') 
{
    if (scale == 'F') 
    {
        return (temp * 9.0 / 5.0) + 32;
    }
    else if (scale == 'C') 
    {

        return (temp - 32) * 5.0 / 9.0;
    }
    else 
    {
        return temp;
    }
}


void showMenu() 
{
    cout << "1. Convert Celsius to Fahrenheit\n";
    cout << "2. Convert Fahrenheit to Celsius\n";
}

int main() 
{
    int choice;
    double temp;
    char scale;

    while (true) 
    {
        showMenu();
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) 
        {
            scale = 'F'; 
        }
        else if (choice == 2) 
        {
            scale = 'C'; 
        }
        else 
        {
            cout << "Choose 1 or 2.\n";
            continue;
        }

        cout << "Enter temperature: ";
        cin >> temp;

        double convertedTemp = convertTemperature(temp, scale);

        if (scale == 'F') 
        {
            cout << fixed << setprecision(2) << "Converted: " << convertedTemp << "°F\n";
        }
        else 
        {
            cout << fixed << setprecision(2) << "Converted: " << convertedTemp << "°C\n";
        }

        char repeat;
        cout << "Another conversion? (y/n): ";
        cin >> repeat;
        if (repeat != 'y' && repeat != 'Y') 
        {
            break;
        }
    }

    cout << "You used Trayvon's Temperature Converter!\n";
    return 0;
}