#ifndef FIRSTCLIENT_HPP
#define FIRSTCLIENT_HPP
#include <QWidget>

class QGridLayout;
class QPushButton;
class QLabel;
class QTextEdit;

class FirstClient : public QWidget {
    Q_OBJECT
private: //members
    QGridLayout* mGridLayout;
    QTextEdit* mTextEdit;
    QPushButton* mSend;
    QLabel* mLabel;
public: //Constructors and Destructor
    FirstClient();
    ~FirstClient();
public slots: //slots
    void display(const QString &qstr);
signals: //signal
    void send(const QString &qstr);
private slots: //emitors
    void sendEmitor();
};

#endif // FIRSTCLIENT_HPP
