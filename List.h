#include <iostream>
#include <string>

using namespace::std;

class List
{
private:
	struct Node
	{
		string name;
		int index;
		int N;

		Node* Next = NULL;
	};
	int ind = 0;
	Node* indexlist = new Node;
public:
	int Adder(string name)
	{
		Node* temp = new Node;

		temp->name = name;
		temp->index = ind;

		temp->Next = indexlist->Next;
		indexlist->Next = temp;

		ind++;
		return temp->index;
	}
	void NAdder(int index, int sum)
	{
		Node* temp = indexlist->Next;
		while (temp != NULL)
		{
			if (temp->index == index)
			{
				temp->N = sum;
				return;
			}
			temp = temp->Next;
		}
	}
	int indexReturn(string name)
	{
		Node* temp = indexlist->Next;
		while (temp != NULL)
		{
			if (temp->name == name)
			{
				return temp->index;
			}
			temp = temp->Next;
		}
		return Adder(name);
	}
	int NReturn(int index)
	{
		Node* temp = indexlist->Next;
		while (temp != NULL)
		{
			if (temp->index == index)
			{
				return temp->N;
			}
			temp = temp->Next;
		}
	}
};
