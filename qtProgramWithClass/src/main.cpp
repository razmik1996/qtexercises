#include <QApplication>
#include "printWidget.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    PrintWidget* pWidget = new PrintWidget();
    
    pWidget->show();
    return app.exec();
}
