#include <iostream>

struct Node 
{ 
	int data; 
	struct Node* next; 
	struct Node* prev;
};

struct Node* head = NULL;

class LinkedList
{
public:
	void push_back(int new_data)
	{	
		struct Node* new_node = new  Node(); 
		new_node->data = new_data; 
		new_node->prev = NULL;
		new_node->next = head;
		if(head != NULL)
			new_node->prev = new_node;	
		head = new_node; 
	}
	void DeleteNode(int data)
	{
		Node* prev = head;
		Node* current = head->next; 
		while( current != NULL) 
		{
			if(current->data == data)
			{
				break;
			}
			else 
			{
				prev = current;
				current = current->next;
			}
		}
		if(current == NULL) 
		{
			std::cout << "Can't remove value: no match found.\n";
		} 
		else
		{
			std::cout << "Deleting: " << current->data << "\n";
			prev->next = current->next; 
			delete current; 
		}
	}
	bool find(int value)
	{	
		Node* prev = head;
		Node* current = head->next; 
		while( current != NULL) 
		{
			if(current->data == value)
			{
				return true;
			}
			else 
			{
				prev = current;
				current = current->next;
			}
		}
		if(current == NULL)
		{
			return false;
		}

	}

	void display()
	{ 
		struct Node* print;
		print = head;
		while (print != NULL) 
		{ 
			std::cout<< print->data <<" "; 
			print = print->next; 
		} 
		std::cout << "\n";
	}
	~LinkedList()
	{
		Node* next = head;
		while(next)
		{
			Node* delete_me = next ;
			next = next->next;
			delete delete_me;
		}
	}
};

int main()
{
	LinkedList* ll = new LinkedList();

	ll->push_back(3);
	ll->push_back(1);
	ll->push_back(7);
	ll->push_back(2);
	ll->push_back(9);
	std::cout << ll->find(7) << "\n";
	std::cout<<"The linked list is: ";
	ll->display(); 
	ll->DeleteNode(7);
	ll->display();
	std::cout << ll->find(12) << "\n";
	return 0; 
} 
