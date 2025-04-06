#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() 
{
    list<string> tasks;
    int choice;
    string task;
    int taskNumber;

    while (true) 
    {
        
        cout << "\n1. Add Task\n2. Remove Task\n3. Show Tasks\n4. Exit\nChoice: ";
        cin >> choice;
        cin.ignore(); 
        if (choice == 1) 
        { 
            cout << "Enter the task you want: ";
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task was added" << endl;
        }
        else if (choice == 2) 
        { 
            if (tasks.empty()) 
            {
                cout << "No tasks to remove" << endl;
            }
            else 
            {
                cout << "Enter the task number to remove: ";
                cin >> taskNumber;
                cin.ignore(); 

                
                if (taskNumber < 1 || taskNumber > tasks.size()) 
                {
                    cout << "Your task number is invalid" << endl;
                }
                else
                {
                    auto it = tasks.begin();
                    advance(it, taskNumber - 1); 
                    tasks.erase(it); 
                    cout << "Task removed" << endl;
                }
            }
        }
        else if (choice == 3) 
        { 
            if (tasks.empty()) 
            {
                cout << "No tasks" << endl;
            }
            else {
                cout << "Tasks:" << endl;
                int index = 1;
                for (const auto& t : tasks) 
                {
                    cout << index++ << ". " << t << endl;
                }
            }
        }
        else if (choice == 4) 
        {
            break;
        }
        else 
        { 
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}