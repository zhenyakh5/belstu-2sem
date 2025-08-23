// Структура для элементов кучи
struct AAA {
    int x;
    void print(); // Метод для печати значения элемента
};

namespace heap {
    // Перечисление для результатов сравнения
    enum CMP {
        LESS = -1,  // Меньше
        EQUAL = 0,  // Равно
        GREAT = 1   // Больше
    };

    // Структура для представления кучи
    struct Heap {
        int size; // Текущий размер кучи
        int maxSize; // Максимальный размер кучи
        void** storage; // Хранилище элементов
        CMP(*compare)(void*, void*); // Указатель на функцию сравнения

        // Конструктор кучи
        Heap(int maxsize, CMP(*f)(void*, void*));

        // Методы для работы с индексами элементов
        int left(int ix);
        int right(int ix);
        int parent(int ix);

        // Проверки на заполненность и пустоту кучи
        bool isFull() const;
        bool isEmpty() const;

        // Методы для сравнения элементов
        const bool isLess(void* x1, void* x2);
        bool isGreat(void* x1, void* x2) const;
        bool isEqual(void* x1, void* x2) const;

        // Метод для обмена элементов
        void swap(int i, int j);

        // Метод для превращения поддерева с корнем в узле в кучу
        void heapify(int ix);

        // Методы для вставки и извлечения максимального и минимального элементов
        void insert(void* x);
        void* extractMax();
        void* extractMin();

        // Метод для извлечения элемента по индексу из кучи
        void extractI(int i);

        // Метод для объединения двух куч
        void unionHeap(const Heap& other);

        // Метод для вывода элементов кучи на экран
        void scan(int i) const;
    };

    // Функция для создания новой кучи
    Heap create(int maxsize, CMP(*f)(void*, void*));
}
