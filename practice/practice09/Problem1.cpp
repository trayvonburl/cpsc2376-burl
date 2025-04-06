#include <iostream>
#include <string>

using namespace std;

int main() 
{
   
    float redPotion{ 0.0f };
    float bluePotion{ 0.0f };
    float* flask{ nullptr };  

    string potionChoice;
    float amountToAdd;

    while (true) 
    {
       
        cout << "Which potion would you like to add liquid to? (Red or Blue, or type 'Done' to quit): ";
        cin >> potionChoice;

        if (potionChoice == "Done") 
        {
            break;
        }


        if (potionChoice == "Red") 
        {
            flask = &redPotion;
        }
        else if (potionChoice == "Blue") 
        {
            flask = &bluePotion;
        }
        else 
        {
            cout << "Invalid potion choice! Please choose 'Red' or 'Blue'." << endl;
            continue;  
        }

        cout << "How many milliliters to add: ";
        cin >> amountToAdd;

        
        *flask += amountToAdd;

        
        cout << "Current Potion Levels:" << endl;
        cout << "Red Potion: " << redPotion << " mL" << endl;
        cout << "Blue Potion: " << bluePotion << " mL" << endl;
    }

    return 0;
}