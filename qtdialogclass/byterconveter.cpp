#include "byterconveter.h"
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
byterconveter::byterconveter(QWidget *parent)
    : QDialog(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout (this);
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    mainLayout->addLayout (editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout (buttonLayout);

    QLabel* decLabel = new QLabel("10");
    QLabel* hexLabel = new QLabel("16");
    QLabel* binLabel = new QLabel("2");
    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout ->addWidget(decLabel,0,0);
    editLayout->addWidget(decEdit,0,1);
    editLayout->addWidget (hexLabel,1,0);
    editLayout->addWidget (hexEdit,1,1);
    editLayout->addWidget (binLabel,2,0);
    editLayout->addWidget (binEdit,2,1);

    QPushButton* exitButton = new QPushButton("離開");
    buttonLayout->addStretch();
    buttonLayout->addWidget (exitButton);

    connect (exitButton, SIGNAL (clicked()), this, SLOT (accept()));
    connect (decEdit, SIGNAL (textChanged (const QString&)), this, SLOT (decChanged (const QString&)));
}
void byterconveter::decChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok)
    {
        hexEdit->setText(QString::number(num, 16));
        binEdit->setText(QString::number(num, 2));
    }
    else
    {
        hexEdit->clear();
        binEdit->clear();
    }
}
void byterconveter:: hexChanged(const QString& newValue)
{
    bool ok;
    int num = newValue.toInt(&ok);
    if (ok)
    {
        hexEdit->setText(QString::number(num, 10));
        binEdit->setText(QString::number(num, 2));
    }
    else
    {
        hexEdit->clear();
        binEdit->clear();
    }
}
void byterconveter:: binChanged (const QString& newValue)
{}


byterconveter::~byterconveter() {}

