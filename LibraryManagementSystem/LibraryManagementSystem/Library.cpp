#include "Library.hpp"

void Library::printAllUsers() // Outputs information of all users
{
    for (int count = 0; count < totalUserCount; count++)
    {
        if (userCollection[count] != nullptr)
        {
            std::cout << '\n' << "-----------------------"
            << '\n' << "User #" << count << " in Database"
            << '\n'
            << '\n' << "Username - " << (*userCollection[count]).getUsername()
            << '\n' << "User ID - " << (*userCollection[count]).getUserID()
            << '\n' << "Books Borrowed:";
            (*userCollection[count]).User::printBooksBorrowed();
        }
        std::cout << '\n' << "-----------------------";
    }
}

void Library::printAllBooks() // Outputs information of all books
{
    for (int count = 0; count < totalBookCount; count++)
    {
        if (bookCollection[count] != nullptr)
        {
            std::cout << '\n' << "-----------------------"
            << '\n' << "Book #" << count << " in Database"
            << '\n'
            << '\n' << "Title - " << (*bookCollection[count]).getTitle()
            << '\n' << "Author - " << (*bookCollection[count]).getAuthor()
            << '\n' << "ISBN - " << (*bookCollection[count]).getISBN()
            << '\n' << "Availability - " << (*bookCollection[count]).returnAvailability((*bookCollection[count]).getAvailability());
        }
        std::cout << '\n' << "-----------------------";
    }
}

int Library::searchUser(std::string userToFind) // Searches for a specified User
{
    for (int count = 0; count < totalUserCount; count++)
    {
        if ((*userCollection[count]).getUsername() == userToFind)
            return count;
    }
    
    return -1;
}

int Library::searchBook(std::string bookToFind) // Searches for a specified Book by title
{
    for (int count = 0; count < totalBookCount; count++)
    {
        if ((*bookCollection[count]).getTitle() == bookToFind)
            return count;
    }
    
    return -1;
}


void Library::addUser() // Menu option to add new user
{
    std::string newUserUsername; // Holds the username of the new user
    std::string junkInput; // Just holds whatever user inputted to progress forward
    
    // Retrieves username of new user
    std::cout << '\n' << "Please enter the name of the new user."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, newUserUsername);
    
    // Creating new user and incrementing totalUserCount
    userCollection[totalUserCount] = new User(newUserUsername);
    totalUserCount++;
    
    // Presenting details of newly created user
    std::cout << '\n' << "Here are the details of the new user. Enter any key to return."
    << '\n' << "-----------------------"
    << '\n' << "Username - " << (*userCollection[totalUserCount]).getUsername()
    << '\n' << "User ID - " << (*userCollection[totalUserCount]).getUserID()
    << '\n' << "Books Borrowed:";
    (*userCollection[totalUserCount]).User::printBooksBorrowed();
    std::cout << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin >> junkInput;
    
    std::cout << '\n' << '\n' << "Returning to menu...";
}

void Library::editUser() // Menu option to edit existing user
{
    std::string newUserUsername; // Holds the new username of the user
    std::string searchEditUser; // The presumed name of the user to be edited, used to search
    // for said user
    int userIndex; // Index of the user to be edited
    std::string junkInput; // Just holds whatever user inputted to progress forward
    
    // Retrieves username of new user
    std::cout << '\n' << "Please enter the name of the user you wish to edit."
    << "Please note that you can only edit a user's name."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, searchEditUser);
    
    // Searching for specified user
    userIndex = searchUser(searchEditUser);
    
    if (userIndex == -1)
    {
        std::cout << '\n' << "This user was not found.";
    }
    else
    {
        // Retrieving new username
        std::cout << '\n' << "Please enter the new name of this user."
        << '\n' << "-----------------------"
        << '\n' << "Enter here -> ";
        std::cin.ignore();
        getline(std::cin, newUserUsername);
        
        // Setting new username
        (*userCollection[userIndex]).setUsername(newUserUsername);
        
        // Presenting details of updated user
        std::cout << '\n' << "Here are the updated details of the user. Enter any key to return."
        << '\n' << "-----------------------"
        << '\n' << "Username - " << (*userCollection[userIndex]).getUsername()
        << '\n' << "User ID - " << (*userCollection[userIndex]).getUserID()
        << '\n' << "Books Borrowed:";
        (*userCollection[userIndex]).User::printBooksBorrowed();
        std::cout << '\n' << "-----------------------"
        << '\n' << "Enter here -> ";
        std::cin >> junkInput;
    }
    
    std::cout << '\n' << '\n' << "Returning to menu...";
}

void Library::removeUser() // Menu option to remove existing user
{
    std::string searchRemoveUser; // The presumed name of the user to be removed, used to search
    // for said user
    int userIndex; // A pointer to the user to be removed
    char deleteDecision; // Holds user's ultimate decision to delete from yes/no prompt in program
    
    // Retrieves username of new user
    std::cout << '\n' << "Please enter the name of the user you wish to remove."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, searchRemoveUser);
    
    // Searching for specified user
    userIndex = searchUser(searchRemoveUser);
    
    if (userIndex == -1)
    {
        std::cout << '\n' << "This user was not found.";
    }
    else
    {
        do
        {
            try
            {
                // Presents information of user selected for removal
                std::cout << '\n' << "Below are the details of the selected user."
                << '\n' << " Are you sure you wish to delete this user? This action cannot be undone."
                << '\n' << "Enter Y for yes, or N for no."
                << '\n' << "-----------------------"
                << '\n' << "Username - " << (*userCollection[userIndex]).getUsername()
                << '\n' << "User ID - " << (*userCollection[userIndex]).getUserID()
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin >> deleteDecision;
                
                if (toupper(deleteDecision) != 'Y' && toupper(deleteDecision) != 'N') // Throws upon invalid selection
                    throw ("Invalid input");
            }
            catch (...) // Outputs error message
            {
                std::cout << '\n' << '\n' << "Please make a valid selection.";
            }
        } while (toupper(deleteDecision) != 'Y' && toupper(deleteDecision) != 'N');
        
        if (toupper(deleteDecision) == 'Y')
        {
            delete userCollection[userIndex];
            userCollection[userIndex] = nullptr;
        }
        
        std::cout << '\n' << '\n' << "Returning to menu...";
    }
}

void Library::viewAllUsers() // Menu option to view all users
{
    std::string junkInput; // Just holds whatever user inputted to progress forward
    
    std::cout << '\n' << '\n' << "Below is every user in the library database."
    << "Enter any key to return.";
    printAllUsers();
    std::cout << '\n' << "Enter here -> ";
    
    std::cin >> junkInput;
}

void Library::addBook() // Menu option to add new book
{
    std::string newBookTitle; // Holds the title of the new book
    std::string newBookAuthor; // Holds the author of the new book
    std::string newBookISBN; // Holds the ISBN of the new book
    std::string junkInput; // Just holds whatever user inputted to progress forward
    
    // Retrieves username of new user
    std::cout << '\n' << "Please enter the title of the new boook."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, newBookTitle);
    
    // Retrieves username of new user
    std::cout << '\n' << "Please enter the author of the new boook."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, newBookAuthor);
    
    // Retrieves username of new user
    std::cout << '\n' << "Please enter the ISBN of the new boook."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, newBookISBN);
    
    // Creating new book and incrementing totalBookCount
    bookCollection[totalBookCount] = new Book(newBookTitle, newBookAuthor, newBookISBN);
    totalBookCount++;
    
    // Presenting details of newly created book
    std::cout << '\n' << "Here are the details of the new user. Enter any key to return."
    << '\n' << "-----------------------"
    << '\n' << "Title - " << (*bookCollection[totalBookCount]).getTitle()
    << '\n' << "Author - " << (*bookCollection[totalBookCount]).getAuthor()
    << '\n' << "ISBN - " << (*bookCollection[totalBookCount]).getISBN()
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin >> junkInput;
    
    std::cout << '\n' << '\n' << "Returning to menu...";
}

void Library::editBook() // Menu option to edit existing book
{
    std::string newBookDetail; // Holds the new detail of the book
    std::string searchEditBook; // The presumed name of the book to be edited, used to search
    // for said book
    int bookIndex; // Index of the book to be edited
    int menuSelection; // Holds the book's selection of which book detail to edit
    // (title, author, ISBN)
    std::string junkInput; // Just holds whatever user inputted to progress forward
    
    std::cout << '\n' << "Please enter the title of the book you wish to edit."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, searchEditBook);
    
    // Searching for specified book
    bookIndex = searchBook(searchEditBook);
    
    if (bookIndex == -1)
    {
        std::cout << '\n' << "This book was not found.";
    }
    else
    {
        // Asking user which book detail they'd like to edit
        do
        {
            try
            {
                std::cout << '\n' << "Please select which detail of the book you'd like to edit"
                << " by entering the number indicated by the chosen option."
                << '\n' << "-----------------------"
                << '\n' << "1 - Title"
                << '\n' << "2 - Author"
                << '\n' << "3 - ISBN"
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin >> menuSelection;
                
                if (menuSelection < 1 || menuSelection > 3) // Throws upon invalid selection
                    throw ("Invalid input");
            }
            catch (...) // Outputs error message
            {
                std::cout << '\n' << '\n' << "Please make a valid selection.";
            }
        } while (menuSelection < 1 || menuSelection > 3);
        
        // Proceeding to edit the indicated detail of chosen book
        switch (menuSelection)
        {
            case 1:
                std::cout << '\n' << "Please enter the new title of the book."
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin.ignore();
                getline(std::cin, newBookDetail);
                (*bookCollection[bookIndex]).setTitle(newBookDetail);
            case 2:
                std::cout << '\n' << "Please enter the new author of the book."
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin.ignore();
                getline(std::cin, newBookDetail);
                (*bookCollection[bookIndex]).setAuthor(newBookDetail);
            case 3:
                std::cout << '\n' << "Please enter the new ISBN of the book."
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin.ignore();
                getline(std::cin, newBookDetail);
                (*bookCollection[bookIndex]).setISBN(newBookDetail);
        }
        
        // Presenting details of updated user
        std::cout << '\n' << "Here are the updated details of the book. Enter any key to return."
        << '\n' << "-----------------------"
        << '\n' << "Title - " << (*bookCollection[totalBookCount]).getTitle()
        << '\n' << "Author - " << (*bookCollection[totalBookCount]).getAuthor()
        << '\n' << "ISBN - " << (*bookCollection[totalBookCount]).getISBN()
        << '\n' << "-----------------------"
        << '\n' << "Enter here -> ";
        std::cin >> junkInput;
    }
    
    std::cout << '\n' << '\n' << "Returning to menu...";
}
    
void Library::removeBook() // Menu option to remove existing book
{
    std::string searchRemoveBook; // The presumed name of the book to be removed, used to search
    // for said book
    int bookIndex; // A pointer to the book to be removed
    char deleteDecision; // Holds user's ultimate decision to delete from yes/no prompt in program
    
    // Retrieves book
    std::cout << '\n' << "Please enter the name of the book you wish to remove."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, searchRemoveBook);
    
    // Searching for specified user
    bookIndex = searchBook(searchRemoveBook);
    
    if (bookIndex == -1)
    {
        std::cout << '\n' << "This user was not found.";
    }
    else
    {
        do
        {
            try
            {
                // Presents information of user selected for removal
                std::cout << '\n' << "Below are the details of the selected user."
                << '\n' << "Are you sure you wish to delete this user? This action cannot be undone."
                << '\n' << "Enter Y for yes, or N for no."
                << '\n' << "-----------------------"
                << '\n' << "Title - " << (*bookCollection[bookIndex]).getTitle()
                << '\n' << "Author - " << (*bookCollection[bookIndex]).getAuthor()
                << '\n' << "ISBN - " << (*bookCollection[bookIndex]).getISBN()
                << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin >> deleteDecision;
                
                if (toupper(deleteDecision) != 'Y' && toupper(deleteDecision) != 'N') // Throws upon invalid selection
                    throw ("Invalid input");
            }
            catch (...) // Outputs error message
            {
                std::cout << '\n' << '\n' << "Please make a valid selection.";
            }
        } while (toupper(deleteDecision) != 'Y' && toupper(deleteDecision) != 'N');
        
        if (toupper(deleteDecision) == 'Y')
        {
            delete bookCollection[bookIndex];
            bookCollection[bookIndex] = nullptr;
        }
        
        std::cout << '\n' << '\n' << "Returning to menu...";
    }
}

void Library::viewAllBooks() // Menu option to view all books
{
    std::string junkInput; // Just holds whatever user inputted to progress forward
    
    std::cout << '\n' << '\n' << "Below is every book in the library database."
    << "Enter any key to return.";
    printAllBooks();
    std::cout << '\n' << "Enter here -> ";
    
    std::cin >> junkInput;
}

void Library::checkOutBook() // Menu option to check out a book
{
    std::string userToCheckOut; // Inputted name of user that will check out book
    std::string bookToCheckOut; // Inputted name of book that will be checked out
    int userIndex; // Index of user who will check out book
    int bookIndex; // Index of book that will be checked out
    char checkOutDecision; // Reads user's final confirmation of whether to check out a book
    
    std::cout << '\n' << '\n' << "Please enter the name of the user that will check"
    << " out a book."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, userToCheckOut);
    
    userIndex = searchUser(userToCheckOut);
    
    if (userIndex == -1)
    {
        std::cout << '\n' << "This user was not found.";
    }
    else
    {
        std::cout << '\n' << '\n' << "Please enter the name of the book that will"
        << "be checked out."
        << '\n' << "-----------------------"
        << '\n' << "Enter here -> ";
        std::cin.ignore();
        getline(std::cin, bookToCheckOut);
        
        bookIndex = searchBook(bookToCheckOut);
        
        if (bookIndex == -1)
        {
            std::cout << '\n' << "This book was not found.";
        }
        else
        {
            do
            {
                try
                {
                    std::cout << "Below are the details of the user who will check out"
                    << " the book, and the book to be checked out. Please confirm whether"
                    << " these details are correct."
                    << '\n' << "Enter Y for yes, or N for no."
                    << '\n' << "-----------------------"
                    << '\n' << "User to Check Out"
                    << '\n'
                    << '\n' << "Username - " << (*userCollection[userIndex]).getUsername()
                    << '\n' << "User ID - " << (*userCollection[userIndex]).getUserID()
                    << '\n' << "-----------------------"
                    << '\n' << "Book to Check Out"
                    << '\n'
                    << '\n' << "Title - " << (*bookCollection[bookIndex]).getTitle()
                    << '\n' << "Author - " << (*bookCollection[bookIndex]).getAuthor()
                    << '\n' << "ISBN - " << (*bookCollection[bookIndex]).getISBN()
                    << '\n' << "-----------------------"
                    << '\n' << "Enter here -> ";
                    std::cin >> checkOutDecision;
                    
                    if (toupper(checkOutDecision) != 'Y' && toupper(checkOutDecision) != 'N') // Throws upon invalid selection
                        throw ("Invalid input");
                }
                catch (...) // Outputs error message
                {
                    std::cout << '\n' << '\n' << "Please make a valid selection.";
                }
            } while (toupper(checkOutDecision) != 'Y' && toupper(checkOutDecision) != 'N');
            
            if (toupper(checkOutDecision) == 'Y')
                (*userCollection[userIndex]).borrowBook(bookCollection[bookIndex]);
            
            std::cout << '\n' << '\n' << "Returning to menu...";
        }
    }
}

void Library::checkInBook() // Menu option to check in a book
{
    std::string userToCheckIn;
    int userIndex;
    int menuSelection; // Reads user's selection of which book to return
    int booksBorrowedCount;
    
    std::cout << '\n' << '\n' << "Please enter the name of the user that will check"
    << " in a book."
    << '\n' << "-----------------------"
    << '\n' << "Enter here -> ";
    std::cin.ignore();
    getline(std::cin, userToCheckIn);
    
    userIndex = searchUser(userToCheckIn);
    
    if (userIndex == -1)
    {
        std::cout << '\n' << "This user was not found.";
    }
    else
    {
        booksBorrowedCount = (*userCollection[userIndex]).getTotalBooks();
        
        do
        {
            try
            {
                std::cout << '\n' << "Please select the book you wish to return by entering the number"
                << " indicated by the chosen book."
                << '\n' << "-----------------------";
                (*userCollection[userIndex]).printBooksBorrowed();
                std::cout << '\n' << "-----------------------"
                << '\n' << "Enter here -> ";
                std::cin >> menuSelection;
                
                if (menuSelection < 0 || menuSelection > booksBorrowedCount) // Throws upon invalid selection
                    throw ("Invalid input");
            }
            catch (...) // Outputs error message
            {
                std::cout << '\n' << '\n' << "Please make a valid selection.";
            }
        } while (menuSelection < 0 || menuSelection > booksBorrowedCount);
        
        //(*userCollection[userIndex]).returnBook();
    }
}
