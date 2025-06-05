#ifndef Book_hpp
#define Book_hpp

#include <iostream>
#include <string>

class Book
{
    private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool availability;
    
    public:
    // Constructor(s)
    Book() = default;
    Book(std::string newTitle, std::string newAuthor, std::string newISBN) : title {newTitle}, author {newAuthor}, ISBN {newISBN}
    {
    }
    
    // Accessor(s)
    std::string getTitle() const
    {
        return title;
    }
    std::string getAuthor() const
    {
        return author;
    }
    std::string getISBN() const
    {
        return ISBN;
    }
    bool getAvailability() const
    {
        return availability;
    }
    
    // Mutator(s)
    void setTitle(std::string newTitle)
    {
        title = newTitle;
    }
    void setAuthor(std::string newAuthor)
    {
        title = newAuthor;
    }
    void setISBN(std::string newISBN)
    {
        title = newISBN;
    }
    void setAvailability(bool newAvailability)
    {
        title = newAvailability;
    }
    
    // Misc. functions
    std::string returnAvailability(bool status);
    void printDetails();
};

#endif
