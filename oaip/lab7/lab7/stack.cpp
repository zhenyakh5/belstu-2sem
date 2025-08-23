#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>
#include "vector"
using namespace std;

struct STACK {
	int data;
	STACK* head;
	STACK* next;
};

void push(char x, Stack* myStk) 
{
	Stack* e = new Stack;
	e->data = x;          
	e->next = myStk->head;
	myStk->head = e;     
}

int pop(Stack* myStk) 
{
	if (myStk->head == NULL)
	{
		cout << "Стек пуст!" << endl;
		return -1;     
	}
	else
	{
		Stack* e = myStk->head;
		char a = myStk->head->data;
		myStk->head = myStk->head->next;
		delete e;                       
		return a;                      
	}
}

void show(Stack* myStk)
{
	Stack* e = myStk->head; 
	char a;
	if (e == NULL)
		cout << "Стек пуст!" << endl;
	while (e != NULL)
	{
		a = e->data; 
		cout << a << " ";
		e = e->next;
	}
	cout << endl;
}

void AddEl(int elem, STACK* stack)
{
	STACK* NewEl = new STACK;
	NewEl->data = elem;
	NewEl->next = stack->head;
	stack->head = NewEl;
}

int TakeFromStack(STACK* stack)
{
	if (stack->head == NULL)
	{
		cout << "Стек пуст";
		return -1;
	}
	else {
		STACK* intermEl = new STACK;
		int elData = stack->head->data;
		stack->head = stack->head->next;
		delete intermEl;
		return elData;
	}
}

void PrintStack(STACK* stack)
{
	STACK* sthead = stack->head;
	int elData;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->data;
		cout << elData << " ";
		sthead = sthead->next;
	}
	cout << "\n";
}

void ToFile(STACK* stack)
{
	ofstream getf;
	getf.open("File13.txt");
	if (getf.is_open())
	{
		STACK* StackHead = stack->head;
		while (StackHead != NULL)
		{
			getf << StackHead->data << "\n";
			StackHead = StackHead->next;
		}; cout << "\n";
	}
	getf.close();
	cout << "Информация записана в файл!\n\n";
}

void FromFile(STACK* stack)
{
	char buf[10];
	vector<int> container;
	ifstream file1("File13.txt");
	if (file1.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (!file1.eof())
	{
		file1.getline(buf, 10);
		if (strlen(buf))
			container.push_back(atoi(buf));
	}

	for (int i = container.size() - 1; i >= 0; i--)
	{
		AddEl(container[i], stack);
	}

	file1.close();
}

void DeleteSameHelp(STACK* stack, int point)
{
	STACK* sthead1 = stack->head;
	for (int k = 0; k < point - 1; k++)
		sthead1 = sthead1->next;

	sthead1->next = sthead1->next->next;
}

void clear(STACK* stack)
{
	if (stack->head == NULL)
		cout << "Стек пуст";
	while (stack->head != NULL)
	{
		STACK* f = stack->head;
		stack->head = stack->head->next;
		delete f;
	}
	cout << "\n";
}

int DeleteSame(STACK* stack)
{
	STACK* sthead = stack->head;
	int elData, i = 0, point = -1;
	vector<int> arr;
	vector<int> arr2;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->data;
		arr.push_back(elData);
		sthead = sthead->next;
	}

	bool first = false;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			if (j != i && !first && arr[i] == arr[j]) {

				point = i;
				first = true;
			}
		}
	}

	arr.erase(arr.begin() + point);

	clear(stack);

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		AddEl(arr[i], stack);
	}

	first = false;

	return 0;
}