#include <iostream>
#include <fstream>
#include <string>
#include "Modules_Yanchuk.h" // Підключаємо наш клас

using namespace std;

int main() {

    setlocale(LC_ALL, "ukr");

    // 1. Перевірка місця розташування файлу main.cpp
    string currentFile = __FILE__;
    bool isCorrectPath = (currentFile.find("\\Lab12\\prj\\Yanchuk-task_12_1") != string::npos) ||
                         (currentFile.find("/Lab12/prj/Yanchuk-task_12_1") != string::npos);

    // Якщо шлях порушено
    if (!isCorrectPath) {
        // Видаємо 100 звукових сигналів
        for (int i = 0; i < 100; ++i) {
            cout << '\a';
        }

        // Записуємо повідомлення у файл TestResults.txt
        ofstream outFile("TestResults.txt");
        if (outFile.is_open()) {
            outFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
            outFile.close();
        }

        cout << "Помилка: файл main.cpp не знаходиться в теці \\Lab12\\prj" << endl;
        return 1; // Виходимо з програми, оскільки умови порушено
    }

    // 2. Якщо шлях вірний — виконуємо логіку роботи з об'єктом
    cout << "Шлях компіляції вірний. Створюємо об'єкт білборда..." << endl;

    // Створюємо екземпляр класу (передаємо розміри сторін, наприклад 6.0 та 3.0)
    ClassLab12_Yanchuk billboard(6.0, 3.0);

    cout << "--- Початкові розміри ---" << endl;
    cout << "Сторона А: " << billboard.getSideA() << endl;
    cout << "Сторона B: " << billboard.getSideB() << endl;
    cout << "Початкова площа: " << billboard.getArea() << endl;

    // Змінюємо атрибути об'єкта
    cout << "\nЗмінюємо розміри на 12.5 та 4.0..." << endl;
    billboard.setSideA(12.5);
    billboard.setSideB(4.0);

    cout << "--- Оновлені розміри ---" << endl;
    cout << "Нова сторона А: " << billboard.getSideA() << endl;
    cout << "Нова сторона B: " << billboard.getSideB() << endl;
    cout << "Нова площа: " << billboard.getArea() << endl;

    return 0;
}
