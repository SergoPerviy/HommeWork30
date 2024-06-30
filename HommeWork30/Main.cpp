#include <iostream>
#include <fstream>
#include <string>

//Функция overwrite, которая принимает путь к файлу и строку, которая полностью заменяет содержимое файла.

bool overwrite(const std::string& filePath, const std::string& newText) {
    
    // Открываем файл для перезаписи его содержимого

    std::ofstream outFile(filePath);
    if (!outFile) {
        // Если не удалось открыть файл для записи, возвращаем false
        return false;
    }

    // Перезаписываем содержимое файла переданным в в функцию текстом
    outFile << newText;

    // Закрываем файл после записи
    outFile.close();

    // Возвращаем true, указывая на успешную замену содержимого
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");

    /*
    Задача 1
    Напишите программу, в которой реализована запись в файл и считывание из него. Пользователь бесконечно вводит строки, которые записываются в файл, 
    пока не будет набрана строка end. После этого, программа выводит содержимое файла в консоль и удаляет его.
    */
    
    std::cout << "Задача №1:\n\n";
    std::ofstream outFile("file.txt", std::ios::out);
    if (!outFile) {
        std::cout << "Не удалось открыть файл для записи." << std::endl;
        return 1;
    }

    std::string input;
    while (true) {
        std::cout << "Введите строку (или 'end' для завершения): ";
        std::getline(std::cin, input);
        if (input == "end")
            break;
        outFile << input << std::endl;
    }
    outFile.close();

    std::ifstream inFile("file.txt", std::ios::in);
    if (!inFile) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1;
    }

    std::cout << "Содержимое файла:" << std::endl;
    while (std::getline(inFile, input)) {
        std::cout << input << std::endl;
    }
    inFile.close();

    /*
    Задача 2
    Создайте функцию overwrite, которая принимает путь к файлу и строку, которая полностью заменяет содержимое файла. 
    Если файла не существует, то функция возвращает false. Если замена прошла успешно, функция возвращает true.
    */

    std::cout << "\n\nЗадача №2:\n\n";
    std::string filePath = "file.txt";
    std::string newText = "Все, что было до меня обнуляй!";
    bool result = overwrite(filePath, newText);

    if (result) {
        std::cout << "Содержимое файла успешно заменено." << std::endl;
    }
    else {
        std::cout << "Не удалось заменить содержимое файла." << std::endl;
    }

    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cout << "Невозможно открыть файл" << std::endl;
        return 1;
    }

    std::string line;
    std::cout << "Измененное содержимое файла из Задачи №1:" << std::endl;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();

    //Функция удаления файла из Задачи №1, перенес в конец для теста Задачи №2.

    if (remove("file.txt") != 0) {
        std::cout << "Ошибка при удалении файла." << std::endl;
        return 1;
    }

    return 0;
}