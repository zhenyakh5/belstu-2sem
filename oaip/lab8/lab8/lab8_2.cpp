#include <iostream>

using namespace std;

// Определение структуры очереди
struct Queue {
    char data;        // данные элемента
    Queue* next;      // указатель на следующий элемент
};

// Функция для ввода символов в очередь
void inputQueue(Queue*& front, Queue*& rear, int maxSize) {
    cout << "Введите символы для очереди (максимальный размер очереди: " << maxSize << "):" << endl;
    char ch;
    for (int i = 0; i < maxSize; ++i) {
        cout << "Символ " << i + 1 << ": ";
        cin >> ch;
        // Создание нового узла очереди и заполнение его данными
        Queue* newNode = new Queue;
        newNode->data = ch;
        newNode->next = nullptr;
        // Если очередь пуста, новый узел становится как передний, так и задний элементом
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            // Иначе новый узел добавляется в конец очереди
            rear->next = newNode;
            rear = newNode;
        }
    }
}

// Функция для вывода содержимого очереди
void displayQueue(Queue* front) {
    cout << "Содержимое очереди:" << endl;
    // Перебор элементов очереди и вывод их данных
    while (front != nullptr) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}

// Функция для удаления элементов очереди до заданного символа
void removeUntil(Queue*& front, Queue*& rear, char target) {
    // Проверяем, есть ли символ в очереди
    Queue* current = front;
    bool found = false;
    while (current != nullptr) {
        if (current->data == target) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found) {
        // Удаляем элементы до заданного символа
        while (front != nullptr && front->data != target) {
            Queue* temp = front;
            front = front->next;
            delete temp;
        }
        if (front != nullptr) {
            // Удаляем узел с заданным символом
            cout << "Элементы до символа '" << target << "' (включительно) удалены из очереди." << endl;
            Queue* temp = front;
            front = front->next;
            delete temp;
        }
        if (front == nullptr) {
            rear = nullptr;
        }
    }
    else {
        cout << "Символ '" << target << "' не найден в очереди." << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int maxSize;
    cout << "Введите максимальный размер очереди: ";
    cin >> maxSize;

    Queue* front = nullptr;  // Указатель на передний элемент очереди
    Queue* rear = nullptr;   // Указатель на задний элемент очереди

    inputQueue(front, rear, maxSize);  // Ввод элементов в очередь

    cout << "Введите эталонный символ: ";
    char target;
    cin >> target;

    removeUntil(front, rear, target);  // Удаление элементов до заданного символа

    displayQueue(front);  // Вывод содержимого очереди

    return 0;
}
