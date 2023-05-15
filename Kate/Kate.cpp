#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;


    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i >= 0; i--) {

        swap(arr[0], arr[i]);


        heapify(arr, i, 0);
    }
}

int main() {
    int n, choice;
    cout << "Введите количество элементов: ";
    cin >> n;

    int arr[n];

    cout << "1.Ссортировать массив с клавиатуры\n2.Сортировать рандомный массив\nВыбирите действие: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Введите элемент:" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " элемент массива: ";
            cin >> arr[i];
        }
    }
    else if (choice == 2) {
        srand(time(0));
        cout << "Рандомный массив: ";
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
            cout << arr[i] << " ";
        }

    }
    else {
        cout << "Ошибка!" << endl;
        return 0;
    }

    heapSort(arr, n);

    cout << "\nОтсортированный массив: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}