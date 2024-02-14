#include <iostream>
#include <vector>
#include <iomanip>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& desc) {
        tasks.emplace_back(desc);
        std::cout << "Task added: " << desc << std::endl;
    }

    void markTaskAsComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            std::cout << "Task marked as complete: " << tasks[index].description << std::endl;
        } else {
            std::cerr << "Invalid task index" << std::endl;
        }
    }

    void displayTasks() const {
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << std::setw(3) << i + 1 << ". ";
            if (tasks[i].completed) {
                std::cout << "[X] ";
            } else {
                std::cout << "[ ] ";
            }
            std::cout << tasks[i].description << std::endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "Options:" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Mark Task as Complete" << std::endl;
        std::cout << "3. Display Tasks" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore();  // Ignore newline character left in the buffer
                std::cout << "Enter task description: ";
                std::string desc;
                std::getline(std::cin, desc);
                toDoList.addTask(desc);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter task index to mark as complete: ";
                std::cin >> index;
                toDoList.markTaskAsComplete(index - 1);  // Adjust for 0-based indexing
                break;
            }
            case 3:
                toDoList.displayTasks();
                break;
            case 4:
                std::cout << "Quitting program." << std::endl;
                return 0;
            default:
                std::cerr << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
