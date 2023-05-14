#include <iostream>
#include <fstream>
#include <vector>

// Функция для разделения массива на две части относительно опорного элемента
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Выбираем последний элемент в качестве опорного
    int i = (low - 1); // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++; // Увеличиваем индекс меньшего элемента
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Функция быстрой сортировки
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Разделяем массив и получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем две части массива
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Проверяем наличие файла input.txt
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cout << "Файл input.txt не найден. Создание файла..." << std::endl;

        // Создаем файл input.txt
        std::ofstream createFile("input.txt");
        createFile.close();

        std::cout << "Файл input.txt создан. Пожалуйста, добавьте значения для сортировки в файл и запустите программу снова." << std::endl;
        return 0;
    }

    std::vector<int> values;
    int value;
    while (inputFile >> value) {
        values.push_back(value);
    }
    inputFile.close();

    // Применение быстрой сортировки
    quickSort(values, 0, values.size() - 1);

    // Запись отсортированных значений в файл output.txt
    std::ofstream outputFile("output.txt", std::ofstream::out | std::ofstream::trunc);
    if (!outputFile) {
        std::cout << "Ошибка открытия файла output.txt." << std::endl;
        return 1;
    }

    for (int i = 0; i < values.size(); i++) {
        outputFile << values[i] << " ";
    }
    outputFile.close();

    std::cout << "Сортировка завершена. Результаты записаны в файл output.txt" << std::endl;

    return 0;
}
