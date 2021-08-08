#include<iostream>
#include<cmath>
using namespace std;

int minKey(int* key, bool* mstSet, int n)
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < n; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

void printMST(int* parent, int** graph, int n)
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < n; i++)
		cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}
void primMST(int** graph, int n)
{
	int* parent = new int[n];
	int* key = new int[n];
	bool* mstSet = new bool[n];
	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < n - 1; count++)
	{
		int u = minKey(key, mstSet, n);
		mstSet[u] = true;
		for (int v = 0; v < n; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
	printMST(parent, graph,n);
}

void Input(int** a, int n)
{
	cout << "\n\t========== Enter element of Graph ==========";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "\nEnter the value at position a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
}

void DeleteData(int** graph, int& n)
{
	for (int i = 0; i < n; i++)
		delete graph[i];
	delete graph;
	n = NULL;
}

int main()
{
	int n;
	cout << "Enter the size of graph: ";
	cin >> n;
	int** graph = new int* [n];
	for (int i = 0; i < n; i++)
		graph[i] = new int[n];
	Input(graph, n);
	primMST(graph, n);
	DeleteData(graph, n);
	cout << endl;
	system("pause");
	return 0;
}

