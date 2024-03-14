#include <iostream>
using namespace std;

int* inputArray(int size) {
    cout << "Input your Array: ";
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
    return arr;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int findNum(int arr[], int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            cout << "Your number (" << num << ") has index: " << i << endl;
            return 0;
        }
    }
    cout << "Your number (" << num << ") not found." << endl;
    return 0;
}

void evenNumCounter(int arr[], int size) {
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        if(arr[i] % 2 == 0){
            counter++;
        }
    }
    cout << "Array has " << counter << " even numbers." << endl;
}

int main()
{
    const int size = 10;
    int* arr = inputArray(size);
    printArray(arr, size);

    int numToFind;
    cout << "Input your number to find: ";
    cin >> numToFind;
    findNum(arr, size, numToFind);

    evenNumCounter(arr, size);
    delete arr;
    return 0;
}
