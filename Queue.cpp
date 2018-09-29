/* 
Queue
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

struct queue
{
	int data;
	queue *next;
};

queue *HEAD = NULL;
queue *TAIL = NULL;

void insert_into_queue(int num)
{
	queue *tmp = new queue;
	if(tmp == NULL)
	{
		cout<<"Memory Full. Can't insert any further.\n";
	}
	else
	{
		tmp->data = num;
		tmp->next = HEAD;
		if(HEAD == NULL)
		{
			tmp->next = NULL;
			TAIL = tmp;
		}
		HEAD = tmp;
	}
}

void remove_from_queue()
{
	if(HEAD != NULL)
	{
		if(HEAD == TAIL)
		{
			delete HEAD;
			HEAD = NULL;
			TAIL = NULL;
		}
		else
		{
			queue *tmp = HEAD;
			while(tmp->next->next != NULL)
			{
				tmp = tmp->next;
			}
			delete TAIL;
			TAIL = tmp;
			TAIL->next = NULL;
		}
	}
	else
	{
		cout<<"Empty Queue: Can't delete any further.\n";
	}
}

void print_queue()
{
	if(HEAD != NULL)
	{
		queue *tmp = HEAD;
		while(tmp != NULL)
		{
			cout<<tmp->data<<" ";
			tmp = tmp->next;
		}
		cout<<"\n";
	}
	else
	{
		cout<<"Empty Queue: Can't print the queue.\n";
	}
}

bool is_queue_empty()
{
	if(HEAD == NULL)
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
		cout<<"Press 1 to insert an element to queue.\n";
		cout<<"Press 2 to remove element from queue.\n";
		cout<<"Press 3 to print the queue.\n";
		cout<<"Press 4 to exit.\n";
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter the element: ";
				cin>>num;
				insert_into_queue(num);
				break;

			case 2:
				remove_from_queue();
				break;

			case 3:
				print_queue();
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