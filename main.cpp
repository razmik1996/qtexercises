#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QObject>
#include <QTextEdit>
#include <QLayout>
#include <QMainWindow>
#include <QGridLayout>


int main(int argc, char** argv) {
    

    QApplication app(argc,argv);
    
    QMainWindow window;
    QWidget* widget = new QWidget(&window);
    QGridLayout* layout = new QGridLayout(widget);
    window.setCentralWidget(widget);
    widget->setLayout(layout);

    QPushButton* closeButton = new QPushButton("Exit", widget);
    QTextEdit* textForChange = new QTextEdit("Enter your text here!!!", widget);
    QPushButton* textPrint = new QPushButton("Print", widget);
    
    layout->addWidget(textForChange, 0, 0, 3, 4);
    layout->addWidget(textPrint, 4, 0);
    layout->addWidget(closeButton, 4, 1);

    window.show();

    QObject::connect(closeButton, SIGNAL(clicked()), &app, SLOT(quit())); 
    return app.exec();
}
