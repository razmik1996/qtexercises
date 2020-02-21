#include "client.hpp"
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QInputDialog>

int Client::count = 0;

Client::Client(QWidget* forDel)
{
    Q_UNUSED(forDel); // forDel parameter given for auto deleting
    mName = "unknow";
    mGridLayout = new QGridLayout(this);
    mTextEdit = new QTextEdit(this);
    mSend = new QPushButton("Send", this);
    mLabel = new QTextEdit(this);

    mLabel->setReadOnly(true);
    mLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mGridLayout->addWidget(mLabel, 0, 0, 2, 3);
    mGridLayout->addWidget(mTextEdit, 2, 0, 2, 3);
    mGridLayout->addWidget(mSend, 5, 0, 1, 3);

    connect(mSend, SIGNAL(clicked()), this, SLOT(sendEmitor()));
    count++;
    id = count;
}

Client::~Client()
{

}

void Client::setName() {
    QString qStr = "User Name for client ";
    QString number = QString::number(id);
    qStr.append(number);
    qStr.append(": ");
    mName = QInputDialog::getText(this, tr("Set name"), qStr);
    if(mName.isEmpty()) {
        mName = "unknow";
    }
}

void Client::displayForOther(const QString &qstr) 
{
    QString msg = mName;
    msg.append(": ");
    msg.append(qstr);
    mLabel->append(msg);
    mLabel->setAlignment(Qt::AlignLeft);
    mLabel->update();
}

void Client::displayForMe(const QString &qstr)
{
    mLabel->append(qstr);
    mLabel->setAlignment(Qt::AlignRight);
    mLabel->update();
}

void Client::sendEmitor()
{
    QString qstr = mTextEdit->toPlainText();
    mTextEdit->clear();
    emit send(qstr);
}
