#include "Book.hpp"

std::string Book::returnAvailability(bool status)
{
    if (status == true)
        return "Available";
    else
        return "Borrowed";
}

void Book::printDetails()
{
    std::cout << '\n' << "Title - " << title
    << '\n' << "Author - " << author
    << '\n' << "ISBN - " << ISBN
    << '\n' << "Availability - " << returnAvailability(availability);
}
