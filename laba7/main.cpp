#include <QApplication>
#include "movesquare.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    moveSquare window;
    window.show();
    return app.exec();
}
