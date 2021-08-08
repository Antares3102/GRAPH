#include<iostream>
#include<ctime>
using namespace std;

// Đề: Biễu diễn đồ thị bằng danh sách kề 

class AdjList
{
private:
	int n; // Số đỉnh của đồ thị
	int** matrix; // Con trỏ cấp 2 để khai báo ma trận
	void allocated() {
		matrix = new int* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
		}
	}
public:
	AdjList() { this->n = 0; }
	~AdjList()
	{
		for (int i = 0; i < n; i++)
			delete[]matrix[i];
		delete[]matrix;
		this->n = 0;
	}

	void Input()
	{
		cout << "\nEnter number vertex of graph: ";
		cin >> this->n;
		int flag;
		this->allocated();
		cout << "\nMenu: \n\t1.Manual Input \n\t2.Automatic Random\n===================================";
		do {
			cout << "\nChoose your input method: ";
			cin >> flag;
		} while (flag < 1 || flag > 2);

		if (flag == 1)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					this->matrix[i][j] = 0;
			cout << "\n\t===== Manual Input =====";
			for (int i = 0; i < n; i++)
			{
				cout << "\nVertex " << i + 1 << ":\n";
				for (int j = 0; j <= i; j++)
				{
					if (i == j)
					{
						matrix[i][j] = 0;
						continue;
					}
					else
					{
						do {
							cout << "\tv" << j + 1 << ": ";
							cin >> this->matrix[i][j];
						} while (matrix[i][j] < 0 || matrix[i][j] > 1);
					}

				}
			}
			Standard();
		}
		else if (flag == 2)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j <= n; j++)
				{
					if (i == j)
						matrix[i][j] = 0;
					else
						this->matrix[i][j] = rand() % 2 - 0;
				}
			}
			Standard();
		}
	}

	void Standard()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				this->matrix[j][i] = this->matrix[i][j];
			}
		}
	}

	void Output()
	{
		cout << endl;
		cout << "  _";
		for (int i = 0; i < n - 1; i++)
		{
			cout << "   ";
		}
		cout<<"   _";
		cout << endl;
		for (int i = 0; i < n - 1; i++)
		{
			cout << " |  ";
			for (int j = 0; j < n; j++)
			{
				cout << matrix[i][j] << "  ";
			}
			cout << "|";
			if (i == (n / 2) - 1)
			{
				cout << " = G(" << n << ";" << this->GetEdges() << ")";
			}
			cout << endl;
		}
		cout << " |_ ";
		for (int i = 0; i < n ; i++)
		{
			cout << matrix[n-1][i];
			if (i == n - 1)
				cout << " _|";
			else cout << "  ";
		}

	}
	
	int GetEdges()
	{
		int k = 0;
		for (int i = 0; i < this->n; i++)
		{
			for (int j = 0; j < this->n; j++)
				k = k + matrix[i][j];
		}
		return k;
	}
};


int main()
{
	srand(time(NULL));
	cout << "\n\n\t\t========== Representing a AdjList by Adjacency List =========";
	AdjList X;
	X.Input();
	cout << "\n\n\t\t\t=============== Adjacency List ==============";
	X.Output();
	cout << "\n\n\n";
	system("pause");
	return 0;

}