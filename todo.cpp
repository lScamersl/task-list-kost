#include <iostream>
#include <vector>
#include <string>
#include <limits>

std::vector<std::string> tasks;

void showMenu() {
    std::cout << "\nСписок задач\n";
    std::cout << "1. Добавить задачу\n";
    std::cout << "2. Показать задачи\n";
    std::cout << "3. Удалить задачу\n";
    std::cout << "4. Выход\n";
}

void addTask() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите текст задачи: ";
    std::string text;
    std::getline(std::cin, text);
    
    if (!text.empty()) {
        tasks.push_back(text);
        std::cout << "Задача добавлена.\n";
    } else {
        std::cout << "Текст задачи не может быть пустым.\n";
    }
}

void listTasks() {
    if (tasks.empty()) {
        std::cout << "Список задач пуст.\n";
    } else {
        std::cout << "\nЗадачи:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

int main() {
    while (true) {
        showMenu();
        std::cout << "Выберите пункт меню: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            addTask();
        } else if (choice == 2) {
            listTasks();
        } else if (choice == 3) {
            std::cout << "Удаление задач будет реализовано позже.\n";
        } else if (choice == 4) {
            std::cout << "Выход из программы.\n";
            break;
        } else {
            std::cout << "Некорректный пункт меню.\n";
        }
    }
    return 0;
}
13:23
