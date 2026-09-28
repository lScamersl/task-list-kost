#define NOMINMAX
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <windows.h> // Необходима для настройки кодировки консоли

std::vector<std::string> tasks;

void showMenu() {
    std::cout << "\n=== Список задач ===\n";
    std::cout << "1. Добавить задачу\n";
    std::cout << "2. Показать задачи\n";
    std::cout << "3. Удалить задачу\n";
    std::cout << "4. Выход\n";
    std::cout << "====================\n";
}

void addTask() {
    // Очищаем буфер ввода после выбора пункта меню
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Введите текст задачи: ";
    std::string text;
    std::getline(std::cin, text);

    if (!text.empty()) {
        tasks.push_back(text);
        std::cout << "Задача успешно добавлена.\n";
    }
    else {
        std::cout << "Текст задачи не может быть пустым.\n";
    }
}

void listTasks() {
    if (tasks.empty()) {
        std::cout << "Список задач пока пуст.\n";
    }
    else {
        std::cout << "\nВаши задачи:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

void deleteTask() {
    listTasks();
    if (tasks.empty()) {
        return;
    }

    std::cout << "Введите номер задачи для удаления: ";
    int num;
    std::cin >> num;

    // Проверка на то, что введено именно число
    if (std::cin.fail()) {
        std::cin.clear(); // Сбрасываем флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер
        std::cout << "Ошибка: нужно ввести целое число.\n";
        return;
    }

    if (num >= 1 && num <= static_cast<int>(tasks.size())) {
        std::string removed = tasks[num - 1];
        tasks.erase(tasks.begin() + num - 1);
        std::cout << "Задача \"" << removed << "\" успешно удалена.\n";
    }
    else {
        std::cout << "Ошибка: задачи с таким номером не существует.\n";
    }
}

int main() {
    // НАСТРОЙКА РУССКОГО ЯЗЫКА:
    // Устанавливаем кодировку Windows-1251 для ввода и вывода в консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true) {
        showMenu();
        std::cout << "Выберите пункт меню: ";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            continue;
        }

        switch (choice) {
        case 1:
            addTask();
            break;
        case 2:
            listTasks();
            break;
        case 3:
            deleteTask();
            break;
        case 4:
            std::cout << "Выход из программы. До свидания!\n";
            return 0;
        default:
            std::cout << "Некорректный пункт меню. Попробуйте снова.\n";
        }
    }
    return 0;
}