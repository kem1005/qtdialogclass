#ifndef BYTERCONVETER_H
#define BYTERCONVETER_H

#include <QDialog>
#include <QString>
class QLineEdit;
class QPushButton;
class byterconveter : public QDialog
{
    Q_OBJECT

public:
    byterconveter(QWidget *parent = nullptr);
    ~byterconveter();
private:
    QLineEdit* display;
    QString currentNumber;
    QString operatorSymbol;
    double storedValue;
    bool isHexMode;
    
    void calculate();
    
private slots:
    void numberClicked();
    void operatorClicked();
    void equalsClicked();
    void hexModeClicked();
    void decModeClicked();
    void clearClicked();
};
#endif // BYTERCONVETER_H
