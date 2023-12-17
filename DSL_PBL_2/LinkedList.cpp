#include "LinkedList.h"
#include "mainwindow.h"
LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::addContact(std::string firstName, std::string lastName, std::string phoneNumber, std::string email) {
    Contact* newContact = new Contact();
    newContact->firstName = firstName;
    newContact->lastName = lastName;
    newContact->phoneNumber = phoneNumber;
    newContact->email = email;

    Contact* temp=head;
    int compareTwoContactsBy = 2;
    while (((temp != nullptr) && (temp->next != nullptr)) && (temp->lastName.compare(newContact->lastName) < 0))
    {
        temp = temp->next;
    }

    if (temp != nullptr)
    {
        compareTwoContactsBy = temp->lastName.compare(newContact->lastName);
    }
    //if the list is empty or the new contact is < than the first contact from the phone book
    if ((temp == nullptr) || ((temp == head) &&
                           (compareTwoContactsBy > 0)))
    {
        //Adding the new contact on first position of the list
        newContact->next = head;
        newContact->prev = nullptr;
        if (head != nullptr)
        {
            head->prev = newContact;
        }
        head = newContact;
    }
    else
    {
        //If we are at the last contact and the new contact is > than the last contact from the phone book
        if ((temp->next == nullptr) &&
            (compareTwoContactsBy < 0))
        {
            //Adding the new contact on the last position of the list
            newContact->next = nullptr;
            newContact->prev = temp;
            temp->next = newContact;
        }
        else
        {
            //Checking if the lastName and firstName are not the same with the new contact
            if (compareTwoContactsBy != 0)
            {
                //Adding at the position iterator is at
                newContact->next = temp;
                newContact->prev = temp->prev;
                temp->prev->next = newContact;
                temp->prev = newContact;
            }
        }
    }
}
Contact* LinkedList:: searchContact(std::string lastName,std::string firstName)
{
    Contact* temp;
    temp = head;
    while(temp!=nullptr)       //Search till end
    {
        if(temp->lastName==lastName && temp->firstName ==firstName)  //if first and last name matched
        {
            return temp;  //Contact found,return ptr to contact
        }
        temp = temp->next;
    }
    return nullptr;//Contact not found
}
int LinkedList:: deleteContact(std::string lastName,std:: string firstName)
{
    Contact* temp=head;
    if(temp==nullptr)
    {
        return -1;
    }
    // Check if the first node is the contact to be deleted
    if (temp->lastName == lastName && temp->firstName == firstName) {
        head = temp->next; // Update head to the next node
        if (head != nullptr) {
            head->prev = nullptr; // Update the new head's prev pointer
        }
        delete temp; // Delete the node
        return 1; // Contact found and deleted successfully
    }
    // Traverse the list to find the contact
    while (temp != nullptr)
    {
        if (temp->lastName == lastName && temp->firstName == firstName) {
            temp->prev->next = temp->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            delete temp;
            return 1; // Contact found and deleted successfully
        }
        temp = temp->next;
    }

    return -1; // Contact not found
}

Contact* LinkedList::getHead() const {
    return head;
}
