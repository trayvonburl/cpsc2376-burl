#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <string>

class Observer 
{
public:
    virtual void update(const std::vector<int>& grades) = 0;
    virtual ~Observer() = default;
};

class GradeBook 
{
    std::vector<int> grades;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addObserver(std::shared_ptr<Observer> observer) 
    {
        observers.push_back(observer);
    }

    void addGrade(int grade) 
    {
        grades.push_back(grade);
        notifyObservers();
    }

    void changeGrade(size_t index, int grade) 
    {
        if (index < grades.size()) 
        {
            grades[index] = grade;
            notifyObservers();
        }
    }

    void notifyObservers() 
    {
        for (auto& obs : observers) 
        {
            obs->update(grades);
        }
    }

    void printGrades() const 
    {
        std::cout << "Grades: ";
        for (int g : grades) std::cout << g << " ";
        std::cout << "\n";
    }
};

class Averager : public Observer 
{
public:
    void update(const std::vector<int>& grades) override 
    {
        if (!grades.empty())
        {
            float avg = std::accumulate(grades.begin(), grades.end(), 0.0f) / grades.size();
            std::cout << "Average grade: " << avg << "\n";
        }
    }
};

class Notifier : public Observer 
{
public:
    void update(const std::vector<int>& grades) override 
    {
        for (int g : grades) 
        {
            if (g < 60) 
            {
                std::cout << "Email sent to student@example.com\n";
                break;
            }
        }
    }
};

int main() 
{
    GradeBook book;
    auto avg = std::make_shared<Averager>();
    auto notif = std::make_shared<Notifier>();
    book.addObserver(avg);
    book.addObserver(notif);

    std::string command;
    while (true) 
    {
        std::cout << "\nEnter command (add <grade>, change <index> <grade>, print, exit): ";
        std::getline(std::cin, command);
        std::string action;
      

        if (action == "add")
        {
            int grade = 0;
            if (index >> grade) 
            {
                book.addGrade(grade);
            }
        }
        else if (action == "change") 
        {
            size_t index;
            int grade;
            if (index >> grade) 
            {
                book.changeGrade(index, grade);
            }
        }
        else if (action == "print") 
        {
            book.printGrades();
        }
        else if (action == "exit") 
        {
            break;
        }
        else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}