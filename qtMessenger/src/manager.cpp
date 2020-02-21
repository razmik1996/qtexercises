#include "manager.hpp"
#include <QGridLayout>
#include <QPushButton>

Manager::Manager()
{
    mWidget2 = new QWidget();
    mWidget1 = new QWidget();
    mLayout1 = new QGridLayout(mWidget1);
    mFirstClient = new Client(mWidget1);
    mLayout2 = new QGridLayout(mWidget2);
    mSecondClient = new Client(mWidget2);
    mCloseButton1 = new QPushButton("Close", mWidget1);
    mCloseButton2 = new QPushButton("Close", mWidget2);
    
    mLayout1->addWidget(mFirstClient, 0, 0);
    mLayout2->addWidget(mSecondClient, 0, 0);
    mLayout1->addWidget(mCloseButton1, 1, 0);
    mLayout2->addWidget(mCloseButton2, 1, 0);
    mLayout1->setSpacing(0);
    mLayout2->setSpacing(0);
    
    mFirstClient->setName();
    mSecondClient->setName();

    connect(mCloseButton1, SIGNAL(clicked()), mWidget1, SLOT(close()));
    connect(mCloseButton2, SIGNAL(clicked()), mWidget2, SLOT(close()));
    connect(mFirstClient, SIGNAL(send(QString)), mSecondClient, SLOT(displayForOther(QString)));
    connect(mSecondClient, SIGNAL(send(QString)), mFirstClient, SLOT(displayForOther(QString)));
    connect(mFirstClient, SIGNAL(send(QString)), mFirstClient, SLOT(displayForMe(QString)));
    connect(mSecondClient, SIGNAL(send(QString)), mSecondClient, SLOT(displayForMe(QString)));
}

Manager::~Manager()
{

}

void Manager::show()
{
    mWidget2->show();
    mWidget1->show();
    mWidget1->move(350, 0);
}
