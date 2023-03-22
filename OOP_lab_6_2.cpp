#include <iostream>
#include <Windows.h>
#include <memory>

using namespace std;
struct Node
{
public:
	int key;
	Node* right;
	Node* left;
};
Node* createNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	return node;
}
void insert(Node*& root, int key)
{
	if (root == NULL)
	{
		root = createNode(key);
	}
	else if (key < root->key)
	{
		insert(root->left, key);
	}
	else if (key > root->key)
	{
		insert(root->right, key);
	}
	else
	{
		cout << "Duplicate" << endl;
	}
}
void Delete(Node* root, int key)
{
	if (key < root->key)
	{
		if (root->key == key)
		{
			root->key = 0;
			root->left = nullptr;
			root->right = nullptr;
			return;
		}
		Delete(root->left, key);
	}
	else
	{
		if (root->key == key)
		{
			root->key = 0;
			return;
		}
		Delete(root->right, key);
	}
}
void Print(Node* root, int space)
{
	int SPACE = 1;
	if (root == NULL || root->key == 0)
	{
		return;
	}
	space += SPACE;
	Print(root->right, space);
	cout << endl;
	for (int i = 0; i < space; i += SPACE)
	{
		cout << " ";
	}
	cout << root->key << endl;
	Print(root->left, space);
}

void Search(Node* root, int ky)
{
	if (root == nullptr)
	{
		cout << "There isn't " << ky << " in the tree" << endl;
		return;
	}
	if (root->key == ky)
		cout << "There is " << ky << " in the tree" << endl;
	else if (ky < root->key)
	{
		Search(root->left, ky);
	}
	else if (ky > root->key)
	{
		Search(root->right, ky);
	}
	
}



int main()
{
	SetConsoleOutputCP(1251);
	int k = 0;
	cout << "Enter root of tree: ";
	cin >> k;
	Node* root = createNode(k);
	int g = 0;
	while (g != 5)
	{
		cout << "\n1.Insert an item in tree\n";
		cout << "2.Delete an item from tree\n";
		cout << "3.Search an element in tree\n";
		cout << "4. Print the tree\n";
		cout << "5.Exit\n";
		cin >> g;
		switch (g)
		{
		case 1:
			int k;
			cout << "\nInsert an element that you want to put: ";
			cin >> k;
			insert(root, k);
			break;
		case 2:
			int n;
			cout << "\nInsert an element that you want to delete: ";
			cin >> n;
			Delete(root, n);
			break;
		case 3:
			int num;
			cout << "\nEnter a number to search in binary Tree:\n";
			cin >> num;
			Search(root, num);
			break;
		case 4:
			Print(root,10);
			break;
		}
	}
}
