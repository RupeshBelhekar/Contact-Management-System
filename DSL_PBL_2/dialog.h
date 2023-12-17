//dialog.h
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include "LinkedList.h"

namespace Ui{
class Dialog;
}
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    void setContactsList(LinkedList *list);
    ~Dialog();

private slots:
    void onUpdateButtonClicked();

private:
    Ui::Dialog *ui;
    LinkedList *contactsList;
};

#endif // Dialog_H
