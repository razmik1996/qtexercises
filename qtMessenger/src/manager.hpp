#ifndef MANAGER_HPP
#define MANAGER_HPP
#include "client.hpp"
#include <QObject>

class QGridLayout;

class Manager : QObject {
    Q_OBJECT
private: // members
    QWidget* mWidget1;
    QWidget* mWidget2;
    QGridLayout* mLayout1;
    QGridLayout* mLayout2;
    Client* mFirstClient;
    Client* mSecondClient;
    QPushButton* mCloseButton1;
    QPushButton* mCloseButton2;
public: // Constructor and Destructor
    /**
    @brief Constructor for manager
    */
    Manager();
    /**
    @brief Destructor for manager
    */
    ~Manager();
public: // Methods
    /**
    @brief Show function show two windows
    */
    void show();
};

#endif //MANAGER_HPP
