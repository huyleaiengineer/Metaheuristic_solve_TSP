#include <bits/stdc++.h>
using namespace std;

/// Cac bien
int n;
vector<vector<int>> graph;

/// Cac ham
void docFile(string s);
void show2DArr(vector<vector<int>> a);

/// Thuat toan gts1
pair<int, vector<int>> gts1(int u)
{
    int cost = 0;
    vector<int> path;
    vector<int> vis(n+1);
    vis[u] = true;
    path.push_back(u);
    int v = u;
    for (int i = 1; i < n; i++)
    {
        int w, minw = INT_MAX;
        for (int j = 1; j <=n; j++)
            if (!vis[j])
                if (graph[v][j] < minw){
                    minw = graph[v][j];
                    w = j;
                }
        path.push_back(w);
        cost += graph[v][w];
        vis[w] = true;
        v = w;
    }
    cost += graph[v][u];
    return {cost, path};
}


int main()
{
    clock_t st, en;
    string s1 = "tsp1.atsp";
    string s = "INPUTDATA/" + s1;
    docFile(s);
    cout << "n = " << n << '\n';
    //show2DArr(graph);
    ofstream f("./greedy/greedy_"+s1);
    st = clock();
    vector<pair<int, vector<int>>> sol;
    for (int i = 1; i <= n; i++)
        sol.push_back(gts1(i));
    sort(sol.begin(), sol.end(), [](pair<int, vector<int>> a, pair<int, vector<int>> b){return a.first < b.first;});
    for (auto i : sol)
    {
        f << i.first << '\n';
        for (auto j : i.second)
            f << j << ' ';
        f << '\n';
    }
    en = clock();
    f << "Thoi gian = " << (en-st)/1000.0 << '\n';
    return 0;
}

void docFile(string s)
{
    ifstream f(s);
    string s1;
    for (int i = 1; i <= 7; i++)
    {
        getline(f, s1);

        if (i == 4){
          n = stoi(s1.substr(11));
          //cout << "n = " << n << '\n';
        }
    }
    graph.resize(n+1);
    for (int i = 1; i <= n; i++)
        graph[i].resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++){
            f >> graph[i][j];
            //cout << graph[i][j] << ' ';
        }
    }
}

void show2DArr(vector<vector<int>> a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
