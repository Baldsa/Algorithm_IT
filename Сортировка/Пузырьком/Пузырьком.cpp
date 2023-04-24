#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>
#include <fstream> // библиотека для работы с файлами
#define size 50000
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    //std::cout << "Введите количество символов в массиве "; std::cin >> size;
    std::vector<int> my_vec;
    std::ifstream input_file("1.txt");
    if (!input_file.is_open()) {
        std::cout << "Не удалось открыть файл!" << std::endl;
        return 1;
    }
    int value;
    for (int i = 0; i < size; i++) {
        input_file >> value;
        my_vec.push_back(value);
    }
    //for (int i = 0; i <= size; i++) {
      //  my_vec.push_back(rand() % 100);
    //}
    input_file.close();
    std::cout << '[';
    for (int i = 0; i < size; i++) {
        std::cout << my_vec[i] << ",";
    }
    std::cout << "]\n";
    auto start = std::chrono::high_resolution_clock::now(); // начало измерения времени
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (my_vec[i] < my_vec[j]) {
                swap(my_vec[i], my_vec[j]);
            }
        }
    }
    std::cout << "\nОтсортированный массив \n[";
    for (int i = 0; i < size; i++) {
        std::cout << my_vec[i] << " ";
    }
    auto stop = std::chrono::high_resolution_clock::now(); // конец измерения времени
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Время выполнения сортировки: " << duration.count() << " микросекунд" << std::endl;

  
}
