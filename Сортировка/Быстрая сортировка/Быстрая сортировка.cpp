#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <fstream> 
#define size 50000
// Функция для обмена значениями двух элементов
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разделения массива на две части относительно опорного элемента
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // выбор опорного элемента
    int i = low - 1; // индекс меньшего элемента
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); // меняем местами arr[i] и arr[j]
        }
    }
    swap(arr[i + 1], arr[high]); // меняем местами arr[i + 1] и arr[high]
    return i + 1;
}

// Реализация быстрой сортировки
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high); // получаем индекс опорного элемента
        quickSort(arr, low, pivot - 1); // сортируем элементы перед опорным элементом
        quickSort(arr, pivot + 1, high); // сортируем элементы после опорного элемента
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(NULL);
    std::vector<int> arr; // Создали верктор с числами
    //std::cout << "Введите количество элементов массива "; std::cin >> size;
    //for (int i = 0; i < size; i++) {
     //   arr.push_back(rand() % 100);
    //}
    std::ifstream input_file("1.txt");
    if (!input_file.is_open()) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return 1;
    }
    int value;
    for (int i = 0; i < size; i++) {
        input_file >> value;
        arr.push_back(value);
    }
    input_file.close();
    int n = 50000; // Получили его размер 
    std::cout << '[';
    for (int i : arr) {
       std::cout << i << " "; 
    }
    std::cout << "]\n";
    //std::cout << "\n";
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, n - 1); // Вызвали фкнкцию быстрой сортировки
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Время выполнения сортировки: " << duration.count() << " микросекунд" << std::endl;
    //std::cout << "Отсортированный массив\n";
    //for (int i : arr) {
    //    std::cout << i << " "; // Вывкли отсортированный вектор 
    //}
    return 0;
}