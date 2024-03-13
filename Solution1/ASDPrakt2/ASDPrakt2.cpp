#include <iostream>
#include <Windows.h>

using namespace std;

// Функція для виведення масиву на екран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Завдання 1.Написати програму.З масиву Х довжиною 13,
    серед елементів якого є позитивні та негативні та нуль, сформуйте новий масив Y, 
    узявши тільки елементи з Х які більше по модулю заданого числа М. 
    Виведіть на екран число М та масиви заданий та отриманий.*/
void task1(int X[], int N, int M) {
    int Y[13];
    int newYSize = 0;

    cout << "Число M: " << M << endl;
    cout << "Масив Х: ";
    for (int i = 0; i < N; ++i) {
        cout << X[i] << " ";
        if (abs(X[i]) > M) {
            Y[newYSize++] = X[i];
        }
    }
    cout << endl << "Масив Y: ";
    printArray(Y, newYSize);
}

/* Завдання 2.Написати програму.У масиві цілих чисел, довжиною 13, усі негативні елементи замініть позитивними.
    Виведіть заданий та отриманий масиви на екран.*/
void task2(int X[], int N) {
    cout << "Заданий масив: ";
    for (int i = 0; i < N; ++i) {
        cout << X[i] << " ";
        if (X[i] < 0) {
            X[i] *= -1;
        }
    }
    cout << endl << "Отриманий масив: ";
    printArray(X, N);
}

/* Завдання 3.Написати програму.У масиві у порядку зменшення є купюри[1000, 500, 200, 100, 50, 20, 10, 5, 2, 1].
    Реалізовати видачу суми, введеної з екрану мінімальною кількістю купюр.*/
void task3(int amount) {
    const int cash[] = { 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    cout << "Сума: " << amount << endl;
    cout << "Купюри для видачі: ";
    for (int i = 0; i < size(cash); ++i) {
        int notes = amount / cash[i];
        if (notes > 0) {
            cout << cash[i] << "x" << notes << " ";
            amount %= cash[i];
        }
    }
    cout << endl;
}

/* Завдання 4.Написати програму.Дано два масива.Зробити третій масив з двох цих масивів.
    Розташування у масиві у порядку зростання.*/
void task4(int arr1[], int size1, int arr2[], int size2, int newArrSize) {
    int arr3[26];
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        }
        else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        arr3[k++] = arr1[i++];
    }

    while (j < size2) {
        arr3[k++] = arr2[j++];
    }

    cout << "Третій масив (у порядку зростання): ";
    printArray(arr3, size1 + size2);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int taskNumber;
    cout << "Оберіть завдання (1-4): ";
    cin >> taskNumber;

    switch (taskNumber) {
    case 1: {
        int X[13] = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6};
        int N = size(X);
        int M;
        cout << "Введіть число M: ";
        cin >> M;
        task1(X, N, M);
        break;
    }
    case 2: {
        int X[] = { -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6 };
        int N = size(X);
        task2(X, N);
        break;
    }
    case 3: {
        int amount;
        cout << "Введіть суму: ";
        cin >> amount;
        task3(amount);
        break;
    }
    case 4: {
        int arr1[] = { 1, 3, 5, 7, 9 };
        int arr2[] = { 2, 4, 6, 8, 10 };
        int size1 = size(arr1);
        int size2 = size(arr2);
        int newArrSize = size1 + size2;
        task4(arr1, size1, arr2, size2, newArrSize);
        break;
    }
    default:
        cout << "Невірний вибір!" << endl;
    }

    return 0;
}
