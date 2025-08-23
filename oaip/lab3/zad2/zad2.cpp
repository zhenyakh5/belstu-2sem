#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 1024;
    char str[MAX_SIZE];
    cout << "Введите строку: ";
    cin.getline(str, MAX_SIZE);

    ofstream outFile("D:/University/oaip/2sem/lab3/zad2.txt");
    if (!outFile) {
        cerr << "Ошибка при открытии файла для записи.\n";
        return 1;
    }
    outFile << str;
    outFile.close();

    ifstream inFile("D:/University/oaip/2sem/lab3/zad2.txt");
    if (!inFile) {
        cerr << "Ошибка при открытии файла для чтения.\n";
        return 1;
    }
    inFile.getline(str, MAX_SIZE);
    inFile.close();

    int k;
    cout << "Введите длину первой подстроки: ";
    cin >> k;
    char firstPart[MAX_SIZE], secondPart[MAX_SIZE];
    int i;
    for (i = 0; i < k && str[i] != '\0'; ++i) {
        firstPart[i] = str[i];
    }
    firstPart[i] = '\0';

    int j = 0;
    while (str[i] != '\0') {
        secondPart[j++] = str[i++];
    }
    secondPart[j] = '\0';

    cout << "Первая подстрока: " << firstPart << endl;
    cout << "Вторая подстрока: " << secondPart << endl;

    return 0;
}