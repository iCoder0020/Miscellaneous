/* 
Stack
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct stack
{
	int data;
	stack *next;
};

stack *TOP = NULL;

void push_into_stack(int num)
{
	stack *tmp = new stack;
	if(tmp == NULL)
	{
		cout<<"Memory Full. Can't push any further.\n";
	}
	else
	{
		tmp->data = num;
		tmp->next = TOP;
		tmp->next = TOP;
		TOP = tmp;
	}
}

void pop_from_stack()
{
	if(TOP != NULL)
	{
		stack *tmp;
		tmp = TOP;
		TOP = TOP->next;
		delete tmp;
	}
	else
	{
		cout<<"Empty Stack: Can't pop any further.\n";
	}
}

void print_stack()
{
	if(TOP != NULL)
	{
		stack *tmp = TOP;
		while(tmp != NULL)
		{
			cout<<tmp->data<<" ";
			tmp = tmp->next;
		}
		cout<<"\n";
	}
	else
	{
		cout<<"Empty Stack: Can't print the stack.\n";
	}
}

bool is_stack_empty()
{
	if(TOP == NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int main()
{
	int choice;
	int num;
	bool exit;

	exit = false;

	while(!exit)
	{
		cout<<"Press 1 to push an element to stack.\n";
		cout<<"Press 2 to pop element from stack.\n";
		cout<<"Press 3 to print the stack.\n";
		cout<<"Press 4 to exit.\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the element: ";
				cin>>num;
				push_into_stack(num);
				break;

			case 2:
				pop_from_stack();
				break;

			case 3:
				print_stack();
				break;

			case 4:
				exit = true;
				break;

			default:
				cout<<"\nEnter a valid choice.";
				break;
		}
		cout<<"\n\n";
	}
	return 0;
}