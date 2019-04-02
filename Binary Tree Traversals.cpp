/*
Tree Traversals
Time Complexity: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
	Node(int x)
	{
		left = NULL;
		right = NULL;
		data = x;
	}
};

void preOrder(Node* root)
{
	stack <Node*> S;
	Node* temp = root;
	while(temp || !S.empty())
	{
		while(temp)
		{
			S.push(temp);
			cout<<temp->data<<" ";
			temp = temp->left;
		}
		temp = S.top();
		S.pop();
		temp = temp->right;
	}
}

void inOrder(Node* root)
{
	stack <Node*> S;
	Node* temp = root;
	while(temp || !S.empty())
	{
		while(temp)
		{
			S.push(temp);
			temp = temp->left;
		}
		temp = S.top();
		cout<<temp->data<<" ";
		S.pop();
		temp = temp->right;
	}
}

void postOrder(Node* root)
{
	stack <Node*> S;
	Node *current, *previous;
	S.push(root);
	previous = NULL;
	while(!S.empty())
	{
		current = S.top();
		if(!previous || previous->left == current || previous->right == current)
		{
			if(current->left)
				S.push(current->left);
			else if(current->right)
				S.push(current->right);
		}
		else if(current->left == previous)
		{
			if(current->right)
				S.push(current->right);
		}
		else
		{
			cout<<current->data<<" ";
			S.pop();
		}
		previous = current;
	}
}

void levelOrder(Node* root)
{
	if(root)
	{
		queue <Node*> Q;
		Q.push(root);
		while(!Q.empty())
		{
			Node* temp = Q.front();
			if(temp->left)
			{
				Q.push(temp->left);
			}
			if(temp->right)
			{
				Q.push(temp->right);
			}
			cout<<temp->data<<" ";
			Q.pop();
		}
	}
}

int main()
{
	int N;
	cin>>N;

	Node* arr[N+1];

	for(int n = 1; n<=N; n++)
	{
		arr[n] = new Node(n);
	}

	for(int n = 1; n<N; n++)
	{
		int a,b;
		char c;
		cin>>a>>b>>c;
		if(c == 'L')
		{
			arr[a]->left = arr[b];
		}
		else if(c == 'R')
		{
			arr[a]->right = arr[b];
		}
	}

	Node* root = arr[1];

	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;
	levelOrder(root);
	cout<<endl;

	return 0;
}