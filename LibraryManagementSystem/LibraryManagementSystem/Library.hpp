#ifndef Library_hpp
#define Library_hpp

#include "Book.hpp"
#include "User.hpp"

#include <iostream>
#include <iomanip>
#include <cctype>

// - All Books + Users will be instantiated through this class, ensure there's function built in
// to prevent duplicate books being added (No two books may share the same ISBN). Duplicate
// users are fine since every user will have a unique user ID

class Library
{
    private:
    User* userCollection[100]; // Holds all Users in library
    Book* bookCollection[100]; // Holds all Books in library
    int totalUserCount {0}; // Keeps track of total users created
    int totalBookCount {0}; // Keeps track of total books created
    
    // Sole instance of Library class
    static Library* soleLibrary;
    
    // Private constructor(s)
    Library()
    {
    }
    
    public:
    // Deleting copy constructor
    Library (const Library& object) = delete;
    
    // getInstance() method is the only way to access an instance of this class
    static Library* getInstance()
    {
        if (soleLibrary == nullptr)
            soleLibrary = new Library();
        
        return soleLibrary;
    }
    
    // Destructor
    ~Library()
    {
        for (int count = 0; count < totalUserCount; count++)
        {
            if (userCollection[count] != nullptr)
                delete userCollection[count];
        }
        
        for (int count = 0; count < totalBookCount; count++)
        {
            if (bookCollection[count] != nullptr)
                delete bookCollection[count];
        }
    }
    
    // Misc. functions
    void printAllUsers(); // Outputs information of all users
    void printAllBooks(); // Outputs information of all books
    int searchUser(std::string); // Searches for a specified User
    int searchBook(std::string); // Searches for a specified Book
    
    void addUser(); // Menu option to add new user
    void editUser(); // Menu option to edit existing user
    void removeUser(); // Menu option to remove existing user
    void viewAllUsers(); // Menu option to view all users
    void addBook(); // Menu option to add new book
    void editBook(); // Menu option to edit existing book
    void removeBook(); // Menu option to remove existing book
    void viewAllBooks(); // Menu option to view all books
    void checkOutBook(); // Menu option to check out a book
    void checkInBook(); // Menu option to check in a book
};

#endif
