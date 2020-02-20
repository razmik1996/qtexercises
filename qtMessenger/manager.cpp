#include "manager.hpp"
#include <QGridLayout>
#include <QPushButton>

Manager::Manager()
{
    mLayout = new QGridLayout(this);
    firstClient = new FirstClient();
    secondClient = new FirstClient();
    closeButton = new QPushButton("Close", this);
    
    mLayout->addWidget(firstClient, 0, 0);
    mLayout->addWidget(secondClient, 0, 1);
    mLayout->addWidget(closeButton, 1, 0);
    mLayout->setSpacing(0);
    
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(firstClient, SIGNAL(send(QString)), secondClient, SLOT(display(QString)));
    connect(secondClient, SIGNAL(send(QString)), firstClient, SLOT(display(QString)));
}

Manager::~Manager()
{
    delete firstClient;
    delete secondClient;
}
