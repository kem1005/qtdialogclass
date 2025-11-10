#include "byterconveter.h"
#include<QLineEdit>
#include<QPushButton>
#include<QVBoxLayout>
#include<QGridLayout>

byterconveter::byterconveter(QWidget *parent)
    : QDialog(parent), currentNumber("0"), storedValue(0), isHexMode(false)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    
    // Display
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(40);
    QFont font = display->font();
    font.setPointSize(16);
    display->setFont(font);
    mainLayout->addWidget(display);
    
    // Button layout
    QGridLayout* buttonLayout = new QGridLayout;
    mainLayout->addLayout(buttonLayout);
    
    // Row 0: + - * /
    QPushButton* btnPlus = new QPushButton("+");
    QPushButton* btnMinus = new QPushButton("-");
    QPushButton* btnMultiply = new QPushButton("*");
    QPushButton* btnDivide = new QPushButton("/");
    
    buttonLayout->addWidget(btnPlus, 0, 0);
    buttonLayout->addWidget(btnMinus, 0, 1);
    buttonLayout->addWidget(btnMultiply, 0, 2);
    buttonLayout->addWidget(btnDivide, 0, 3);
    
    connect(btnPlus, &QPushButton::clicked, this, &byterconveter::operatorClicked);
    connect(btnMinus, &QPushButton::clicked, this, &byterconveter::operatorClicked);
    connect(btnMultiply, &QPushButton::clicked, this, &byterconveter::operatorClicked);
    connect(btnDivide, &QPushButton::clicked, this, &byterconveter::operatorClicked);
    
    // Row 1: 7 8 9 16進制
    QPushButton* btn7 = new QPushButton("7");
    QPushButton* btn8 = new QPushButton("8");
    QPushButton* btn9 = new QPushButton("9");
    QPushButton* btnHex = new QPushButton("16進制");
    
    buttonLayout->addWidget(btn7, 1, 0);
    buttonLayout->addWidget(btn8, 1, 1);
    buttonLayout->addWidget(btn9, 1, 2);
    buttonLayout->addWidget(btnHex, 1, 3);
    
    connect(btn7, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btn8, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btn9, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btnHex, &QPushButton::clicked, this, &byterconveter::hexModeClicked);
    
    // Row 2: 4 5 6 10進制
    QPushButton* btn4 = new QPushButton("4");
    QPushButton* btn5 = new QPushButton("5");
    QPushButton* btn6 = new QPushButton("6");
    QPushButton* btnDec = new QPushButton("10進制");
    
    buttonLayout->addWidget(btn4, 2, 0);
    buttonLayout->addWidget(btn5, 2, 1);
    buttonLayout->addWidget(btn6, 2, 2);
    buttonLayout->addWidget(btnDec, 2, 3);
    
    connect(btn4, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btn5, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btn6, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btnDec, &QPushButton::clicked, this, &byterconveter::decModeClicked);
    
    // Row 3: 1 2 3 =
    QPushButton* btn1 = new QPushButton("1");
    QPushButton* btn2 = new QPushButton("2");
    QPushButton* btn3 = new QPushButton("3");
    QPushButton* btnEquals = new QPushButton("=");
    
    buttonLayout->addWidget(btn1, 3, 0);
    buttonLayout->addWidget(btn2, 3, 1);
    buttonLayout->addWidget(btn3, 3, 2);
    buttonLayout->addWidget(btnEquals, 3, 3);
    
    connect(btn1, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btn2, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btn3, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btnEquals, &QPushButton::clicked, this, &byterconveter::equalsClicked);
    
    // Row 4: 0 C
    QPushButton* btn0 = new QPushButton("0");
    QPushButton* btnClear = new QPushButton("C");
    
    buttonLayout->addWidget(btn0, 4, 0, 1, 2);
    buttonLayout->addWidget(btnClear, 4, 2, 1, 2);
    
    connect(btn0, &QPushButton::clicked, this, &byterconveter::numberClicked);
    connect(btnClear, &QPushButton::clicked, this, &byterconveter::clearClicked);
    
    // Set minimum button sizes
    for(int i = 0; i < buttonLayout->count(); i++) {
        QWidget* widget = buttonLayout->itemAt(i)->widget();
        if(QPushButton* btn = qobject_cast<QPushButton*>(widget)) {
            btn->setMinimumSize(60, 40);
        }
    }
}

void byterconveter::numberClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    QString digit = button->text();
    
    if (currentNumber == "0") {
        currentNumber = digit;
    } else {
        currentNumber += digit;
    }
    
    if (isHexMode) {
        bool ok;
        int value = currentNumber.toInt(&ok);
        if (ok) {
            display->setText(QString::number(value, 16).toUpper());
        }
    } else {
        display->setText(currentNumber);
    }
}

void byterconveter::operatorClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    
    if (!currentNumber.isEmpty()) {
        if (!operatorSymbol.isEmpty()) {
            calculate();
        } else {
            storedValue = currentNumber.toDouble();
        }
    }
    
    operatorSymbol = button->text();
    currentNumber.clear();
}

void byterconveter::equalsClicked()
{
    if (!currentNumber.isEmpty() && !operatorSymbol.isEmpty()) {
        calculate();
        operatorSymbol.clear();
    }
}

void byterconveter::calculate()
{
    double secondValue = currentNumber.toDouble();
    double result = 0;
    
    if (operatorSymbol == "+") {
        result = storedValue + secondValue;
    } else if (operatorSymbol == "-") {
        result = storedValue - secondValue;
    } else if (operatorSymbol == "*") {
        result = storedValue * secondValue;
    } else if (operatorSymbol == "/") {
        if (secondValue != 0) {
            result = storedValue / secondValue;
        } else {
            display->setText("Error");
            currentNumber.clear();
            storedValue = 0;
            return;
        }
    }
    
    storedValue = result;
    
    // Format result
    if (result == static_cast<int>(result)) {
        currentNumber = QString::number(static_cast<int>(result));
    } else {
        currentNumber = QString::number(result);
    }
    
    if (isHexMode) {
        display->setText(QString::number(static_cast<int>(result), 16).toUpper());
    } else {
        display->setText(currentNumber);
    }
}

void byterconveter::hexModeClicked()
{
    isHexMode = true;
    if (!currentNumber.isEmpty()) {
        bool ok;
        int value = currentNumber.toInt(&ok);
        if (ok) {
            display->setText(QString::number(value, 16).toUpper());
        }
    }
}

void byterconveter::decModeClicked()
{
    isHexMode = false;
    if (!currentNumber.isEmpty()) {
        display->setText(currentNumber);
    }
}

void byterconveter::clearClicked()
{
    currentNumber = "0";
    operatorSymbol.clear();
    storedValue = 0;
    display->setText("0");
}

byterconveter::~byterconveter() {}

