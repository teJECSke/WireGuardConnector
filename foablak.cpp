#include "foablak.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSettings>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include "dbconnectiondialog.h"

FoAblak::FoAblak(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *menuBar = new QMenuBar;
    QMenu *menu = new QMenu("Menu");

    QAction *connectAction = new QAction("Connect", this);
    menu->addAction(connectAction);

    menuBar->addMenu(menu);
    setMenuBar(menuBar);

    connect(connectAction, &QAction::triggered, this, &FoAblak::connectSlot);
}

void FoAblak::connectSlot() {
    // Create a QSettings object
    QSettings settings("YourCompany", "YourApp");

    // Read the database connection parameters from the settings
    QString hostName = settings.value("db/hostName", "localhost").toString();
    QString databaseName = settings.value("db/databaseName", "myDatabase").toString();
    QString userName = settings.value("db/userName", "myUsername").toString();
    QString password = settings.value("db/password", "myPassword").toString();

    DbConnectionDialog *dialog = new DbConnectionDialog();
    if (dialog->exec() == QDialog::Accepted) {

        // Create a QSqlDatabase object
        QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

        // Set the connection parameters
        db.setHostName(hostName);
        db.setDatabaseName(databaseName);
        db.setUserName(userName);
        db.setPassword(password);



        // Open the connection
        if (!db.open()) {
            // Handle the error
            qDebug() << "Error: Unable to connect to the database.";
        } else {
            qDebug() << "Connected to the database.";
        }

    }
}

FoAblak::~FoAblak() {}
