#ifndef BYTERCONVETER_H
#define BYTERCONVETER_H

#include <QDialog>
class QLineEdit;
class byterconveter : public QDialog
{
    Q_OBJECT

public:
    byterconveter(QWidget *parent = nullptr);
    ~byterconveter();
private:
    QLineEdit* decEdit;
    QLineEdit* hexEdit;
    QLineEdit* binEdit;
private slots:
    void decChanged (const QString&);
    void hexChanged (const QString&);
    void binChanged (const QString&);
};
#endif // BYTERCONVETER_H
