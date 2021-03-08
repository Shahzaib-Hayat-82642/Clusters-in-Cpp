#include "clist.h"



class clists
{
private:
	struct Node
	{
		clist list;

		Node* Next = NULL;
	};
	queue<Node> Queues;
	
	
public:
	void NodeAdder()
	{
		Node temp;
		Queues.push(temp);
	}
	
	void Displayclist()
	{
		Node* temp = &Queues.front();
		while (temp != NULL)
		{
			temp->list.Displayclist();
			cout << endl << endl;
			temp = temp->Next;
		}
	}
};