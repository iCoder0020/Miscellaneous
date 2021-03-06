/* 
Min\Max Heap
Insertion - O(logN)
Extraction - O(logN)
*/

#include <bits/stdc++.h>

using namespace std;

#define parent(temp) (temp-1)/2
#define left_child(temp) 2*temp + 1
#define right_child(temp) 2*temp + 2

vector <int> heap;
string type;

void switch_places(int i, int j)
{
	int temp = heap[i];
	heap[i] = heap[j];
	heap[j] = temp;
}

void heap_insert(int num)
{
	heap.push_back(num);
	if(heap.size() != 0)
	{
		int pos = heap.size()-1;
		if(type == "min")
		{
			while(heap[pos] < heap[parent(pos)])
			{
				switch_places(pos, parent(pos));
				pos = parent(pos);
			}
		}
		else if(type == "max")
		{
			while(heap[pos] > heap[parent(pos)])
			{
				switch_places(pos, parent(pos));
				pos = parent(pos);
			}
		}
	}
}

int heap_extract()
{
	if(heap.size() == 0)
	{
		cout<<"Heap is empty. Can't Extract."<<endl;
	}
	else
	{
		int ans = heap.front();
		heap[0] = heap.back();
		heap.pop_back();
		int pos = 0;
		if(type == "min")
		{
			while(1)
			{
				if(left_child(pos) < heap.size() && right_child(pos) < heap.size())
				{
					if(heap[pos]>heap[left_child(pos)] || heap[pos]>heap[right_child(pos)])
					{
						if(heap[left_child(pos)] <= heap[right_child(pos)])
						{
							switch_places(pos, left_child(pos));
							pos = left_child(pos);
						}
						else
						{
							switch_places(pos, right_child(pos));
							pos = right_child(pos);
						}
					}
					else
					{
						break;
					}
				}
				else if(left_child(pos) < heap.size())
				{
					if(heap[pos]>heap[left_child(pos)])
					{
						switch_places(pos, left_child(pos));
						pos = left_child(pos);
					}
					else
					{
						break;
					}
				}
				else if(right_child(pos) < heap.size())
				{
					if(heap[pos]>heap[right_child(pos)])
					{
						switch_places(pos, right_child(pos));
						pos = right_child(pos);
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		else if(type == "max")
		{
			while(1)
			{
				if(left_child(pos) < heap.size() && right_child(pos) < heap.size())
				{
					if(heap[pos]<heap[left_child(pos)] || heap[pos]<heap[right_child(pos)])
					{
						if(heap[left_child(pos)] >= heap[right_child(pos)])
						{
							switch_places(pos, left_child(pos));
							pos = left_child(pos);
						}
						else
						{
							switch_places(pos, right_child(pos));
							pos = right_child(pos);
						}
					}
					else
					{
						break;
					}
				}
				else if(left_child(pos) < heap.size())
				{
					if(heap[pos]<heap[left_child(pos)])
					{
						switch_places(pos, left_child(pos));
						pos = left_child(pos);
					}
					else
					{
						break;
					}
				}
				else if(right_child(pos) < heap.size())
				{
					if(heap[pos]<heap[right_child(pos)])
					{
						switch_places(pos, right_child(pos));
						pos = right_child(pos);
					}
					else
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		return ans;
	}
}

void print_heap()
{
	if(heap.size()!=0)
	{
		for(auto it = heap.begin(); it!=heap.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"Empty Heap."<<endl;
	}
}

int main()
{
	int N;
	int temp;
	cin>>N>>type;
	while(N--)
	{
		cin>>temp;
		heap_insert(temp);
	}
	while(heap.size()!=0)
	{
		cout<<heap_extract()<<endl;
		print_heap();
	}
	return 0;
}