#include <QApplication>
#include <QKeyEvent>
#include <QPainter>
#include <QWidget>

class GameWidget : public QWidget
{
private:
    int playerX;
    int playerY;
    static const int cellSize = 40;
    static const int rows = 8;
    static const int cols = 8;

public:
    GameWidget(QWidget *parent = nullptr)
        : QWidget(parent), playerX(1), playerY(1)
    {
        setWindowTitle("Tutorial 14 - Facing the Wall");
        setFixedSize(cols * cellSize, rows * cellSize);
        setFocusPolicy(Qt::StrongFocus);
    }

protected:
    void paintEvent(QPaintEvent *) override
    {
        QPainter painter(this);

        for (int y = 0; y < rows; y++)
        {
            for (int x = 0; x < cols; x++)
            {
                QRect cell(x * cellSize, y * cellSize, cellSize, cellSize);

                if (isWall(x, y))
                {
                    painter.fillRect(cell, Qt::black);
                }
                else
                {
                    painter.fillRect(cell, Qt::white);
                }

                painter.drawRect(cell);
            }
        }

        QRect playerCell(playerX * cellSize, playerY * cellSize, cellSize, cellSize);
        painter.fillRect(playerCell, Qt::yellow);
        painter.drawText(playerCell, Qt::AlignCenter, "P");
    }

    void keyPressEvent(QKeyEvent *event) override
    {
        int nextX = playerX;
        int nextY = playerY;

        if (event->key() == Qt::Key_Left)
        {
            nextX--;
        }
        else if (event->key() == Qt::Key_Right)
        {
            nextX++;
        }
        else if (event->key() == Qt::Key_Up)
        {
            nextY--;
        }
        else if (event->key() == Qt::Key_Down)
        {
            nextY++;
        }

        if (!isWall(nextX, nextY))
        {
            playerX = nextX;
            playerY = nextY;
            update();
        }
    }

private:
    bool isWall(int x, int y) const
    {
        if (x < 0 || x >= cols || y < 0 || y >= rows)
        {
            return true;
        }

        if (x == 0 || x == cols - 1 || y == 0 || y == rows - 1)
        {
            return true;
        }

        if (x == 4 && y >= 2 && y <= 5)
        {
            return true;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    GameWidget game;
    game.show();

    return app.exec();
}