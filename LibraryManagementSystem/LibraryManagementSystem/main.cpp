#include "Book.hpp"
#include "User.hpp"
#include "Library.hpp"

#include <iostream>

// enum class for different menus
enum class Menu
{
    Main,
    ManageBooks,
    ManageUsers,
    ManageTransactions
};


// Function prototypes
int outputMenu(Menu); // Outputs menu based on which is specified in parameter
void printMenu(Menu); // Prints menu options based on which menu is specified in parameter

int main()
{
    Library* LibraryDatabase {Library::getInstance()};
    
    // Welcome message
    std::cout << "Welcome to the Library Management System.";
    
    // Variable declarations
    int menuSelection1; // Holds the user's menu selection for the main menu
    int menuSelection2; // Holds the user's menu selection for subsequent menu
    
    do
    {
        menuSelection1 = outputMenu(Menu::Main);
        
        switch (menuSelection1)
        {
            case 1:
                menuSelection2 = outputMenu(Menu::ManageBooks);
                switch (menuSelection2)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
                break;
            case 2:
                menuSelection2 = outputMenu(Menu::ManageUsers);
                switch (menuSelection2)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
                break;
            case 3:
                menuSelection2 = outputMenu(Menu::ManageTransactions);
                switch (menuSelection2)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
                        break;
                }
                break;
        }
    } while (menuSelection1 != 4);
}

int outputMenu(Menu chosenMenu)
{
    int menuSelection;
    
    do
    {
        try
        {
            std::cout << '\n' << '\n' << "Please select your desired action from the menu by entering the number indicated by"
            << " the chosen option."
            << '\n' << "-----------------------";
            printMenu(chosenMenu);
            std::cout << '\n' << "-----------------------"
            << '\n' << "Enter here -> ";
            std::cin >> menuSelection;
            
            if (menuSelection < 1 || menuSelection > 5) // Throws upon invalid selection
                throw ("Invalid input");
        }
        catch (...) // Outputs error message
        {
            std::cout << '\n' << '\n' << "Please make a valid selection.";
        }
    } while (menuSelection < 1 || menuSelection > 5);
    
    return menuSelection;
}

void printMenu(Menu chosenMenu)
{
    switch (chosenMenu)
    {
        case Menu::Main:
            std::cout << '\n' << "1 - Manage Books"
            << '\n' << "2 - Manage Users"
            << '\n' << "3 - Manage Transactions"
            << '\n' << "4 - Exit Library Management System";
            break;
        case Menu::ManageBooks:
            std::cout << '\n' << "1 - Add Book"
            << '\n' << "2 - Edit Book"
            << '\n' << "3 - Remove Book"
            << '\n' << "4 - View All Books"
            << '\n' << "5 - Return to Main Menu";
            break;
        case Menu::ManageUsers:
            std::cout << '\n' << "1 - Add User"
            << '\n' << "2 - Edit User"
            << '\n' << "3 - Remove User"
            << '\n' << "4 - View All Users"
            << '\n' << "5 - Return to Main Menu";
            break;
        case Menu::ManageTransactions:
            std::cout << '\n' << "1 - Check Out Book"
            << '\n' << "2 - Check In Book"
            << '\n' << "3 - View All Books"
            << '\n' << "4 - View All Users"
            << '\n' << "5 - Return to Main Menu";
            break;
    }
}
