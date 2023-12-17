#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "contact.h"

class LinkedList {
private:
    Contact* head; // Pointer to the first contact in the list
    size_t size;

public:
    LinkedList();
    void addContact(std::string firstName, std::string lastName, std::string phoneNumber, std::string email);
    Contact* searchContact(std::string lastName, std::string firstName);
    int deleteContact(std::string lastName, std:: string firstName);
    Contact* getHead() const;

};
#endif // LINKEDLIST_H
