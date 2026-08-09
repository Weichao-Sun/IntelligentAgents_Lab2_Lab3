#include <QApplication>
#include <QFont>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton quit("Quit");
    quit.resize(120, 50);
    quit.setFont(QFont("Times", 18, QFont::Bold));

    QObject::connect(&quit, &QPushButton::clicked, &app, &QApplication::quit);

    quit.show();

    return app.exec();
}