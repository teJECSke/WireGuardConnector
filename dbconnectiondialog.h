#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class DbConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    DbConnectionDialog(QWidget *parent = nullptr) : QDialog(parent)
    {
        QLineEdit *hostLineEdit = new QLineEdit(this);
        QLineEdit *databaseLineEdit = new QLineEdit(this);
        QLineEdit *usernameLineEdit = new QLineEdit(this);
        QLineEdit *passwordLineEdit = new QLineEdit(this);
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        QPushButton *saveButton = new QPushButton(tr("Save"), this);

        QFormLayout *layout = new QFormLayout;
        layout->addRow(tr("Host:"), hostLineEdit);
        layout->addRow(tr("Database:"), databaseLineEdit);
        layout->addRow(tr("Username:"), usernameLineEdit);
        layout->addRow(tr("Password:"), passwordLineEdit);
        layout->addWidget(saveButton);

        setLayout(layout);

        connect(saveButton, &QPushButton::clicked, this, &DbConnectionDialog::accept);
    }
};