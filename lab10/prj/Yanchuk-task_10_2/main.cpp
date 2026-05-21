#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

#include "Modules_Yanchuk.h"

using namespace std;

void test_task_10_2() {
    cout << "=== Запуск тесту для задачі 10.2 ===" << endl;
    string filename = "test_file_10_2.txt";

    // Створюємо файл з якимось початковим текстом
    ofstream create_file(filename);
    if (create_file.is_open()) {
        create_file << "Це тестовий рядок для перевірки розміру файлу.";
        create_file.close();
    }

    // Викликаємо твою функцію (вона має ДОПИСАТИ дані)
    task_10_2(filename);

    // Відкриваємо і читаємо, щоб перевірити, чи все додалося
    ifstream check_file(filename);
    if (check_file.is_open()) {
        string content((istreambuf_iterator<char>(check_file)), istreambuf_iterator<char>());
        check_file.close();

        // Перевіряємо, чи з'явилися ключові слова у файлі
        if (content.find("Об'єм цього файлу") != string::npos && content.find("Дата й час") != string::npos) {
            cout << "[ PASSED ] Тест 10.2: Розмір та час успішно дописані у файл!" << endl;
        } else {
            cout << "[ FAILED ] Тест 10.2: Дані не були дописані." << endl;
        }
    }
    cout << "====================================" << endl << endl;
}
int main() {
    // Встановлюємо локаль для коректної роботи з кирилицею
    // Для Windows часто працює ".1251" або "ukr", для Linux - "uk_UA.UTF-8"
    setlocale(LC_ALL, "ukr");

    // Запускаємо тест
    test_task_10_2();



    return 0;
