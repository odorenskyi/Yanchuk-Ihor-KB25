#ifndef MODULES_YANCHUK_H_INCLUDED
#define MODULES_YANCHUK_H_INCLUDED
#include <cmath>
#include <string>
using namespace std;

double s_calculation(double x, double y, double z);

double salary_calculation(double salary, int experience, double office_salary);

void temperature_calculation(const double temps[], int size, double& avg_celsius, double& avg_fahrenheit);

double analyze_bit(unsigned int N);

string getAuthorInfo();

string extractUppercase(const string& filename);

string checkPunctuation(const string& filename);

void writePoemVertically(const string& inputFile, const string& outputFile);

string getFileSizeKB(const string& filename);

string getCurrentDateTime();

string toBinary(int b);

class ClassLab12_Yanchuk {
private:
    // Закриті атрибути (довжини сторін білборда)
    double sideA;
    double sideB;

public:
    // Конструктор з параметрами за замовчуванням
    ClassLab12_Yanchuk(double a = 1.0, double b = 1.0);

    // Геттери (функції для отримання значень)
    double getSideA() const;
    double getSideB() const;
    double getArea() const;

    // Сеттери (функції для зміни значень)
    void setSideA(double a);
    void setSideB(double b);
};

#endif // MODULES_YANCHUK_H_INCLUDED
