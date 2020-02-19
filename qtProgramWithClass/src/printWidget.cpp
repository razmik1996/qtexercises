#include "printWidget.hpp"
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <iostream>
#include <string>

PrintWidget::PrintWidget()
{
    mLayout = new QGridLayout(this);
    mCloseButton = new QPushButton("Close", this);
    mPrintButton = new QPushButton("Print", this);
    mLineEdit = new QLineEdit(this);

    mLayout->addWidget(mLineEdit, 0, 0, 1, 2);
    mLayout->addWidget(mPrintButton, 1, 0);
    mLayout->addWidget(mCloseButton, 1, 1);

    connect(mCloseButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(mPrintButton, SIGNAL(clicked()), this, SLOT(display()));
}

PrintWidget::~PrintWidget()
{

}

void PrintWidget::display()
{
    QString qstr = mLineEdit->text();
    std::string str = qstr.toStdString();
    std::cout << str << std::endl;
}

