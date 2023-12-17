#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"
#include "LinkedList.h"
#include "contact.h"
#include <QString>
#include <string.h>
#include <iostream>
#include <fstream>
#include "dialog.h"
using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), contactsList(new LinkedList()), updateDialog(nullptr)
{

    ui->setupUi(this);
    this->showMaximized();
//    QString imagePath = "D:/Qt/DSL_PBL_2/updatewindow (1) (1).png";
    QString imagePath = "D:/Qt/DSL_PBL_2/bg_image (1).png";
    QString styleSheet = "QMainWindow { background-image: url(" + imagePath + ");background-repeat: no-repeat;}";
    this->setStyleSheet(styleSheet);
    connect(ui->Add_contactPush, SIGNAL(clicked()), this, SLOT(on_addContactButton_clicked()));
    connect(ui->searchContactButton, SIGNAL(clicked()), this,SLOT(on_searchContactButton_clicked()));
    connect(ui->deleteContactButton, SIGNAL(clicked()), this,SLOT(on_deleteContactButton_clicked()));
    connect(ui->displayContactButton, SIGNAL(clicked()), this,SLOT(on_displayContactButton_clicked()));
    connect(ui->updateContactButton, SIGNAL(clicked()), this,SLOT(on_updateContactButton_clicked()));
//    createDefaultFile("contacts.dat");
//    loadContactsFromFile(*contactsList, "contacts.dat");
    displayContacts();

}

MainWindow::~MainWindow() {
//    saveContactsToFile(*contactsList, "contacts.dat");
    delete ui;
    delete updateDialog;
}

void MainWindow::on_addContactButton_clicked()
{
    QString firstName = ui->FirstNameLineEdit->text();
    QString lastName = ui->LastNameLineEdit->text();
    QString phoneNumber = ui->ContactNumberLineEdit->text();
    QString gmail = ui->EmailLineEdit->text();

    // Add contact to the linked list
    contactsList->addContact(firstName.toStdString(), lastName.toStdString(),
                             phoneNumber.toStdString(), gmail.toStdString());

    // Update the list widget to display contacts
    ui->listWidget->clear();
    displayContacts();

    // Clear input fields
    ui->FirstNameLineEdit->clear();
    ui->LastNameLineEdit->clear();
    ui->ContactNumberLineEdit->clear();
    ui->EmailLineEdit->clear();
}
void MainWindow::on_searchContactButton_clicked()
{
    // Create and show the search results window
    QString firstName = ui->FirstNameLineEdit->text();
    QString lastName = ui->LastNameLineEdit->text();


    // Update the list widget to display searched contact
    ui->listWidget->clear();
    Contact *temp = contactsList->searchContact(lastName.toStdString(),firstName.toStdString());

    if(temp!=nullptr)
    {
        ui->listWidget->addItem("       " + QString::fromStdString(temp->firstName) + "  " + QString::fromStdString(temp->lastName)+ "                           " + QString::fromStdString(temp->phoneNumber) + "                                   " + QString::fromStdString(temp->email));
    }
    else
    {
        ui->listWidget->addItem("\n                                           Contact Not found!");
    }

}
void MainWindow:: on_displayContactButton_clicked()
{
    ui->listWidget->clear();
    displayContacts();
}
void MainWindow:: displayContacts()
{
    ui->listWidget->clear();
    Contact *temp = contactsList->getHead();
    if(!temp)
    {
        ui->listWidget->addItem("\n                                           No Contacts!");
    }
    else
    {
        while(temp!=nullptr)
        {
            ui->listWidget->addItem("       " + QString::fromStdString(temp->firstName) + "  " + QString::fromStdString(temp->lastName)+ "                           " + QString::fromStdString(temp->phoneNumber) + "                                   " + QString::fromStdString(temp->email));
            temp = temp->next;
        }

    }
}
void MainWindow::on_deleteContactButton_clicked()
{
    // Create and show the search results window
    QString firstName = ui->FirstNameLineEdit->text();
    QString lastName = ui->LastNameLineEdit->text();

    bool contactDeleted = contactsList->deleteContact(lastName.toStdString(),firstName.toStdString());
    // Update the list widget to display searched contact
    ui->listWidget->clear();

    if(contactDeleted)
    {
        displayContacts();
    }
    else
    {
        ui->listWidget->addItem("\n                                           Contact Not found!");
    }
}

void MainWindow::on_updateContactButton_clicked()
{
    if (updateDialog == nullptr)
    {
        updateDialog = new Dialog(this);
        updateDialog->setWindowTitle("Update contact");
        updateDialog->setModal(true);
        updateDialog->setContactsList(contactsList);
        updateDialog->exec();
    }
    else
    {
        updateDialog->close();
        delete updateDialog;
        updateDialog = nullptr;
    }
}
