#include <iostream>
#define inf 9999
using namespace std;

int n;
int table[100][100];

int dijkstra(int mulai, int akhir)
{
    int dist[n];
    bool visited[n];
    int i, j, v;
    for (i = 1; i <= n; i++)
    {
        dist[i] = inf;
    }
    for (i = 1; i <= n; i++)
    {
        visited[i] = false;
    }
    dist[mulai] = 0;
    while (true)
    {
        int u = -1;
        int minDist = inf;
        for (i = 1; i <= n; i++)
        {
            if ((visited[i] == false) && (dist[i] < minDist))
            {
                u = i;
                minDist = dist[i];
            }
        }
        if ((u == -1) || (dist[u] == inf))
        {
            break;
        }
        visited[u] = true;
        for (v = 1; v <= n; v++)
        {
            if (table[u][v] != 0)
            {
                if (dist[v] > dist[u] + table[u][v])
                {
                    dist[v] = dist[u] + table[u][v];
                }
            }
        }
    }

    return dist[akhir];
}

int main()
{
    int mulai, akhir;
    int i, j;
    cout << "Masukkan banyak node: ";
    cin >> n;
    cout << "Masukkan jarak node secara matriks: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
        cout << "\n";
    }
    int jawab = 0;
    char x;
    while (jawab == 0)
    {
        cout << "Masukkan node start(awal): ";
        cin >> mulai;
        cout << "Masukkan node finish(akhir): ";
        cin >> akhir;
        cout << "jarak minimal dari node " << mulai << " ke " << akhir << " : " << dijkstra(mulai, akhir) << endl;
        cout << ("Apakah ingin melanjutkan program? (y/n) ");
        cin >> x;
        if (x == 'y' || x == 'Y')
        {
            jawab = 0;
        }
        else if (x == 'n' || x == 'N')
        {
            cout << ("Terima Kasih");
            jawab = 1;
        }
        else
        {
            cout << ("Input salah y atau n!");
        }
    }
}
