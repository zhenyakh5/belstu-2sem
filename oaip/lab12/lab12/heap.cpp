#include "Heap.h"
#include <iostream>
#include <iomanip>

// ������ ��� ��������� AAA
void AAA::print() {
    std::cout << x; // ����� �������� x ��������� AAA
}

namespace heap {
    // ����������� ����
    Heap::Heap(int maxsize, CMP(*f)(void*, void*)) {
        size = 0; // ������������� ������� ���� ��� 0
        storage = new void* [maxSize = maxsize]; // ��������� ������ ��� ��������� ��������� ����
        compare = f; // ���������� ������� ��������� ���������
    }

    // ������ ��� ������ � ��������� ���������
    int Heap::left(int ix) {
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1); // ���������� ������ ������ ������� ���� � �������� ix
    }

    int Heap::right(int ix) {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2); // ���������� ������ ������� ������� ���� � �������� ix
    }

    int Heap::parent(int ix) {
        return (ix + 1) / 2 - 1; // ���������� ������ ������������� ���� ��� ���� � �������� ix
    }

    // �������� �� ������������� � ������� ����
    bool Heap::isFull() const {
        return (size >= maxSize); // ���������, ��������� �� ����
    }

    bool Heap::isEmpty() const {
        return (size <= 0); // ���������, ����� �� ����
    }

    // ������ ��� ��������� ���������
    const bool Heap::isLess(void* x1, void* x2) {
        return compare(x1, x2) == LESS; // ���������, ������ �� x1, ��� x2, � ������� �������� ������� ���������
    }

    bool Heap::isGreat(void* x1, void* x2) const {
        return compare(x1, x2) == GREAT; // ���������, ������ �� x1, ��� x2, � ������� �������� ������� ���������
    }

    bool Heap::isEqual(void* x1, void* x2) const {
        return compare(x1, x2) == EQUAL; // ���������, ����� �� x1 � x2, � ������� �������� ������� ���������
    }

    // ����� ��� ������ ���������
    void Heap::swap(int i, int j) {
        void* buf = storage[i]; // ��������� ���������� ��� ������ ����������
        storage[i] = storage[j]; // ������ �������� �� ������� i ��������� �� ������� j
        storage[j] = buf; // ������ �������� �� ������� j ����������� ����� ��������� �� ������� i
    }

    // ����� ��� ����������� ��������� � ������ � ���� � ����
    void Heap::heapify(int ix) {
        int l = left(ix), r = right(ix), irl = ix; // ���������� �������� ������ � ������� �������� ���� � �������� ix
        if (l > 0) { // ���� � ���� ���� ����� �������
            if (isGreat(storage[l], storage[ix])) irl = l; // ���� �������� ������ ������� ������ �������� ����, ��������� ������ ������������� �������
            if (r > 0 && isGreat(storage[r], storage[irl])) irl = r; // ���� �������� ������� ������� ������ �������� ������������� �������, ��������� ������ ������������� �������
            if (irl != ix) { // ���� ������������ ������� �� ����, ��������� ������������ ������� �� ����� ���� � ���������� �������� heapify ��� ������������� �������
                swap(ix, irl);
                heapify(irl);
            }
        }
    }

    // ����� ��� ������� ������ �������� � ����
    void Heap::insert(void* x) {
        int i;
        if (!isFull()) { // ���� ���� �� ���������
            storage[i = ++size - 1] = x; // ��������� ������� � ����� ����
            while (i > 0 && isLess(storage[parent(i)], storage[i])) { // ���������� ����������� ������� �����, ���� �� ������ ������ ��������
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }

    // ����� ��� ���������� ������������� �������� �� ����
    void* Heap::extractMax() {
        void* rc = nullptr;
        if (!isEmpty()) { // ���� ���� �� �����
            rc = storage[0]; // ��������� ������������ �������
            storage[0] = storage[size - 1]; // ���������� ��������� ������� �� ����� �����
            size--; // ��������� ������ ����
            heapify(0); // ��������������� �������� ����
        }
        return rc;
    }

    void* Heap::extractMin() {
        void* rc = nullptr;
        if (!isEmpty()) { // ���� ���� �� �����
            int minIndex = 0; // ������ ������������ ��������, �������� � �����
            for (int i = 1; i < size; ++i) { // ���� ���������� ������� � ����
                if (isLess(storage[i], storage[minIndex])) { // ���� ������� ������� ������ ������������
                    minIndex = i; // ��������� ������ ������������ ��������
                }
            }
            rc = storage[minIndex]; // ��������� ����������� �������
            storage[minIndex] = storage[size - 1]; // ���������� ��������� ������� �� ����� ������������
            size--; // ��������� ������ ����
            heapify(minIndex); // ��������������� �������� ����
        }
        return rc;
    }



    // ����� ��� ���������� �������� �� ������� �� ����
    void Heap::extractI(int i) {
        if (i < 0 || i >= size) { // �������� �� ������������ �������
            std::cerr << "Invalid index\n"; // ����� ��������� �� ������
            return;
        }
        storage[i] = storage[size - 1]; // ���������� ��������� ������� �� ����� ����������
        size--; // ��������� ������ ����
        heapify(i); // ��������������� �������� ����
    }

    // ����� ��� ����������� ���� ���
    void Heap::unionHeap(const Heap& other) {
        if (size + other.size > maxSize) { // �������� �� ����������� ����������� ���
            std::cerr << "Union would exceed maximum size\n"; // ����� ��������� �� ������
            return;
        }

        for (int i = 0; i < other.size; ++i) { // ���������� ��������� �� ������ ���� � �������
            insert(other.storage[i]);
        }
    }

    // ����� ��� ������ ��������� ���� �� �����
    void Heap::scan(int i) const {
        int probel = 20; // ��������� ���������� ��������
        std::cout << '\n'; // ������� �� ����� ������
        if (size == 0) // ���� ���� �����
            std::cout << "���� �����"; // ����� ��������� �� ����
        for (int u = 0, y = 0; u < size; u++) { // ���� �� ���� ��������� ����
            std::cout << std::setw(probel + 10) << std::setfill(' '); // ��������� ������� ����� ���������
            ((AAA*)storage[u])->print(); // ����� �������� �� �����
            if (u == y) { // ���� ��������� ����� ������ ����
                std::cout << '\n'; // ������� �� ����� ������
                if (y == 0) // ���� ��� ������ �������
                    y = 2; // ������� � ���������� ������
                else
                    y += y * 2; // ���������� ���� �������� � ������ �� 2 ������
            }
            probel /= 2; // ���������� ������� ����� ��������� � ��� ����
        }
        std::cout << '\n'; // ������� �� ����� ������
    }

    // ������� ��� �������� ����� ����
    Heap create(int maxsize, CMP(*f)(void*, void*)) {
        return *(new Heap(maxsize, f)); // �������� ����� ���� � ����������� ��������� �� ���
    }
}
