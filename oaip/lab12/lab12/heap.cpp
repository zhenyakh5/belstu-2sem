#include "Heap.h"
#include <iostream>
#include <iomanip>

// Методы для структуры AAA
void AAA::print() {
    std::cout << x; // Вывод значения x структуры AAA
}

namespace heap {
    // Конструктор кучи
    Heap::Heap(int maxsize, CMP(*f)(void*, void*)) {
        size = 0; // Инициализация размера кучи как 0
        storage = new void* [maxSize = maxsize]; // Выделение памяти под хранилище элементов кучи
        compare = f; // Присвоение функции сравнения элементов
    }

    // Методы для работы с индексами элементов
    int Heap::left(int ix) {
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1); // Возвращает индекс левого потомка узла с индексом ix
    }

    int Heap::right(int ix) {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2); // Возвращает индекс правого потомка узла с индексом ix
    }

    int Heap::parent(int ix) {
        return (ix + 1) / 2 - 1; // Возвращает индекс родительского узла для узла с индексом ix
    }

    // Проверки на заполненность и пустоту кучи
    bool Heap::isFull() const {
        return (size >= maxSize); // Проверяет, заполнена ли куча
    }

    bool Heap::isEmpty() const {
        return (size <= 0); // Проверяет, пуста ли куча
    }

    // Методы для сравнения элементов
    const bool Heap::isLess(void* x1, void* x2) {
        return compare(x1, x2) == LESS; // Проверяет, меньше ли x1, чем x2, с помощью заданной функции сравнения
    }

    bool Heap::isGreat(void* x1, void* x2) const {
        return compare(x1, x2) == GREAT; // Проверяет, больше ли x1, чем x2, с помощью заданной функции сравнения
    }

    bool Heap::isEqual(void* x1, void* x2) const {
        return compare(x1, x2) == EQUAL; // Проверяет, равны ли x1 и x2, с помощью заданной функции сравнения
    }

    // Метод для обмена элементов
    void Heap::swap(int i, int j) {
        void* buf = storage[i]; // Временная переменная для обмена элементами
        storage[i] = storage[j]; // Замена элемента на позиции i элементом на позиции j
        storage[j] = buf; // Замена элемента на позиции j сохраненным ранее элементом на позиции i
    }

    // Метод для превращения поддерева с корнем в узле в кучу
    void Heap::heapify(int ix) {
        int l = left(ix), r = right(ix), irl = ix; // Вычисление индексов левого и правого потомков узла с индексом ix
        if (l > 0) { // Если у узла есть левый потомок
            if (isGreat(storage[l], storage[ix])) irl = l; // Если значение левого потомка больше значения узла, обновляем индекс максимального потомка
            if (r > 0 && isGreat(storage[r], storage[irl])) irl = r; // Если значение правого потомка больше значения максимального потомка, обновляем индекс максимального потомка
            if (irl != ix) { // Если максимальный потомок не узел, переносим максимальный потомок на место узла и рекурсивно вызываем heapify для максимального потомка
                swap(ix, irl);
                heapify(irl);
            }
        }
    }

    // Метод для вставки нового элемента в кучу
    void Heap::insert(void* x) {
        int i;
        if (!isFull()) { // Если куча не заполнена
            storage[i = ++size - 1] = x; // Добавляем элемент в конец кучи
            while (i > 0 && isLess(storage[parent(i)], storage[i])) { // Перемещаем добавленный элемент вверх, пока он больше своего родителя
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }

    // Метод для извлечения максимального элемента из кучи
    void* Heap::extractMax() {
        void* rc = nullptr;
        if (!isEmpty()) { // Если куча не пуста
            rc = storage[0]; // Сохраняем максимальный элемент
            storage[0] = storage[size - 1]; // Перемещаем последний элемент на место корня
            size--; // Уменьшаем размер кучи
            heapify(0); // Восстанавливаем свойство кучи
        }
        return rc;
    }

    void* Heap::extractMin() {
        void* rc = nullptr;
        if (!isEmpty()) { // Если куча не пуста
            int minIndex = 0; // Индекс минимального элемента, начинаем с корня
            for (int i = 1; i < size; ++i) { // Ищем наименьший элемент в куче
                if (isLess(storage[i], storage[minIndex])) { // Если текущий элемент меньше минимального
                    minIndex = i; // Обновляем индекс минимального элемента
                }
            }
            rc = storage[minIndex]; // Сохраняем минимальный элемент
            storage[minIndex] = storage[size - 1]; // Перемещаем последний элемент на место минимального
            size--; // Уменьшаем размер кучи
            heapify(minIndex); // Восстанавливаем свойство кучи
        }
        return rc;
    }



    // Метод для извлечения элемента по индексу из кучи
    void Heap::extractI(int i) {
        if (i < 0 || i >= size) { // Проверка на корректность индекса
            std::cerr << "Invalid index\n"; // Вывод сообщения об ошибке
            return;
        }
        storage[i] = storage[size - 1]; // Перемещаем последний элемент на место удаляемого
        size--; // Уменьшаем размер кучи
        heapify(i); // Восстанавливаем свойство кучи
    }

    // Метод для объединения двух куч
    void Heap::unionHeap(const Heap& other) {
        if (size + other.size > maxSize) { // Проверка на возможность объединения куч
            std::cerr << "Union would exceed maximum size\n"; // Вывод сообщения об ошибке
            return;
        }

        for (int i = 0; i < other.size; ++i) { // Добавление элементов из другой кучи в текущую
            insert(other.storage[i]);
        }
    }

    // Метод для вывода элементов кучи на экран
    void Heap::scan(int i) const {
        int probel = 20; // Начальное количество пробелов
        std::cout << '\n'; // Переход на новую строку
        if (size == 0) // Если куча пуста
            std::cout << "Куча пуста"; // Вывод сообщения об этом
        for (int u = 0, y = 0; u < size; u++) { // Цикл по всем элементам кучи
            std::cout << std::setw(probel + 10) << std::setfill(' '); // Установка отступа перед элементом
            ((AAA*)storage[u])->print(); // Вывод элемента на экран
            if (u == y) { // Если достигнут конец уровня кучи
                std::cout << '\n'; // Переход на новую строку
                if (y == 0) // Если это первый уровень
                    y = 2; // Переход к следующему уровню
                else
                    y += y * 2; // Увеличение шага перехода к уровню на 2 уровня
            }
            probel /= 2; // Уменьшение отступа перед элементом в два раза
        }
        std::cout << '\n'; // Переход на новую строку
    }

    // Функция для создания новой кучи
    Heap create(int maxsize, CMP(*f)(void*, void*)) {
        return *(new Heap(maxsize, f)); // Создание новой кучи и возвращение указателя на нее
    }
}
