#include <iostream>
#include <fstream>
#include <vector>

// ������� ��� ���������� ������� �� ��� ����� ������������ �������� ��������
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // �������� ��������� ������� � �������� ��������
    int i = (low - 1); // ������ �������� ��������

    for (int j = low; j <= high - 1; j++) {
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot) {
            i++; // ����������� ������ �������� ��������
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// ������� ������� ����������
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // ��������� ������ � �������� ������ �������� ��������
        int pi = partition(arr, low, high);

        // ���������� ��������� ��� ����� �������
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    // ��������� ������� ����� input.txt
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cout << "���� input.txt �� ������. �������� �����..." << std::endl;

        // ������� ���� input.txt
        std::ofstream createFile("input.txt");
        createFile.close();

        std::cout << "���� input.txt ������. ����������, �������� �������� ��� ���������� � ���� � ��������� ��������� �����." << std::endl;
        return 0;
    }

    std::vector<int> values;
    int value;
    while (inputFile >> value) {
        values.push_back(value);
    }
    inputFile.close();

    // ���������� ������� ����������
    quickSort(values, 0, values.size() - 1);

    // ������ ��������������� �������� � ���� output.txt
    std::ofstream outputFile("output.txt", std::ofstream::out | std::ofstream::trunc);
    if (!outputFile) {
        std::cout << "������ �������� ����� output.txt." << std::endl;
        return 1;
    }

    for (int i = 0; i < values.size(); i++) {
        outputFile << values[i] << " ";
    }
    outputFile.close();

    std::cout << "���������� ���������. ���������� �������� � ���� output.txt" << std::endl;

    return 0;
}
