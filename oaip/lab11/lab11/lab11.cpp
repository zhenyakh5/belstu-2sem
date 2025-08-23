#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tree
{
    int key;
    int value;
    Tree* Left, * Right;
};

Tree* makeTree(Tree* Root);
Tree* list(int i, int s);
Tree* insertElem(Tree* Root, int key, int s);
Tree* search(Tree* n, int key);
Tree* delet(Tree* Root, int key);
void view(Tree* t, int level);
void delAll(Tree* t);
double average(Tree* root);

Tree* Root = NULL;
vector<int> keys;


int iter = 0;


int main()
{
    setlocale(0, "Russian");
    int key, choice, n;
    float s;
    Tree* rc; char letter;
    for (;;)
    {
        cout << "1 -  создание дерева\n";
        cout << "2 -  добавление элемента\n";
        cout << "3 -  поиск по ключу\n";
        cout << "4 -  удаление элемента\n";
        cout << "5 -  вывод дерева\n";
        cout << "6 -  подсчет среднего арифметического\n";
        cout << "7 -  очистка дерева\n";
        cout << "8 -  выход\n";
        cout << "ваш выбор?\n";
        cin >> choice;
        cout << "\n";
        switch (choice)
        {
        case 1:  Root = makeTree(Root);  break;
        case 2:  cout << "\nВведите ключ: "; cin.ignore(); cin >> key;
            cout << "Введите число: "; cin >> s;
            insertElem(Root, key, s); break;
        case 3:  cout << "\nВведите ключ: ";  cin >> key;
            rc = search(Root, key);
            cout << "Найденное число= " << rc->value << endl;
            break;

        case 4:  cout << "\nВведите удаляемый ключ: "; cin >> key;
            Root = delet(Root, key);  break;
        case 5:  if (Root->key >= 0)
        {
            cout << "Дерево повернуто на 90 град. влево" << endl;
            view(Root, 0);
        }
              else cout << "Дерево пустое\n"; break;
        case 6:
            printf_s("среднее арифметическое = %.2f \n", average(Root));
            break;
        case 7:  delAll(Root); break;
        case 8:  exit(0);
        }
    }
}

// Функция создания дерева
Tree* makeTree(Tree* Root) {
    int key, s;
    cout << "Конец ввода - отрицательное число\n\n";
    if (Root == NULL) {
        cout << "Введите ключ корня: "; cin >> key;
        cout << "Введите число корня: "; cin >> s;
        Root = list(key, s); // Создание корня дерева
    }
    while (1) {
        cout << "\nВведите ключ: ";  cin >> key;
        if (key < 0) break; // Завершение ввода при отрицательном ключе
        if (count(keys.begin(), keys.end(), key) > 0) { // Проверка наличия ключа в векторе keys
            cout << "Ошибка ввода ключа. Ключ должен быть уникален." << endl;
            break;
        }
        cout << "Введите число: ";  cin >> s;
        insertElem(Root, key, s); // Добавление элемента в дерево
        keys.push_back(key); // Добавление ключа в вектор keys
    }
    return Root;
}


// Функция создания нового узла
Tree* list(int i, int s) {
    Tree* t = new Tree[sizeof(Tree)]; // Выделение памяти под новый узел
    t->key = i; // Присвоение ключа узлу
    t->value = s; // Присвоение значения узлу
    t->Left = t->Right = NULL; // Установка указателей на поддеревья в NULL
    return t; // Возвращение указателя на созданный узел
}

// Функция добавления элемента в дерево
Tree* insertElem(Tree* t, int key, int s) {
    Tree* Prev = t; // Указатель на предыдущий узел
    int find = 0; // Флаг нахождения узла с таким же ключом
    while (t && !find)
    {
        Prev = t; // Запоминание предыдущего узла
        if (key == t->key) // Если ключи совпали
            find = 1; // Устанавливаем флаг
        else
            if (key < t->key) t = t->Left; // Если ключ меньше текущего, переходим влево
            else t = t->Right; // Иначе переходим вправо
    }
    if (!find) { // Если узел с таким ключом не найден
        t = list(key, s); // Создаем новый узел
        if (key < Prev->key) // Если ключ меньше ключа предыдущего узла
            Prev->Left = t; // Подвешиваем новый узел к левой ветке
        else
            Prev->Right = t; // Иначе подвешиваем к правой ветке
    }
    return t; // Возвращаем указатель на корень дерева
}


// Функция удаления элемента из дерева
Tree* delet(Tree* Root, int key) {
    Tree* Del, * Prev_Del, * R, * Prev_R; // Указатели на удаляемый узел, предыдущий удаляемому, замещающий узел и его предыдущий
    Del = Root; // Начинаем поиск с корня
    Prev_Del = NULL; // Инициализируем предыдущий удаляемому узлу как NULL
    while (Del != NULL && Del->key != key) { // Поиск узла для удаления
        Prev_Del = Del; // Запоминание предыдущего узла
        if (Del->key > key)
            Del = Del->Left; // Переход в левое поддерево
        else
            Del = Del->Right; // Переход в правое поддерево
    }
    if (Del == NULL) { // Если узел для удаления не найден
        puts("\nНет такого ключа"); // Вывод сообщения об ошибке
        return Root; // Возвращаем корень без изменений
    }
    if (Del->Right == NULL)
        R = Del->Left; // Если у удаляемого узла нет правого потомка
    else
        if (Del->Left == NULL)
            R = Del->Right; // Если у удаляемого узла нет левого потомка
        else
        {
            Prev_R = Del; // Инициализируем предыдущий замещающему узлу узел как сам удаляемый узел
            R = Del->Left; // Начинаем поиск замещающего узла в левом поддереве
            while (R->Right != NULL)
            {
                Prev_R = R; // Запоминание предыдущего узла
                R = R->Right; // Переход вправо
            }
            if (Prev_R == Del)
                R->Right = Del->Right; // Если предыдущий замещающему узлу узел - сам удаляемый узел, замещаем правое поддерево
            else
            {
                R->Right = Del->Right; // Замещаем правое поддерево
                Prev_R->Right = R->Left; // Присваиваем правому потомку замещающего узла левое поддерево замещающего узла
                R->Left = Prev_R; // Присваиваем левому потомку замещающего узла предыдущий замещающий узел
            }
        }
    if (Del == Root) Root = R; // Если удаляемый узел - корень, замещаем его замещающим узлом
    else
        if (Del->key < Prev_Del->key)
            Prev_Del->Left = R; // Если удаляемый узел находится слева от предыдущего узла, подвешиваем замещающий узел слева
        else
            Prev_Del->Right = R; // Иначе подвешиваем справа
    int tmp = Del->key; // Запоминаем ключ удаляемого узла
    cout << "\nУдален элемент с ключом " << tmp << endl; // Выводим сообщение об успешном удалении
    delete Del; // Освобождаем память, занятую удаляемым узлом
    return Root; // Возвращаем корень дерева
}


// Функция поиска элемента в дереве по ключу
Tree* search(Tree* n, int key) {
    Tree* rc = n; // Инициализируем указатель на результат поиска текущим корнем
    if (rc != NULL) // Если текущий корень не пустой
    {
        if (key < (key, n->key)) // Если ключ меньше ключа текущего узла
            rc = search(n->Left, key); // Рекурсивный вызов поиска в левом поддереве
        else
            if (key > (key, n->key)) // Если ключ больше ключа текущего узла
                rc = search(n->Right, key); // Рекурсивный вызов поиска в правом поддереве
    }
    else
        cout << "Нет такого элемента\n"; // Вывод сообщения об ошибке, если узел не найден
    return rc; // Возвращаем найденный узел
}

// Функция для вычисления суммы всех элементов дерева
int sum(Tree* n) {
    if (n == nullptr) {
        return 0;
    }

    return n->key + sum(n->Left) + sum(n->Right);
}

// Функция для подсчета количества элементов в дереве
int countNodes(Tree* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + countNodes(root->Left) + countNodes(root->Right);
}

// Функция для вычисления среднего арифметического всех элементов дерева
double average(Tree* root) {
    int totalSum = sum(root);
    int totalCount = countNodes(root);

    if (totalCount == 0) {
        return 0; // Деление на ноль, если дерево пустое
    }

    return static_cast<double>(totalSum) / totalCount;
}


// Функция вывода дерева на экран
void view(Tree* t, int level) {

    if (t) // Если текущий узел не пустой
    {
        view(t->Right, level + 1); // Рекурсивный вызов для правого поддерева
        for (int i = 0; i < level; i++) // Отступ от левого края консоли для наглядности
            cout << " -- ";
        int tm = t->key; // Запоминаем ключ текущего узла
        printf_s("%d %d\n", tm, t->value); // Выводим на экран ключ и значение текущего узла
        view(t->Left, level + 1); // Рекурсивный вызов для левого поддерева
    }
}

// Функция очистки памяти, выделенной под дерево
void delAll(Tree* t) {
    if (t != NULL) // Если текущий узел не пустой
    {
        delAll(t->Left); // Рекурсивный вызов для левого поддерева
        delAll(t->Right); // Рекурсивный вызов для правого поддерева
        delete t; // Освобождаем память, занятую текущим узлом
    }
}
