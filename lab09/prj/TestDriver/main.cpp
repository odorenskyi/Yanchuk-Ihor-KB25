#include <iostream>
#include <iomanip>
#include <string>


#include "Modules_Yanchuk.h"

using namespace std;


template <typename T_in, typename T_out>
void runTestCase(int testId, string taskName, T_in inputDesc, T_out expected, T_out actual) {
    cout << "Test Case ID: " << testId << " (" << taskName << ")" << endl;
    cout << "Input data: " << inputDesc << endl;
    cout << "Expected result: " << expected << endl;
    cout << "Actual result:   " << actual << endl;

    // Перевірка статусу тест-кейсу
    if (expected == actual) {
        cout << "Status: passed" << endl;
    } else {
        cout << "Status: failed" << endl;
    }
    cout << "---------------------------------------" << endl;
}

int main() {
    cout << "=== TestDriver: Модульне тестування функцій ===" << endl << endl;

    // ==========================================
    // ТЕСТУВАННЯ ЗАДАЧІ 9.1
    // ==========================================
    cout << ">>> Тестування функції для Задачі 9.1 <<<" << endl;

    // ПРИКЛАД 1 (заміни `task9_1` на свою реальну функцію та підстав свої типи)
    // int input9_1_1 = 5;
    // int expected9_1_1 = 25; // Очікуваний результат
    // int actual9_1_1 = task9_1(input9_1_1); // Виклик твоєї функції з бібліотеки
    // runTestCase(1, "Task 9.1", "a = 5", expected9_1_1, actual9_1_1);

    // ПРИКЛАД 2
    // int input9_1_2 = -2;
    // int expected9_1_2 = 4;
    // int actual9_1_2 = task9_1(input9_1_2);
    // runTestCase(2, "Task 9.1", "a = -2", expected9_1_2, actual9_1_2);

    // ПРИКЛАД 3
    // int input9_1_3 = 0;
    // int expected9_1_3 = 0;
    // int actual9_1_3 = task9_1(input9_1_3);
    // runTestCase(3, "Task 9.1", "a = 0", expected9_1_3, actual9_1_3);

    // ==========================================
    // ТЕСТУВАННЯ ЗАДАЧІ 9.2
    // ==========================================
    cout << ">>> Тестування функції для Задачі 9.2 <<<" << endl;

    // ПРИКЛАД для функції, яка приймає два або більше аргументів:
    // double input9_2_x = 2.5;
    // double input9_2_y = 4.0;
    // double expected9_2 = 10.0;
    // double actual9_2 = task9_2(input9_2_x, input9_2_y);
    // string inputDesc9_2 = "x = " + to_string(input9_2_x) + ", y = " + to_string(input9_2_y);
    // runTestCase(1, "Task 9.2", inputDesc9_2, expected9_2, actual9_2);




    // ==========================================
    // ТЕСТУВАННЯ ЗАДАЧІ 9.3
    // ==========================================
    cout << ">>> Тестування функції для Задачі 9.3 <<<" << endl;





    cout << "=== Тестування завершено ===" << endl;

    // Затримка екрану, щоб консоль не закривалась миттєво (зручно для копіювання у звіт)
    system("pause");
    return 0;
}
