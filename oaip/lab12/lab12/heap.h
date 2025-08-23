// ��������� ��� ��������� ����
struct AAA {
    int x;
    void print(); // ����� ��� ������ �������� ��������
};

namespace heap {
    // ������������ ��� ����������� ���������
    enum CMP {
        LESS = -1,  // ������
        EQUAL = 0,  // �����
        GREAT = 1   // ������
    };

    // ��������� ��� ������������� ����
    struct Heap {
        int size; // ������� ������ ����
        int maxSize; // ������������ ������ ����
        void** storage; // ��������� ���������
        CMP(*compare)(void*, void*); // ��������� �� ������� ���������

        // ����������� ����
        Heap(int maxsize, CMP(*f)(void*, void*));

        // ������ ��� ������ � ��������� ���������
        int left(int ix);
        int right(int ix);
        int parent(int ix);

        // �������� �� ������������� � ������� ����
        bool isFull() const;
        bool isEmpty() const;

        // ������ ��� ��������� ���������
        const bool isLess(void* x1, void* x2);
        bool isGreat(void* x1, void* x2) const;
        bool isEqual(void* x1, void* x2) const;

        // ����� ��� ������ ���������
        void swap(int i, int j);

        // ����� ��� ����������� ��������� � ������ � ���� � ����
        void heapify(int ix);

        // ������ ��� ������� � ���������� ������������� � ������������ ���������
        void insert(void* x);
        void* extractMax();
        void* extractMin();

        // ����� ��� ���������� �������� �� ������� �� ����
        void extractI(int i);

        // ����� ��� ����������� ���� ���
        void unionHeap(const Heap& other);

        // ����� ��� ������ ��������� ���� �� �����
        void scan(int i) const;
    };

    // ������� ��� �������� ����� ����
    Heap create(int maxsize, CMP(*f)(void*, void*));
}
