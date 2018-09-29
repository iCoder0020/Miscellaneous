/* 
Depth-First Search (DFS)
Time Complexity: O(N+M)
*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;

struct stack
{
	int data;
	stack *next
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

int top_element()
{
	return TOP->data;
}

void DFS(vector <int> *adj_list, int size, int starting_vertex_index)
{
	bool flagged[size];
	int s;
	for(int i = 0; i<size; i++)
	{
		flagged[i] = false;
	}
	s = starting_vertex_index;
	push_into_stack(s);
	while(!is_stack_empty())
	{
		print_stack();

		s = top_element();
		flagged[s] = true;

		pop_from_stack();

		for(int j = 0; j<adj_list[s].size(); j++)
		{
			if(flagged[adj_list[s][j]] == false)
			{
				flagged[adj_list[s][j]] = true;
				push_into_stack(adj_list[s][j]);
			}
		}
	}
}

int main()
{
	int N;
	cin>>N;
	vector <int> adj_list[N];
	int m;
	char c;
	for(int n = 0; n<N; n++)
	{
		scanf("%d%c", &m, &c);
		while(1)
		{
			scanf("%d%c", &m, &c);
			adj_list[n].push_back(m-1);
			if(c == '\n')
			{
				break;
			}
		}
	}
	DFS(adj_list, N, 0);
	return 0;
}