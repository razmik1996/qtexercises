#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <QWidget>

class QGridLayout; // for Grid layout pointer
class QPushButton; // for Push Button pointer
class QTextEdit; //for Text edit pointers
class QLabel; //for display other message

class Client : public QWidget {
    Q_OBJECT
public: //static member
    static int count;
private: //members
    int id;
    QLabel* mOnlineLabel;
    QGridLayout* mGridLayout;
    QTextEdit* mTextEdit;
    QPushButton* mSend;
    QTextEdit* mLabel;
    QString mName;
public: //Constructors and Destructor
    /**
    @brief Constructor for Client
    @param forDel - for auto deletion
    */
    Client(QWidget* forDel);

    /**
    @brief Destructor
    */
    ~Client();
public slots: //slots
    /**
    @brief signal for Display on other label
    */
    void displayForOther(const QString &qstr);

    /**
    @brief signal for Display on other online label
    */
    void displayOnLabel(const QString &qstr);

    /**
    @brief signal for Display on my label
    */
    void displayForMe(const QString &qstr);
signals: //signal
    /**
    @brief signal for online display on label
    @param qstr - display qstr on 
    */
    void onlineDisplay(const QString &qstr);    
    
    /**
    @brief signal for display
    @param qstr - display qstr on label
    */
    void send(const QString &qstr);
private slots: //emitters
    void onlineDisplayEmitor();
    void sendEmitor();
public: //methods
    /**
    @brief Set name
    */
    void setName();
};

#endif // CLIENT_HPP
