#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Tutorial 13 - Game Over");

    int score = 0;

    QLabel *scoreLabel = new QLabel("Score: 0");
    QLabel *statusLabel = new QLabel("Game running...");
    QPushButton *collectButton = new QPushButton("Collect Cookie");
    QPushButton *resetButton = new QPushButton("Restart");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(scoreLabel);
    layout->addWidget(statusLabel);
    layout->addWidget(collectButton);
    layout->addWidget(resetButton);

    window.setLayout(layout);
    window.resize(300, 180);

    QObject::connect(collectButton, &QPushButton::clicked, [&]() {
        if (score < 30)
        {
            score += 10;
            scoreLabel->setText("Score: " + QString::number(score));
        }

        if (score >= 30)
        {
            statusLabel->setText("GAME OVER - Final Score: " + QString::number(score));
            collectButton->setEnabled(false);
        }
    });

    QObject::connect(resetButton, &QPushButton::clicked, [&]() {
        score = 0;
        scoreLabel->setText("Score: 0");
        statusLabel->setText("Game running...");
        collectButton->setEnabled(true);
    });

    window.show();

    return app.exec();
}