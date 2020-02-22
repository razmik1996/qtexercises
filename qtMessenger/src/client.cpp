#include "client.hpp"
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QInputDialog>
#include <QLabel>

int Client::count = 0;

Client::Client(QWidget* forDel)
{
    Q_UNUSED(forDel); // forDel parameter given for auto deleting
    mName = "unknow";
    mGridLayout = new QGridLayout(this);
    mTextEdit = new QTextEdit(this);
    mSend = new QPushButton("Send", this);
    mOnlineLabel = new QLabel(this);
    mLabel = new QTextEdit(this);

    mLabel->setReadOnly(true);
    mLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mGridLayout->addWidget(mLabel, 0, 0, 2, 3);
    mGridLayout->addWidget(mOnlineLabel, 2, 0, 1, 3);
    mGridLayout->addWidget(mTextEdit, 3, 0, 2, 3);
    mGridLayout->addWidget(mSend, 5, 0, 1, 3);

    mOnlineLabel->setStyleSheet("QLabel{border-radius: 5px; background: #0cd6e8; color: #4A0C46;}");

    connect(mSend, SIGNAL(clicked()), this, SLOT(sendEmitor()));
    connect(mTextEdit, SIGNAL(textChanged()), this, SLOT(onlineDisplayEmitor()));
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
    mOnlineLabel->setText(" ");
    mLabel->setAlignment(Qt::AlignRight);
    mLabel->update();
}

void Client::sendEmitor()
{
    QString qstr = mTextEdit->toPlainText();
    mTextEdit->clear();
    emit send(qstr);
}

void Client::onlineDisplayEmitor()
{
    QString qstr = mTextEdit->toPlainText();
    emit onlineDisplay(qstr);
}

void Client::displayOnLabel(const QString &qstr)
{
    mOnlineLabel->setText(qstr);
}