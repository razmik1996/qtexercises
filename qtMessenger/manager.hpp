#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "firstClient.hpp"

class QGridLayout;

class Manager : public QWidget {
    Q_OBJECT
private: // members
    QGridLayout* mLayout;
    FirstClient* firstClient;
    FirstClient* secondClient;
    QPushButton* closeButton;
public: // Constructor and Destructor
    Manager();
    ~Manager();
};

#endif //MANAGER_HPP
