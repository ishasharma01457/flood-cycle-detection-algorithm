#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class Node
{
public:
	int x;
	Node* next;

	Node(int x)
	{
		this->x = x;
		next = NULL;
	}
};


Node* head = NULL;
class Linked
{
public:
	void insertion(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
			head = newNode;
		else
        {
			newNode->next = head;
			head = newNode;
		}
	}

	bool findloop()
	{
		Node *slowPointer = head,
			*fastPointer = head;

		while (slowPointer != NULL
			&& fastPointer != NULL
			&& fastPointer->next != NULL)
        {
			slowPointer = slowPointer->next;
			fastPointer = fastPointer->next->next;
			if (slowPointer == fastPointer)
				return 1;
		}

		return 0;
	}
};

int main()
{
	Linked l1;
	l1.insertion(15);
	l1.insertion(20);
	l1.insertion(17);
	l1.insertion(11);
	l1.insertion(10);
    l1.insertion(22);
    l1.insertion(18);


	Node* temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = head;

	if (l1.findloop())
		cout << "Cycle exists" << endl;
	else
		cout << "Cycle does not exists" << endl;

	return 0;
}

