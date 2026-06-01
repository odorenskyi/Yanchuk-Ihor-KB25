#include <iostream>
#include <string>

#include "Modules_Yanchuk.h"

using namespace std;



// Клас, що моделює сутність предметної області (Рекламний щит / Прямокутник)

class ClassLab12_Yanchuk {
private:
    // Закриті дані-члени класу (private) — Виноска 4
    double sideA; // Довжина суміжної сторони a
    double sideB; // Довжина суміжної сторони b

public:
    // 1. Конструктор класу — Виноска 1
    // Ініціалізує атрибути під час створення об'єкта
    ClassLab12_Yanchuk(double a, double b) {
        // Викликаємо сеттери, щоб одразу спрацювала валідація вхідних даних
        setSideA(a);
        setSideB(b);
    }

    // 2. Відкриті функції-члени для запису з валідацією (Сеттери) — Виноска 4
    // Забезпечують перевірку, щоб сторони прямокутника не були нульовими або від'ємними
    void setSideA(double a) {
        if (a > 0) {
            sideA = a;
        } else {
            cout << "[ВАЛІДАЦІЯ]: Помилка! Сторона 'a' має бути > 0. Встановлено значення за замовчуванням 1.0" << endl;
            sideA = 1.0;
        }
    }

    void setSideB(double b) {
        if (b > 0) {
            sideB = b;
        } else {
            cout << "[ВАЛІДАЦІЯ]: Помилка! Сторона 'b' має бути > 0. Встановлено значення за замовчуванням 1.0" << endl;
            sideB = 1.0;
        }
    }

    // 3. Відкриті функції-члени для читання (Геттери) — Виноска 2
    // Повертають поточні значення атрибутів об'єкта
    double getSideA() const {
        return sideA;
    }

    double getSideB() const {
        return sideB;
    }

    // 4. Метод обчислення площі — Виноска 3
    // Обчислює та повертає площу (S = a * b) за значеннями атрибутів
    double getArea() const {
        return sideA * sideB;
    }
};

// Головна функція для демонстрації роботи програми
int main() {
    setlocale(LC_ALL, "ukr");
    cout <<getAuthorInfo()<< endl;
    // Налаштування кодування для коректного відображення української мови в консолі
    setlocale(LC_ALL, "Ukrainian");

    cout << "=== ДЕМОНСТРАЦІЯ РОБОТИ ПРОГРАМИ ===" << endl;

    // Крок 1: Створення об'єкта з коректними початковими даними (стороны 5.5 та 3.0)
    cout << "\n1. Створення об'єкта billboard1 із параметрами (5.5, 3.0):" << endl;
    ClassLab12_Yanchuk billboard1(5.5, 3.0);

    // Демонстрація геттерів (Виноска 2) та обчислення площі (Виноска 3)
    cout << "Сторона a: " << billboard1.getSideA() << " м" << endl;
    cout << "Сторона b: " << billboard1.getSideB() << " м" << endl;
    cout << "Площа прямокутника (S = a * b): " << billboard1.getArea() << " кв. м" << endl;


    // Крок 2: Спроба створення об'єкта з некоректними даними для перевірки валідації
    cout << "\n2. Спроба створення об'єкта billboard2 з некоректними параметрами (-2.0, 0.0):" << endl;
    ClassLab12_Yanchuk billboard2(-2.0, 0.0);

    cout << "Значення після валідації в billboard2:" << endl;
    cout << "Сторона a: " << billboard2.getSideA() << " м" << endl;
    cout << "Сторона b: " << billboard2.getSideB() << " м" << endl;
    cout << "Площа об'єкта зі значеннями за замовчуванням: " << billboard2.getArea() << " кв. м" << endl;


    // Крок 3: Тестування зміни значень через сеттери (Виноска 4)
    cout << "\n3. Зміна параметрів першого об'єкта за допомогою сеттерів:" << endl;
    billboard1.setSideA(10.0);
    billboard1.setSideB(4.5);

    cout << "Нова сторона a: " << billboard1.getSideA() << " м" << endl;
    cout << "Нова сторона b: " << billboard1.getSideB() << " м" << endl;
    cout << "Нова обчислена площа: " << billboard1.getArea() << " кв. м" << endl;

    cout << "\n====================================" << endl;
    return 0;
}
