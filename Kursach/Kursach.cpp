#include <iostream>
#include <locale>
#include <chrono>
#include <ctime>


using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
 
        gap = (gap * 10) / 13;
        if (gap < 1)
            gap = 1;

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); 

    const int SIZE = 50; 
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr[i] =  (rand() % 201) - 100;
    }

    cout << "Исходный массив: ";
    printArray(arr, SIZE);

    int arrCopy1[SIZE];
    int arrCopy2[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arrCopy1[i] = arr[i];
        arrCopy2[i] = arr[i];
    }

    auto combSortStart = chrono::high_resolution_clock::now();
    combSort(arrCopy1, SIZE);
    auto combSortEnd = chrono::high_resolution_clock::now();

    double combSortTime = chrono::duration<double, milli>(combSortEnd - combSortStart).count();
    cout << "Время выполнения сортировки расчёской: " << combSortTime << " мс" << endl;

    auto bubbleSortStart = chrono::high_resolution_clock::now();
    bubbleSort(arrCopy2, SIZE);
    auto bubbleSortEnd = chrono::high_resolution_clock::now();

    double bubbleSortTime = chrono::duration<double, milli>(bubbleSortEnd - bubbleSortStart).count();
    cout << "Время выполнения пузырьковой сортировки: " << bubbleSortTime << " мс" << endl;

    cout << "Отсортированный массив (сортировка расчёской): ";
    printArray(arrCopy1, SIZE);

    cout << "Отсортированный массив (пузырьковая сортировка): ";
    printArray(arrCopy2, SIZE);

    return 0;
}

