#include <QCoreApplication>
#include <QString>
#include <cstdlib>
#include <QDebug>



using namespace std;

int factorial(int x)
{
    int retVal = 0;

    switch (x) {
    case 0:
        retVal = 1;
        break;
    case 1:
        retVal = 1;
        break;
    case 2:
        retVal = 2;
        break;
    case 3:
        retVal = 6;
        break;
    case 4:
        retVal = 24;
        break;
    case 5:
        retVal = 120;
        break;
    case 6:
        retVal = 720;
        break;
    case 7:
        retVal = 5040;
        break;
    case 8:
        retVal = 40320;
        break;
    case 9:
        retVal = 362880;
        break;
    default:
        break;
    }

    return retVal;
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 100; i++)
    {
        //qDebug() << factorial(i);
        char * str[10] = {};
        //QString::number(i).unicode();

        while (!str)

    }

    QCoreApplication a(argc, argv);

    return a.exec();

}
