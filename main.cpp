#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTextStream input(stdin);
    QTextStream output(stdout);

    output << "Enter a string: ";
    output.flush();

    QString inputString = input.readLine(); // <-- input

    if (inputString == "100") {
        int* ptr = nullptr;
        output << *ptr << Qt::endl; // crash input 100 
    }

    output << "You entered: " << inputString << Qt::endl;
    return a.exec();
}
