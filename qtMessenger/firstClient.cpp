#include "firstClient.hpp"
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>

FirstClient::FirstClient()
{
    mGridLayout = new QGridLayout(this);
    mTextEdit = new QTextEdit(this);
    mSend = new QPushButton("Send", this);
    mLabel = new QLabel(this);

    mLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mGridLayout->addWidget(mLabel, 0, 0, 2, 3);
    mGridLayout->addWidget(mTextEdit, 2, 0, 2, 3);
    mGridLayout->addWidget(mSend, 5, 0, 1, 3);

    connect(mSend, SIGNAL(clicked()), this, SLOT(sendEmitor()));
}

FirstClient::~FirstClient()
{

}

void FirstClient::display(const QString &qstr) 
{
    mLabel->setText(qstr);
    mLabel->update();
}

void FirstClient::sendEmitor()
{
    QString qstr = mTextEdit->toPlainText();
    emit send(qstr);
}
