#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "LinkedList.h"
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
QT_END_NAMESPACE
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addContactButton_clicked();
    void on_searchContactButton_clicked();
    void on_deleteContactButton_clicked();
    void on_displayContactButton_clicked();
    void on_updateContactButton_clicked();
    void displayContacts();
private:
    Ui::MainWindow *ui;
    LinkedList *contactsList;
    Dialog *updateDialog;
};
#endif // MAINWINDOW_H
