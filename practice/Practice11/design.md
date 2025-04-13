Board Game Café Lending

Specification

This program helps manage the lending system at a local board game café. The café owns multiple board games. Customers can check out games, and the system keeps track of which customer has which game and when it's due to be returned. The staff can also mark games as returned, which updates the available inventory.

**Entities**: BoardGame, Customer, Loan  
**Key Actions**: List all games, check out a game, return a game, view active loans


Design Classes

Nouns 
- **BoardGame** – title, totalCopies, availableCopies
- **Customer** – name, contact info
- **Loan** – game, customer, due date

Verbs 
- Add game to inventory
- Check out game to customer
- Return game
- List all games
- View who has what

Class Declarations 

```mermaid
class BoardGame 
{
private:
    std::string title;
    int totalCopies;
    int availableCopies;

public:
    BoardGame(const std::string& title, int totalCopies);

    std::string getTitle() const;
    int getTotalCopies() const;
    int getAvailableCopies() const;
    void checkOut();
    void returnCopy();
};

class Customer 
{
private:
    std::string name;
    std::string contactInfo;

public:
    Customer(const std::string& name, const std::string& contactInfo);

    std::string getName() const;
    std::string getContactInfo() const;
};

class Loan 
{
private:
    BoardGame* game;
    Customer* customer;
    std::string dueDate;

public:
    Loan(BoardGame* game, Customer* customer, const std::string& dueDate);

    BoardGame* getGame() const;
    Customer* getCustomer() const;
    std::string getDueDate() const;
};
Mermaid Class Diagram
```mermaid
Copy
Edit
classDiagram
    class BoardGame 
    {
        - string title
        - int totalCopies
        - int availableCopies
        + BoardGame(string title, int totalCopies)
        + string getTitle()
        + int getTotalCopies()
        + int getAvailableCopies()
        + void checkOut()
        + void returnCopy()
    }

    class Customer 
    {
        - string name
        - string contactInfo
        + Customer(string name, string contactInfo)
        + string getName()
        + string getContactInfo()
    }

    class Loan 
    {
        - BoardGame* game
        - Customer* customer
        - string dueDate
        + Loan(BoardGame* game, Customer* customer, string dueDate)
        + BoardGame* getGame()
        + Customer* getCustomer()
        + string getDueDate()
    }

    Loan --> BoardGame : "references"
    Loan --> Customer : "references"