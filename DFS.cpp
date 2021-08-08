#include<iostream>
#include<stack>
#include<cmath>
#include<ctime>
using namespace std;

int n; 
int matrix[1001][1001];
bool visited[1001];
int flag = 0;

void Standard()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[j][i] = matrix[i][j];
        }
    }
}
void Input()
{
    cout << "\nEnter number vertex of graph: ";
    cin >> n;
    int flag;
    cout << "\nMenu: \n\t1.Manual Input \n\t2.Automatic Random\n===================================";
    do {
        cout << "\nChoose your input method: ";
        cin >> flag;
    } while (flag < 1 || flag > 2);

    if (flag == 1)
    {
        cout << "\n\t===== Manual Input =====";
        for (int i = 0; i < n; i++)
        {
            cout << "\nVertex " << i + 1 << ":\n";
            for (int j = 0; j <= i; j++)
            {
                if (i == j)
                    matrix[i][j] = 0;
                else
                {
                    do {
                        cout << "\tv" << j + 1 << ": ";
                        cin >> matrix[i][j];
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
                    matrix[i][j] = rand() % 2 - 0;
            }
        }
        Standard();
    }
}
int GetEdges()
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            k = k + matrix[i][j];
    }
    return k;
}
void Output()
{
    cout << endl;
    cout << "  _";
    for (int i = 0; i < n - 1; i++)
    {
        cout << "   ";
    }
    cout << "   _";
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
            cout << " = G(" << n << ";" << GetEdges() << ")";
        }
        cout << endl;
    }
    cout << " |_ ";
    for (int i = 0; i < n; i++)
    {
        cout << matrix[n - 1][i];
        if (i == n - 1)
            cout << " _|";
        else cout << "  ";
    }
}



void DFS(int u)
{
    cout << "DFS(" << u << "): ";
    stack<int> st;
    st.push(u);
    visited[u] = true;
    cout << u << " ";
    flag++;
    while (!st.empty())
    {
        int v = st.top();
        st.pop();
        for (int t = 1; t <= n; t++)
        {
            if (visited[t] == false && matrix[v][t] == 1)
            {
                cout << t << " ";
                visited[t] = true;
                st.push(v);
                st.push(t);
                flag++;
                break;
            }
        }
    }
}

void Report()
{
    if (flag == n)
        cout << "\n\tThe Graph: Connected!";
    else cout << "\n\tThe Graph: NOT Connected!";
}

int main()
{

    int s; 
    Input();
    Output();
    cout << "\n\nSelect starting vertex: ";
    cin >> s;
    DFS(s);
    Report();
    cout << endl;
    system("pause");
    return 0;
}