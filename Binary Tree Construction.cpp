/*
Tree Construction
Time Complexity: O(N^2)/O(N^3)
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	string data;
	Node(string x)
	{
		left = NULL;
		right = NULL;
		data = x;
	}
};

void preOrder(Node* root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(Node* root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void postOrder(Node* root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
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

int find_element(string str[], string val, int l, int r)
{
	for(int i = l; i<r; i++)
	{
		if(str[i] == val)
		{
			return i;
		}
	}
	return -1;
}

Node* pre_in(string pre[], string in[], int l, int r)
{
	static int preIndex = 0;
	if(l>=r)
	{
		return NULL;
	}
	else
	{
		Node* root = new Node(pre[preIndex]);
		preIndex++;

		int i = find_element(in, root->data, l, r);

		root->left = pre_in(pre, in, l, i);
		root->right = pre_in(pre, in, i+1, r);
		
		return root;
	}
}

Node* in_lev(string in[], string lev[], int l, int r, int N)
{
	if(l>=r)
	{
		return NULL;
	}
	else
	{
		int i;
		for(int n = 0; n<N; n++)
		{
			i = find_element(in, lev[n], l, r);
			if(i != -1)
			{
				break;
			}
		}

		Node* root = new Node(in[i]);

		root->left = in_lev(in, lev, l, i, N);
		root->right = in_lev(in, lev, i+1, r, N);

		return root;
	}
}

int main()
{
	int N;
	cin>>N;
	string S[4][N];
	string order[4] = { "PreOrder Traversal: ", 
						"InOrder Traversal: ", 
						"PostOrder Traversal: ", 
						"LevelOrder Traversal: "};
	for(int m = 0; m<4; m++)
	{
		for(int n = 0; n<N; n++)
		{
			cin>>S[m][n];
		}
	}

	// Node* root = pre_in(S[0], S[1], 0, N);

	Node* root = in_lev(S[1], S[3], 0, N, N);

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