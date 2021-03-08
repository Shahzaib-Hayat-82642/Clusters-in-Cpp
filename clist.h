#include <iostream>
#include <string>
#include <queue>

using namespace::std;

class clist
{
private:
	struct Node
	{
		string name;
		int Degree;

		Node* Next = NULL;
	};
	int N = 0;
	int E = 0;
	float d;
	queue<Node> Queue;
	
	
public:
	void NodeAdder(string name, int Degree)
	{
		Node temp;
		temp.name = name;
		temp.Degree = Degree;

		Queue.push(temp);

		N = N + 1;
		E = E + Degree;
	}
	float Density()
	{
		d = (2 * float(E)) / (float(N) * (float(N) - 1));
		return d;
	}
	void Displayclist()
	{
		Node* temp = &Queue.front();
		while (temp != NULL)
		{
			cout << temp->name << "(" << temp->Degree << ")" << "  ";
			temp = temp->Next;
		}
	}
};