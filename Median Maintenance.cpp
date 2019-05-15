/*
Median Maintenance
Time Complexity: O(NlogN) 
*/

#include <bits/stdc++.h>

using namespace std;

#define DT float

int main()
{
	int N;
	cin>>N;
	DT arr[N];
	DT median[N];
	priority_queue <DT> max_heap;
	priority_queue <DT, vector<DT>, greater<DT>> min_heap;
	for(int n = 0; n<N; n++)
	{
		cin>>arr[n];
		if(max_heap.empty() || arr[n] <= max_heap.top())
			max_heap.push(arr[n]);
		else
			min_heap.push(arr[n]);
		if(max_heap.size()<min_heap.size())
		{
			DT temp = min_heap.top();
			min_heap.pop();
			max_heap.push(temp);
		}
		else if(max_heap.size() > min_heap.size()+1)
		{
			DT temp = max_heap.top();
			max_heap.pop();
			min_heap.push(temp);
		}
		if(n&1)
			median[n] = (min_heap.top() + max_heap.top())/2;
		else
			median[n] = max_heap.top();
	}
	for(int n = 0; n<N; n++)
		cout<<median[n]<<" ";
	cout<<endl;
	return 0;
}