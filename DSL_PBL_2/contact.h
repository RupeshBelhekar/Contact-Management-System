#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;
    std::string email;
    Contact* next;   // Pointer to the next contact in the list
    Contact* prev;
};
#endif // CONTACT_H
