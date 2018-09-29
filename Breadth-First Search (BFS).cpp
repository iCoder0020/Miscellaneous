/* 
Breadth-First Search (BFS)
Time Complexity: O(N+M)
*/

#include <iostream>
#include <stdio.h>
#include <vector>
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

int tail_element()
{
	return TAIL->data;
}

void BFS(vector <int> *adj_list, int size, int starting_vertex_index)
{
	bool flagged[size];
	int s;
	for(int i = 0; i<size; i++)
	{
		flagged[i] = false;
	}
	s = starting_vertex_index;
	insert_into_queue(s);
	while(!is_queue_empty())
	{
		s = tail_element();
		flagged[s] = true;

		remove_from_queue();

		for(int j = 0; j<adj_list[s].size(); j++)
		{
			if(flagged[adj_list[s][j]] == false)
			{
				flagged[adj_list[s][j]] = true;
				insert_into_queue(adj_list[s][j]);
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
	BFS(adj_list, N, 0);
	return 0;
}