#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.resize(300, 160);
    window.setWindowTitle("Tutorial 3 - Family Values");

    QPushButton quit("Quit", &window);
    quit.setFont(QFont("Times", 18, QFont::Bold));
    quit.setGeometry(40, 55, 220, 50);

    QObject::connect(&quit, &QPushButton::clicked, &app, &QApplication::quit);

    window.show();

    return app.exec();
}