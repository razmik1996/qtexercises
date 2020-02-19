#ifndef PRINTWIDGET_HPP
#define PRINTWIDGET_HPP
#include <QWidget>

class QGridLayout;
class QPushButton;
class QLineEdit;

class PrintWidget : public QWidget {
    Q_OBJECT
private: //Members
    QGridLayout* mLayout;
    QPushButton* mCloseButton;
    QPushButton* mPrintButton;
    QLineEdit* mLineEdit;
public: //Constructors and Destructor
    PrintWidget();
    ~PrintWidget();
public slots:
    void display();
};

#endif// PRINTWIDGET_HPP
