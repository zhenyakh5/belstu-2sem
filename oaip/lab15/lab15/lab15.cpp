#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = 0; j < array.size() - 1; j++)
        {
            if (array[j] < array[j + 1])
                Swap(&array[j], &array[j + 1]); // меняем местами
        }
    }
}

void heapify(vector<int>& A, int pos, int n)
{
    int t, tm;
    while (2 * pos + 1 < n) // Пока у элемента в позиции pos есть дочерний элемент
    {
        t = 2 * pos + 1; // Инициализация t как левого дочернего элемента
        if (2 * pos + 2 < n && A[2 * pos + 2] <= A[t]) // Если есть правый дочерний элемент и он больше левого
            t = 2 * pos + 2; // Обновляем t как индекс правого дочернего элемента
        if (A[pos] > A[t]) // Если значение элемента в позиции pos меньше значения элемента в позиции t
        {
            tm = A[pos]; // Запоминаем значение элемента в позиции pos
            A[pos] = A[t]; // Заменяем значение элемента в позиции pos значением элемента в позиции t
            A[t] = tm; // Заменяем значение элемента в позиции t сохраненным значением
            pos = t; // Переходим к следующему уровню в пирамиде
        }
        else
            break; // Иначе выходим из цикла while
    }
}

void piramSort(vector<int>& A, int n)
{
    for (int i = n - 1; i >= 0; i--) // Построение начальной пирамиды
        heapify(A, i, n);
    while (n > 0) // Пока в массиве остаются неотсортированные элементы
    {
        int tm = A[0]; // Запоминаем значение первого элемента (максимального в пирамиде)
        A[0] = A[n - 1]; // Перемещаем последний элемент в начало массива
        A[n - 1] = tm; // Помещаем максимальный элемент в конец массива
        n--; // Уменьшаем размер "нерассмотренной" части массива
        heapify(A, 0, n); // Восстанавливаем свойство пирамиды для оставшейся части массива
    }
}


void PrintArray(const vector<int>& array)
{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int a_len, b_len;
    cout << "Введите размер массива А\n";
    cin >> a_len;

    cout << "Введите размер массива В\n";
    cin >> b_len;

    vector<int> A;
    vector<int> B;
    vector<int> array1;
    vector<int> array2;

    for (int i = 0; i < a_len; i++)
    {
        A.push_back(rand() % 100 - 50 + 1);
    }

    for (int i = 0; i < b_len; i++)
    {
        B.push_back(rand() % 100 - 50 + 1);
    }

    for (int i = 0; i < a_len; i++)
    {
        if (A[i] % 2 != 0) {
            array1.push_back(A[i]);
            array2.push_back(A[i]);
        }
    }

    for (int i = 0; i < b_len; i++)
    {
        if (B[i] % 2 == 0) {
            array1.push_back(B[i]);
            array2.push_back(B[i]);
        }
    }
    cout << "Массив A \n";
    PrintArray(A);
    cout << "Массив B \n";
    PrintArray(B);
    cout << "Массив C \n";
    PrintArray(array1);

    clock_t start_time_1 = clock();
    BubbleSort(array2);
    clock_t end_time_1 = clock();

    cout << "Время пузырьковой сортировки: " << end_time_1 - start_time_1 << " ms \n";
    cout << "Отсортированный массив пузырьком\n";
    PrintArray(array2);

    unsigned int start_time_2 = clock();
    piramSort(array1, array1.size());
    unsigned int end_time_2 = clock();

    cout << "Время пирамидальной сортировки: " << end_time_2 - start_time_2 << " ms \n";

    cout << "Отсортированный массив пирамидально\n";
    PrintArray(array1);

    return 0;
}
