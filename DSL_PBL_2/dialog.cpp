// Dialog.cpp
#include "dialog.h"
#include "ui_dialog.h"
#include "qobjectdefs.h"
#include "LinkedList.h"
#include "contact.h"
#include <QString>
#include <string.h>
#include "dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog), contactsList(new LinkedList())
{
    ui->setupUi(this);
    this->showMaximized();
    QString imagePath1 ="D:/Qt/DSL_PBL_2/updatewindow (2).png";
    QString styleSheet = "QDialog { background-image: url(" + imagePath1 + ");background-repeat: no-repeat;}";
    this->setStyleSheet(styleSheet);
    connect(ui->updatecontactButton, SIGNAL(clicked()), this, SLOT(onUpdateButtonClicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onUpdateButtonClicked()
{
    // Logic to update contact
    // Retrieve data from oldFirstNameLineEdit and perform the update
    QString firstName = ui->oldfirstnamelineEdit->text();
    QString lastName = ui->oldlastnamelineEdit->text();
    ui->oldlistWidget->clear();
    ui->newlistWidget->clear();

    Contact *temp = contactsList->searchContact(lastName.toStdString(),firstName.toStdString());
    if(temp!=nullptr)
    {
        ui->oldlistWidget->addItem("       " + QString::fromStdString(temp->firstName) + "  " + QString::fromStdString(temp->lastName)+ "                           " + QString::fromStdString(temp->phoneNumber) + "                                   " + QString::fromStdString(temp->email));

        // Get the new details from the user
        QString newFirstName = ui->newfirstnamelineEdit->text();
        QString newLastName = ui->newlastnamelineEdit->text();
        QString newPhoneNumber = ui->newnumberlineEdit->text();
        QString newEmail = ui->newemaillineEdit->text();

        // Update the contact details
        temp->firstName = newFirstName.toStdString();
        temp->lastName = newLastName.toStdString();
        temp->phoneNumber = newPhoneNumber.toStdString();
        temp->email = newEmail.toStdString();

        // Clear input fields
        ui->oldfirstnamelineEdit->clear();
        ui->oldlastnamelineEdit->clear();
        ui->newfirstnamelineEdit->clear();
        ui->newlastnamelineEdit->clear();
        ui->newnumberlineEdit->clear();
        ui->newemaillineEdit->clear();
        // Display updated contact details
        ui->newlistWidget->addItem("       " + QString::fromStdString(temp->firstName) + "  " + QString::fromStdString(temp->lastName) + "                           " + QString::fromStdString(temp->phoneNumber) + "                                   " + QString::fromStdString(temp->email));

    }
    else
    {
        ui->oldlistWidget->addItem("\n                                           Contact Not found!");
    }
}
void Dialog::setContactsList(LinkedList *list)
{
    contactsList = list;
}
