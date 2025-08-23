#pragma once

struct Stack
{
	char data;
	Stack* head;
	Stack* next; 
};

void show(Stack* myStk); 
int pop(Stack* myStk); 
void push(char x, Stack* myStk); 