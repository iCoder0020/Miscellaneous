/*
Binary Search Tree (AVL)
Insert: O(logN)
Remove: O(logN)
Search: O(logN)
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
	int height;
	Node(int x)
	{
		left = NULL;
		right = NULL;
		data = x;
		height = 1;
	}
};

int height(Node* x)
{
	if(x == NULL)
		return 0;
	else 
		return x->height;
}

int balance(Node *x)
{
	if(x == NULL)
		return 0;
	else
		return height(x->left) - height(x->right);
}

Node* rightRotate(Node* x)
{
	Node* y = x->left;
	Node* t2 = y->right;
	
	x->left = t2;
	y->right = x;

	x->height = max(height(x->right), height(x->left))+1;
	y->height = max(height(y->right), height(y->left))+1;

	return y;

}

Node* leftRotate(Node* x)
{
	Node* z = x->right;
	Node* t3 = z->left;

	x->right = t3;
	z->left = x;

	x->height = max(height(x->right), height(x->left))+1;
	z->height = max(height(z->right), height(z->left))+1;

	return z;
}

Node* LLrotate(Node* x)
{
	return rightRotate(x);
}

Node* LRrotate(Node* x)
{
	x->left = leftRotate(x->left);
	return rightRotate(x);
}

Node* RLrotate(Node* x)
{
	x->right = rightRotate(x->right);
	return leftRotate(x);
}

Node* RRrotate(Node* x)
{
	return leftRotate(x);
}

void inorder(Node* x)
{
	if(x)
	{
		inorder(x->left);
		cout<<x->data<<" ";
		inorder(x->right);
	}
}

Node* insert(Node* root, int x)
{
	if(root)
	{
		if(x<=root->data)
			root->left = insert(root->left, x);
		else
			root->right = insert(root->right, x);
		root->height = max(height(root->left), height(root->right))+1;

		int b = balance(root);

		if(b>1 && x<root->left->data)
			root = LLrotate(root);
		else if(b>1 && x>root->left->data)
			root = LRrotate(root);
		else if(b<-1 && x<root->right->data)
			root = RLrotate(root);
		else if(b<-1 && x>root->right->data)
			root = RRrotate(root);

		return root;
	}
	else
		return new Node(x);
}

Node* find_inorder_successor(Node* root)
{
	Node* temp = root->right;
	while(temp->left != NULL)
		temp = temp->left;
	return temp;
}

Node* remove(Node* root, int x)
{
	if(root == NULL)
		return NULL;
	else if(x < root->data)
		root->left = remove(root->left, x);
	else if(x > root->data)
		root->right = remove(root->right, x);
	else
	{
		if(root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
 			return temp;
		}
		else if(root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else
		{
			Node* temp = find_inorder_successor(root);
			root->data = temp->data;
			root->right = remove(root->right, temp->data);
		}
	}

	int b = balance(root);

	if(b>1 && x<root->left->data)
		root = LLrotate(root);
	else if(b>1 && x>root->left->data)
		root = LRrotate(root);
	else if(b<-1 && x<root->right->data)
		root = RLrotate(root);
	else if(b<-1 && x>root->right->data)
		root = RRrotate(root);

	return root;
}

int search(Node* root, int x)
{
	if(root)
	{
		if(x == root->data)
			return 1;
		else if(x < root->data)
			return search(root->left, x);
		else
			return search(root->right, x);
	}
	else
		return -1;
}

int main()
{
	int N;
	cin>>N;

	Node *root = NULL;

	for(int n = 0; n<N; n++)
	{
		int temp;
		cin>>temp;
		root = insert(root, temp);
	}

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	root = remove(root, -5);
	root = remove(root, 0);

	cout<<"Inorder: ";
	inorder(root);
	cout<<endl;

	return 0;
}