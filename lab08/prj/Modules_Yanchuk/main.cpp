#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>

using namespace std;

double s_calculation(float x, float y, float z)
{
    float S;
    const double pi = 3.14159265358979323846;
    S=log(x) * sin(z) + (1.0 / 2.0 * pow(x, 2) - pow(sqrt(y + z), 2) - pow(x, 5)) / (10.0 * pi * pow(z, 4));
    return roundf(S * 100000.0f) / 100000.0f;
}

string printWindSpeedInfo(int bofort) {
    stringstream result;
    double minSpeed = 0, maxSpeed = 0;
    string description;

    switch (bofort) {
    case 0: minSpeed = 0; maxSpeed = 0.3; description = "Відсутність вітру. Дим піднімається прямо. Листя дерев нерухомі."; break;
    case 1: minSpeed = 0.3; maxSpeed = 1.5; description = "Дим 'пливе'. Флюгер не обертається."; break;
    case 2: minSpeed = 1.6; maxSpeed = 3.4; description = "Рух повітря відчувається обличчям. Шелестить листя."; break;
    case 3: minSpeed = 3.5; maxSpeed = 5.4; description = "Тріпоче листя, хитаються дрібні гілки. Майорять прапори."; break;
    case 4: minSpeed = 5.5; maxSpeed = 7.9; description = "Хитаються тонкі гілки дерев. Вітер піднімає пил та шматки паперу."; break;
    case 5: minSpeed = 8.0; maxSpeed = 10.7; description = "Хитаються великі гілки. На воді з’являються хвилі."; break;
    case 6: minSpeed = 10.8; maxSpeed = 13.8; description = "Хитаються великі гілки."; break;
    case 7: minSpeed = 13.9; maxSpeed = 17.1; description = "Хитаються невеликі стовбури дерев. На морі здіймаються хвилі."; break;
    case 8: minSpeed = 17.2; maxSpeed = 20.7; description = "Ламаються гілки дерев. Важко йти проти вітру."; break;
    case 9: minSpeed = 20.8; maxSpeed = 24.4; description = "Невеликі руйнування. Зриває покрівлі, руйнує димарі."; break;
    case 10: minSpeed = 24.5; maxSpeed = 28.4; description = "Значні руйнування. Дерева вириваються з корінням."; break;
    case 11: minSpeed = 28.5; maxSpeed = 32.6; description = "Великі руйнування."; break;
    case 12: minSpeed = 32.7; maxSpeed = 50.0; description = "Призводить до спустошень."; break;
    default:
        result << "Незадовільний бал Бофорда!" << endl;
        return result.str();
    }

    result << "Швидкість вітру: " << minSpeed << " - " << maxSpeed << " м/с ("
        << minSpeed * 3.6 << " - " << maxSpeed * 3.6 << " км/ч)\n"
        << "Опис: " << description << endl;

    return result.str();
}

string headCircumference(int headCircumference) {

    stringstream result;
    string size, category;

    if (headCircumference >= 53 && headCircumference <= 54) { size = "XS"; category = "Дорослі"; }
    else if (headCircumference >= 55 && headCircumference <= 56) { size = "S"; category = "Дорослі"; }
    else if (headCircumference >= 57 && headCircumference <= 58) { size = "M"; category = "Дорослі"; }
    else if (headCircumference >= 59 && headCircumference <= 60) { size = "L"; category = "Дорослі"; }
    else if (headCircumference >= 61 && headCircumference <= 62) { size = "XL"; category = "Дорослі"; }
    else if (headCircumference >= 48 && headCircumference <= 49) { size = "S"; category = "Діти"; }
    else if (headCircumference >= 50 && headCircumference <= 51) { size = "M"; category = "Діти"; }
    else if (headCircumference >= 52 && headCircumference <= 53) { size = "L"; category = "Діти"; }
    else { size = "Розмір не знайдений!"; }

    result << "Категорія: " << category << "\nРозмір шолома: " << size << endl;

    return result.str();
}

unsigned int countBits(unsigned int number) {
    if (number > 8999) {
        return 0;
    }

    bool isD10Set = (number & (1 << 9)) != 0;
    unsigned int count = 0;

    for (int i = 0; i < 32; i++) {
        bool bitIsSet = (number & (1 << i)) != 0;
        count += (isD10Set ? bitIsSet : !bitIsSet) ? 1 : 0;
    }

    return count;
}

void Information() {
    cout << "=======================================" << endl;
    cout << "        Лабораторна робота №9          " << endl;
    cout << "      Виконав: студент Ігор Янчук      " << endl;
    cout << "=======================================" << endl;
    cout << endl; // Додатковий порожній рядок для краси
}

// Функція для розв'язання задачі 10.1
void task_10_1(const string& input_file, const string& output_file) {
    // Відкриваємо вхідний файл для читання та вихідний для запису
    // Якщо вихідний файл існує, його вміст буде знищено (перезаписано)
    ifstream fin(input_file);
    ofstream fout(output_file);

    // Перевірка статусу відкриття файлових потоків
    if (!fin.is_open()) {
        cerr << "Помилка: не вдалося відкрити вхідний файл " << input_file << endl;
        return;
    }
    if (!fout.is_open()) {
        cerr << "Помилка: не вдалося відкрити вихідний файл " << output_file << endl;
        fin.close();
        return;
    }

    string line;
    string uppercase_letters = "";
    int line_count = 0;
    bool all_punct = true;

    // Зчитуємо файл по рядках
    while (getline(fin, line)) {
        if (line.empty()) continue; // Пропускаємо порожні рядки

        line_count++;

        // Шукаємо символи верхнього регістру
        for (char c : line) {
            // isupper коректно працюватиме з кирилицею,
            // якщо у функції main() встановлено правильну локаль
            if (isupper((unsigned char)c)) {
                uppercase_letters += c;
            }
        }

        // Перевіряємо, чи закінчується рядок розділовим знаком
        // Спочатку відкидаємо можливі невидимі символи кінця рядка (наприклад, \r у Windows)
        while (!line.empty() && (line.back() == ' ' || line.back() == '\r' || line.back() == '\t')) {
            line.pop_back();
        }

        if (!line.empty()) {
            char last_char = line.back();
            // Перевіряємо, чи є останній символ розділовим знаком
            if (!ispunct((unsigned char)last_char)) {
                all_punct = false;
            }
        }
    }

    // Записуємо результати у вихідний файл
    // 1. Авторська інформація (інтегровані твої дані)
    fout << "=== Авторська інформація ===\n";
    fout << "Розробник: Янчук Ігор\n";
    fout << "Установа: КБ-25\n";
    fout << "Місто: Кропивницький, Україна\n";
    fout << "Рік розробки: 2026\n\n";

    // 2. Всі символи верхнього регістру
    fout << "=== Символи верхнього регістру ===\n";
    if (uppercase_letters.empty()) {
        fout << "Не знайдено.\n\n";
    } else {
        fout << uppercase_letters << "\n\n";
    }

    // 3. Повідомлення про форматування вірша
    fout << "=== Аналіз форматування тексту ===\n";
    if (all_punct) {
        fout << "Кожен рядок тексту закінчується розділовим знаком.\n";
    } else {
        fout << "НЕ кожен рядок тексту закінчується розділовим знаком.\n";
    }

    // Якщо рядків 4 (лише вірш) або 5 (4 рядки вірша + 1 рядок автора), вважаємо умову виконаною
    if (line_count >= 4 && line_count <= 5) {
        fout << "Вірш подано одним стовпчиком з чотирьох рядків.\n";
    } else {
        fout << "Текст НЕ відповідає формату стовпчика з чотирьох рядків (фактично рядків: " << line_count << ").\n";
    }

    // Закриваємо всі відкриті файлові потоки
    fin.close();
    fout.close();
}
