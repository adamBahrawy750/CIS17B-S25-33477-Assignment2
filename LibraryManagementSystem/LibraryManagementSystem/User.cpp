#include "User.hpp"

std::string User::generateUserID()
{
    // Variable declaration(s)
    std::string newUserID; // Holds the full randomly-generated account number
    std::string randDigit; // Holds each randomly generated digit to add to account number
    
    // Generates a random digit eight times, appending it to newAccountNumber at the end of
    // each run
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int count = 0; count < 8; count++)
    {
        randDigit = std::to_string(rand() % 10);
        newUserID.append(randDigit);
    }
    
    return newUserID;
}

void User::printBooksBorrowed()
{
    if (totalBooks > 0)
    {
        for (int count = 0; count <= totalBooks; count++)
        {
            std::cout << '\n' << "Book #" << count << " - "
            << (*borrowedBooks[count]).Book::getTitle();
        }
    }
    else
    {
        std::cout << '\n' << "None.";
    }
}

int User::userBookSearch(Book* searchBook)
{
    for (int count = 0; count <= totalBooks; count++)
    {
        if ((*searchBook).Book::getISBN() == (*borrowedBooks[count]).Book::getISBN())
            return count;
    }
    
    return -1;
}

void User::borrowBook(Book* bookToBorrow) // Function to borrow a book
{
    if (totalBooks < 5)
    {
        if ((*bookToBorrow).Book::getAvailability())
        {
            borrowedBooks[totalBooks] = bookToBorrow; // Copying pointer from totalBooks to now
            // have direct access to that book
            
            totalBooks++; // Incrementing totalBooks
            
            (*bookToBorrow).Book::setAvailability(false); // Flagging book as now being borrowed
        }
        else
        {
            // Temporary error message
            std::cout << '\n' << "This book has already been checked out by another user.";
        }
    }
    else
    {
        // Temporary error message
        std::cout << '\n' << "This user has already checked out the maximum number of books.";
    }
}

void User::returnBook(Book* bookToReturn) // Function to return a book
{
    // Clears out copied data of now-returned book from user list
    // Decrements the user's borrowed book total
    // Re-sorts array of borrowed books so that next open slot is the last one
    
    int bookIndex = {userBookSearch(bookToReturn)};
    
    if (bookIndex == -1)
    {
        std::cout << '\n' << "This user has not checked out that book.";
    }
    else
    {
        borrowedBooks[bookIndex] = nullptr;
        totalBooks--;
        
        // Loop re-orders all Books in borrowedBooks so there are no empty indexes
        // between Book objects, thus, any subsequent Books are added to the end of the list
        bool indexEmpty = false;
        for (int count = 0; count < 5; count++)
        {
            if (borrowedBooks[count] == nullptr)
                indexEmpty = true;
            
            if (indexEmpty && borrowedBooks[count + 1] != nullptr)
            {
                borrowedBooks[count] = borrowedBooks[count + 1];
                borrowedBooks[count + 1] = nullptr;
                
            }
        }
    }
}
