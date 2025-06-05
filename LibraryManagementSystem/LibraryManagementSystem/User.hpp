#ifndef User_hpp
#define User_hpp

#include "Book.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

// Still need to implement books as borrowed objects, somehow

class User
{
    private:
    std::string username;
    std::string userID;
    int totalBooks = 0;
    Book* borrowedBooks[5]; // List of books that have been borrowed. Initialized as pointer
    // to Books so that array can point to Books directly, negating a need to copy the Books'
    // data to store it
    
    public:
    // Constructor(s)
    User()
    {
        username = "";
        userID = generateUserID();
    }
    User(std::string newUsername) : username {newUsername}
    {
        userID = generateUserID();
    }
    
    // Accessor(s)
    std::string getUsername() const
    {
        return username;
    }
    std::string getUserID() const
    {
        return userID;
    }
    int getTotalBooks() const
    {
        return totalBooks;
    }
    
    // Mutator(s)
    void setUsername(std::string newUsername)
    {
        username = newUsername;
    }
    
    // Misc. functions
    std::string generateUserID();
    void printBooksBorrowed();
    int userBookSearch(Book* searchBook);
    void borrowBook(Book* bookToBorrow);
    void returnBook(Book* bookToReturn);
};

#endif
