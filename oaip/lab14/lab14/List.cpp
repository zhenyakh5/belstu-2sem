#include "List.h" // Включение заголовочного файла "List.h" (предположительно, содержащего необходимые объявления)

#include <iostream> // Включение библиотеки iostream для операций ввода-вывода

struct AAA // Определение структуры с именем AAA
{
    int key;    // Целочисленная переменная с именем key
    char* mas;  // Указатель на char с именем mas
    char* name; // Указатель на char с именем name
};

namespace listx // Начало определения пространства имен listx
{
    bool Object::insert(void* data) // Определение функции insert класса Object
    {
        bool rc = NULL; // Инициализация булевой переменной rc значением NULL (вероятно, предполагается false)
        if (head == NULL) // Если указатель head равен NULL
            head = new Element(NULL, data, head); // Создать новый элемент с данными и установить его как head
        else
            head = (head->prev = new Element(NULL, data, head)); // В противном случае создать новый элемент и установить его как head, корректируя указатели
        return rc; // Вернуть булево значение rc (которое всегда false)
    }

    Element* Object::search(void* data) // Определение функции search класса Object
    {
        Element* rc = head; // Инициализация указателя rc значением head
        while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key)) // Пока rc не равен NULL и ключ данных в rc не равен ключу вводных данных
            rc = rc->next; // Перейти к следующему элементу
        return rc; // Вернуть указатель rc
    }

    bool Object::deleteByElement(Element* e) // Определение функции deleteByElement класса Object
    {
        bool rc = NULL; // Инициализация булевой переменной rc значением NULL (вероятно, предполагается false)
        if (rc = (e != NULL)) // Если e не равен NULL
        {
            if (e->next != NULL) // Если следующий элемент после e не равен NULL
                e->next->prev = e->prev; // Установить предыдущий указатель следующего элемента равным предыдущему указателю e
            if (e->prev != NULL) // Если предыдущий элемент перед e не равен NULL
                e->prev->next = e->next; // Установить следующий указатель предыдущего элемента равным следующему указателю e
            else
                head = e->next; // Иначе установить указатель head равным следующему указателю e
            delete e; // Удалить элемент e
        }
        std::cout << "Элемент удалён" << std::endl; // Вывести "Элемент удалён" (на русском языке)
        return rc; // Вернуть булево значение rc (которое true, если e не равен NULL)
    }

    bool Object::deleteByData(void* data) // Определение функции deleteByData класса Object
    {
        return deleteByElement(search(data)); // Вызвать deleteByElement с результатом функции search с входными данными и вернуть его результат
    }

    Element* Object::getLast() // Определение функции getLast класса Object
    {
        listx::Element* e = this->getFirst(), * rc = this->getFirst(); // Инициализация двух указателей e и rc первым элементом
        while (e != NULL) // Пока e не равен NULL
        {
            rc = e; // Установить rc в e
            e = e->getNext(); // Перейти к следующему элементу
        };
        return rc; // Вернуть указатель rc
    }

    Object create() // Определение функции create
    {
        return *(new Object()); // Создать новый объект Object динамически и вернуть его
    };

    void Object::scan() // Определение функции scan класса Object
    {
        listx::Element* e = this->getFirst(); // Инициализация указателя e первым элементом
        bool k = 0; // Инициализация булевой переменной k значением 0
        while (e != NULL) // Пока e не равен NULL
        {

            std::cout << "Год создания университета: " << ((AAA*)e->data)->key << "; " << "ФИО : " << ((AAA*)e->data)->mas << "; " << "Название университета : " << ((AAA*)e->data)->name << "; "; // Вывести ключ, mas и name данных в e
            e = e->getNext(); // Перейти к следующему элементу
            k = 1; // Установить k в 1
        };

        if (!k) // Если k равно false
        {
            std::cout << " - "; // Вывести "-"
        }
    }
} // Конец определения пространства имен
