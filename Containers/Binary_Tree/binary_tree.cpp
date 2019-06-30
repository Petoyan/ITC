#include <iostream>

struct Node
{
	int value;
	Node* left;
        Node* right;
};

class binary_tree
{
private:
	Node* root;
public:
	binary_tree()
	{
		root = NULL;
	}
	binary_tree(int val)
	{
		root->value = val;
	}
	~binary_tree()
	{
		delete_tree(root);
	}
	void delete_tree(Node* left)
	{
		if(left != NULL)
		{
			delete_tree(left->left);
			delete_tree(left->right);
			delete left;
		}
	}
	void insert(int val, Node* left)
	{
		if(val < left->value)
		{
			if(left->left != NULL)
			{
			insert(val,left->left);
			}
			else
			{
				left->left = new Node;
				left->left->value = val;
				left->left->left = NULL;
				left->left->right = NULL;
			}
		}
		else if(val >= left->value)
		{
			if(left->right != NULL)
			{
				insert(val,left->right);
			}
			else
			{
				left->right = new Node;
				left->right->value = val;
				left->right->left = NULL;
				left->right->right = NULL;
			}
		}

	}
	void insert(int val)
	{
		if(root != NULL)
		{
			insert(val, root);
		}
		else
		{
			root = new Node;
			root->value = val;
			root->left = NULL;
			root->right = NULL;
		}
	}
	Node* search(int val)
	{
		return search(val, root);
	}
	Node* search(int val, Node* left)
	{
		if(left != NULL)
		{
			if(left->value == val)
			{
				return left;
			}
			if(val < root->value)
			{
				return search(val, left->left);
			}
			else
			{
				return search(val, left->right);
			}
		}
		else
		{
			return NULL;
		}
	}
	void print(Node* left)
	{
		if(left != NULL)
		{
			print(left->left);
			std::cout << left->value << "  " ;
			print(left->right);
		}
	}
	void print()
	{
		std::cout << root->value << "  ";
		print(root->left);
		print(root->right);
		std::cout << "\n";
	}

};

int main(){

	binary_tree *tree = new binary_tree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);
	Node* n = tree->search(14);
	std::cout << "Searching resulte = " << n->value << "\n";
	tree->print();
	delete tree;

} 
