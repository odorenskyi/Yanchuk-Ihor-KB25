#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

// Підключаємо заголовковий файл твоєї статичної бібліотеки
// Переконайся, що шлях до нього налаштовано у Build Options проекту TestDriver
#include "Modules_Yanchuk.h"

using namespace std;

// Функція для автоматизованого тестування задачі 10.1
void test_task_10_1() {
    cout << "=== Запуск тесту для задачі 10.1 ===" << endl;

    string input_filename = "test_input_10_1.txt";
    string output_filename = "test_output_10_1.txt";

    // КРОК А1: Драйвер створює вхідний файл та записує в нього тестовий текст
    // Текст відповідає Варіанту 14
    ofstream create_input(input_filename);
    if (create_input.is_open()) {
        create_input << "Якщо у тебе є який талант,\n"
                     << "То будуть вороги обов'язково,\n"
                     << "Бо бездарі від заздрощів готові\n"
                     << "Паплюжити й ганьбити все підряд.\n"
                     << "/ Віталій Іващенко /\n";
        create_input.close();
        cout << "[ INFO ] Вхідний файл успішно згенеровано." << endl;
    } else {
        cout << "[ ERROR ] Не вдалося створити вхідний файл для тесту." << endl;
        return;
    }

    // КРОК А2: Викликається функція з іменами файлів як аргументами
    task_10_1(input_filename, output_filename);

    // КРОК А3: Відкривається модифікований файл, зчитується текст і порівнюється з очікуваним
    ifstream check_output(output_filename);
    if (!check_output.is_open()) {
        cout << "[ FAILED ] Тест 10.1: Вихідний файл не був створений функцією!" << endl;
        return;
    }

    // Зчитуємо весь вміст вихідного файлу в один рядок для зручного пошуку
    string output_content((istreambuf_iterator<char>(check_output)), istreambuf_iterator<char>());
    check_output.close();

    // Визначаємо очікувані результати (Expected Results)
    // 1. У вірші великі літери: Я, Т, Б, П, В, І
    bool test_capitals_passed = (output_content.find("ЯТБПВІ") != string::npos);

    // 2. Третій рядок вірша ("Бо бездарі від заздрощів готові") не закінчується розділовим знаком
    bool test_punct_passed = (output_content.find("НЕ кожен рядок") != string::npos);

    // КРОК А4: Результат порівняння виводиться у стандартний потік
    if (test_capitals_passed && test_punct_passed) {
        cout << "[ PASSED ] Тест 10.1: Функція відпрацювала коректно!" << endl;
    } else {
        cout << "[ FAILED ] Тест 10.1: Результат не відповідає очікуванням." << endl;
        if (!test_capitals_passed) cout << "  -> Помилка: Неправильно знайдені великі літери (очікувалось ЯТБПВІ)." << endl;
        if (!test_punct_passed) cout << "  -> Помилка: Неправильно визначено наявність розділових знаків у кінці рядків." << endl;
    }

    cout << "====================================" << endl << endl;
}

int main() {
    // Встановлюємо локаль для коректної роботи з кирилицею
    // Для Windows часто працює ".1251" або "ukr", для Linux - "uk_UA.UTF-8"
    setlocale(LC_ALL, "ukr");

    // Запускаємо тест
    test_task_10_1();



    return 0;
}
