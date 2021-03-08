//	M Qais Sultani (2018314)
//	Rizwan Ali Jandan (2018395)
//	Shahzaib Hayat (2018425)

#include <fstream>
#include "clists.h"
#include "List.h"
int N = 40;
int sum;
List IndexList;
int** AdjMatrix = new int* [N];
int** mul = new int* [N];
void dynamic_allocation()
{
	// dynamic allocation
	for (int i = 0; i < N; ++i)
	{
		AdjMatrix[i] = new int[N];
		mul[i] = new int[N];
	}
	// allocation of 0 in all elements of array
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			AdjMatrix[i][j] = 0;
			mul[i][j] = 0;
		}
	}
}
void multiplaying_matrix()
{
	// multiplaying matrix
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < N; ++k)
			{
				mul[i][j] = mul[i][j] + AdjMatrix[i][k] * AdjMatrix[k][j];
			}
		}
	}
	// allocating 0 to the diagonals
	for (int i = 0; i < N; ++i)
	{
		mul[i][i] = 0;
	}
}
void N_assignment()
{
	// assigning Node degree by adding all its nodes
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < N; j++)
		{
			sum = sum + AdjMatrix[i][j];
		}
		IndexList.NAdder(i, sum);
	}
}
void display_AdjMatrix()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << AdjMatrix[i][j] << " ";
		}
		cout << endl;
	}
}
void display_mulMatrix()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << mul[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	dynamic_allocation();
	int x;
	int y;
	string name1 = "\0";
	string name2 = "\0";
	float BondDistance;

	ifstream file("Assignment 5-PPI-I.txt");
	if (file.is_open())
	{
		do {
			name1 = "\0";
			name2 = "\0";
			file >> name1 >> name2 >> BondDistance;
			if (name1 != "\0") {
				// index finding
				x = IndexList.indexReturn(name1);
				y = IndexList.indexReturn(name2);
				
				cout << name1 << " -- " << name2 << "  " << BondDistance << endl;
				cout << x << " -- " << y << endl;
				
				// adj matrix value assigning
				AdjMatrix[x][y] = 1;
				swap(x, y);
				AdjMatrix[x][y] = 1;
			}
		} while (name1 != "\0");
		file.close();
	}
	else
	{
		cout << endl << "'Assignment 5-PPI-I.txt' File could not Open!" << endl << endl;
		system("pause");
		return 0;
	}

	multiplaying_matrix();
	N_assignment();
	cout << "Qais" << endl;
	display_AdjMatrix();
	cout << "Qais" << endl;
	display_mulMatrix();
	
	// displaying degrees
	for (int i = 0; i < N; i++)
	{
		cout << IndexList.NReturn(i) << endl;
	}
}
