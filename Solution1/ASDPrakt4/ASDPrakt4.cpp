#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int* inputArray(int size) {
    /*srand(time(NULL));*/
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];/*rand() % 9 + 1;*/
    }
    return arr;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int* bubbleSort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмін елементів, якщо вони в неправильному порядку
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}



void findNum(int arr[], int size, int num) {
    int left = 0, right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "[left: " << left << "] " << "[mid: " << mid << "] " << "[right: " << right << "] " << endl;
        //Якщо знайдено елемент на середині
        if (arr[mid] == num) {
            result = mid;
            break;
        }

        // Якщо елемент більший, ігноруємо ліву частину
        if (arr[mid] < num) {
            left = mid + 1;
        }
        // Якщо елемент менший, ігноруємо праву частину
        else {
            right = mid - 1;
        }
    }
    if (result == -1) {
        cout << "Element was not found";
    }
    else
    {
        cout << "Element  was found in position: " << result;
    }
}

int main()
{
    const int size = 10;
    int* arr = inputArray(size);
    cout << "Your array: ";
    printArray(arr, size);

    arr = bubbleSort(arr, size);
    cout << "Sorted array: ";
    printArray(arr, size);

    int numToFind;
    cout << "Input your number to find: ";
    cin >> numToFind;
    findNum(arr, size, numToFind);
}