#include <QApplication>
#include "manager.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    Manager manager;
    manager.show();

    return app.exec();
}
