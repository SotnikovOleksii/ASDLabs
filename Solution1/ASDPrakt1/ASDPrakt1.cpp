#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

/* Завдання 1.Написати програму.Дано три цілих числа.Вибрати з них ті, які належать інтервалу[1, №].
    Де №- остання цифра порядкового номеру у списку групи.*/
void task1(int a, int b, int c) {
    
    int n = 3;
    if (a >= 1 && a <= n)
        cout << a << " ";
    if (b >= 1 && b <= n)
        cout << b << " ";
    if (c >= 1 && c <= n)
        cout << c << " ";
    cout << endl;
}

/* Завдання 2.Написати програму.Дано 3 числа.Знайти максимальне серед них і вивести на екран.*/
void task2(int a, int b, int c) {
    int max = a;
    if (max < b) {
        max = b;
    }if (max < c) {
        max = c;
    }
    cout << "Максимальне серед чисел: " << max << endl;
}

/* Завдання 3.Написати програму.Знайти суму n елементів наступного ряду чисел : 1 - 0.5 0.25 - 0.125 ... n.
    Кількість елементів (n) вводиться з клавіатури. Вивести на екран кожен член ряду і його суму. 
    Вирішити задачу використовуючи циклічну конструкцію for. */
void task3(int n) {
    double sum = 0;
    double num = 1;
    cout << "Ряд чисел: ";
    for (int i = 0; i < n; i++) {
        cout << num << " ";
        sum += num;
        num /= -2;
    }
    cout << endl << "Сума: " << sum << endl;
}

/* Завдання 4.Написати програму.Дано ціле число, що не менше 2.Виведіть його найменший натуральний дільник, відмінний від 1. 
    Вирішити задачу використовуючи циклічну конструкцію while.
    (У циклі while в якості логічного виразу використовується команда n% i порівнювана з нулем.)*/
int task4(int n) {
    int i = 2;
    while (i <= n) {
        if (n % i == 0)
            return i;
        i++;
    }
}

/* Завдання 5.Написати програму.Програма має вивести ряд послідовності Фібоначчі.
    Кожен наступний член дорівнюється суммі двох попередніх. 0, 1, 1, 2, 3, 5, 8, 13……. */
void task5(int n) {
    int a = 0, b = 1, c;
    cout << "Послідовність Фібоначчі: ";
    cout << a << " ";
    for (int i = 0; i < n; i++) {
        cout << b << " ";
        c = a;
        a = b;
        b = c + a;
    }
    cout << endl;
}

/* Завдання 6.Написати програму.“Вгадайте число від 1 до 20” */
void task6() {
    srand(time(0));
    int secretNum = rand() % 21;
    int guess, attempts = 0;
    while (true) {
        cout << "Введіть число від 0 до 20: ";
        cin >> guess;
        if (guess < 0 || guess > 20) {
            cout << "Невірне значення" << endl;
            continue;
        }
        attempts++;
        if (guess < secretNum)
            cout << "Запропоноване число менше задуманого" << endl;
        else if (guess > secretNum)
            cout << "Запропоноване число більше задуманого" << endl;
        else {
            cout << "Ви вгадали число з " << attempts << " разу" << endl;
            break;
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int taskNumber;
    cout << "Оберіть завдання (1-6): ";
    cin >> taskNumber;

    switch (taskNumber) {
    case 1: {
        int a, b, c;
        cout << "Введіть три цілих числа: ";
        cin >> a >> b >> c;
        task1(a, b, c);
        break;
    }
    case 2: {
        int a, b, c;
        cout << "Введіть три числа: ";
        cin >> a >> b >> c;
        task2(a, b, c);
        break;
    }
    case 3: {
        int n;
        cout << "Введіть кількість елементів ряду: ";
        cin >> n;
        task3(n);
        break;
    }
    case 4: {
        int n;
        cout << "Введіть ціле число не менше 2: ";
        cin >> n;
        int divisor = task4(n);
        cout << "Найменший натуральний дільник: " << divisor << endl;
        break;
    }
    case 5: {
        int n;
        cout << "Введіть кількість елементів послідовності Фібоначчі: ";
        cin >> n;
        task5(n);
        break;
    }
    case 6: {
        task6();
        break;
    }
    default:
        cout << "Невірний вибір!" << endl;
    }

    return 0;
}
