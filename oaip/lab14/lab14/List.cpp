#include "List.h" // ��������� ������������� ����� "List.h" (����������������, ����������� ����������� ����������)

#include <iostream> // ��������� ���������� iostream ��� �������� �����-������

struct AAA // ����������� ��������� � ������ AAA
{
    int key;    // ������������� ���������� � ������ key
    char* mas;  // ��������� �� char � ������ mas
    char* name; // ��������� �� char � ������ name
};

namespace listx // ������ ����������� ������������ ���� listx
{
    bool Object::insert(void* data) // ����������� ������� insert ������ Object
    {
        bool rc = NULL; // ������������� ������� ���������� rc ��������� NULL (��������, �������������� false)
        if (head == NULL) // ���� ��������� head ����� NULL
            head = new Element(NULL, data, head); // ������� ����� ������� � ������� � ���������� ��� ��� head
        else
            head = (head->prev = new Element(NULL, data, head)); // � ��������� ������ ������� ����� ������� � ���������� ��� ��� head, ����������� ���������
        return rc; // ������� ������ �������� rc (������� ������ false)
    }

    Element* Object::search(void* data) // ����������� ������� search ������ Object
    {
        Element* rc = head; // ������������� ��������� rc ��������� head
        while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key)) // ���� rc �� ����� NULL � ���� ������ � rc �� ����� ����� ������� ������
            rc = rc->next; // ������� � ���������� ��������
        return rc; // ������� ��������� rc
    }

    bool Object::deleteByElement(Element* e) // ����������� ������� deleteByElement ������ Object
    {
        bool rc = NULL; // ������������� ������� ���������� rc ��������� NULL (��������, �������������� false)
        if (rc = (e != NULL)) // ���� e �� ����� NULL
        {
            if (e->next != NULL) // ���� ��������� ������� ����� e �� ����� NULL
                e->next->prev = e->prev; // ���������� ���������� ��������� ���������� �������� ������ ����������� ��������� e
            if (e->prev != NULL) // ���� ���������� ������� ����� e �� ����� NULL
                e->prev->next = e->next; // ���������� ��������� ��������� ����������� �������� ������ ���������� ��������� e
            else
                head = e->next; // ����� ���������� ��������� head ������ ���������� ��������� e
            delete e; // ������� ������� e
        }
        std::cout << "������� �����" << std::endl; // ������� "������� �����" (�� ������� �����)
        return rc; // ������� ������ �������� rc (������� true, ���� e �� ����� NULL)
    }

    bool Object::deleteByData(void* data) // ����������� ������� deleteByData ������ Object
    {
        return deleteByElement(search(data)); // ������� deleteByElement � ����������� ������� search � �������� ������� � ������� ��� ���������
    }

    Element* Object::getLast() // ����������� ������� getLast ������ Object
    {
        listx::Element* e = this->getFirst(), * rc = this->getFirst(); // ������������� ���� ���������� e � rc ������ ���������
        while (e != NULL) // ���� e �� ����� NULL
        {
            rc = e; // ���������� rc � e
            e = e->getNext(); // ������� � ���������� ��������
        };
        return rc; // ������� ��������� rc
    }

    Object create() // ����������� ������� create
    {
        return *(new Object()); // ������� ����� ������ Object ����������� � ������� ���
    };

    void Object::scan() // ����������� ������� scan ������ Object
    {
        listx::Element* e = this->getFirst(); // ������������� ��������� e ������ ���������
        bool k = 0; // ������������� ������� ���������� k ��������� 0
        while (e != NULL) // ���� e �� ����� NULL
        {

            std::cout << "��� �������� ������������: " << ((AAA*)e->data)->key << "; " << "��� : " << ((AAA*)e->data)->mas << "; " << "�������� ������������ : " << ((AAA*)e->data)->name << "; "; // ������� ����, mas � name ������ � e
            e = e->getNext(); // ������� � ���������� ��������
            k = 1; // ���������� k � 1
        };

        if (!k) // ���� k ����� false
        {
            std::cout << " - "; // ������� "-"
        }
    }
} // ����� ����������� ������������ ����
