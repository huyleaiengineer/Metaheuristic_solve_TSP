#include <bits/stdc++.h>
using namespace std;

string s1;

/// Cac bien
int n;
vector<vector<int>> graph;
vector<pair<int, vector<int>>> pop(200);

/// Cac tham so thuat toan bee
int N; /// Kich thuoc quan the
int p; /// Tim kiem lan can
int h; /// Tim kiem lan can nhieu lan
int nep, nsp;

/// Dieu kien dung tim kiem lan can
int soLanLapLocalSearch;
int loigiatoiuu;

/// Cac ham
void docFile(string s);
void show2DArr(vector<vector<int>> a);
/// Khoi tao 1 loi giai ngau nhien
pair<int, vector<int>> randomSolution(int n);
void randomPop(int N);
int tinhCost(vector<int> path);
/// Cac thuat toan tim kiem lan can
pair<int, vector<int>> dao(pair<int, vector<int>> s);
pair<int, vector<int>> chen(pair<int, vector<int>> s);
pair<int, vector<int>> doicho(pair<int, vector<int>> s);
pair<int, vector<int>> traodoiqualai(pair<int, vector<int>> s);

/// Thuat toan bee
vector<pair<int, vector<int>>> tmp;

pair<int, vector<int>> bee(){
   // pop.clear();
    cout << "Popsize truoc khi tao ngau nhien = " << pop.size() << "\n";
    cout << "Pop capacity truoc khi tao ngau nhien = " << pop.capacity() << "\n";
    cout << "N = " << N << '\n';
    randomPop(N);
    cout << "Popsize sau khoi tao = " << pop.size() << "\n";
    cout << "truoc dem\n";

    int dem = 1;

    cout << "Quan the theo lan lan lap " << dem << '\n';
        for (auto i : pop)
            cout << i.first << ' ';
        cout << '\n';


    sort(pop.begin(), pop.end());
    int best_cost = pop[0].first;
    cout << "best_cost = " << best_cost << "\n";
    while (dem <= 100 && best_cost > loigiatoiuu)
    {
        dem++;
        //cout << "best_cost = \n";
        soLanLapLocalSearch *= nep;

        for (int i = 0; i <= h; i++)
        {

            //cout << "soLan = " << soLanLapLocalSearch << '\n';
           //for (int i = 1; i <= nep; i++)
           //{
               int option = rand()%4;
               //cout << "option = " << option << '\n';
               if (option == 0){
                    pair<int, vector<int>> tam = dao(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
               else if (option == 1){
                    pair<int, vector<int>> tam = chen(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
               else if (option == 2){
                    pair<int, vector<int>> tam = doicho(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
               else{
                    pair<int, vector<int>> tam = traodoiqualai(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
          // }
          // cout << "Best Lan can cua ca the trong h " << i << " = " << pop[pop.size()-1].first << '\n';
        }

        soLanLapLocalSearch /= nep;
        soLanLapLocalSearch *= nsp;
        for (int i = h+1; i < p; i++)
        {

            //cout << "soLan = " << soLanLapLocalSearch << '\n';
            //for (int i = 1; i <= nsp; i++)
           //{
               int option = rand()%4;
               //cout << "option = " << option << '\n';
               if (option == 0){
                    pair<int, vector<int>> tam = dao(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
               else if (option == 1){
                    pair<int, vector<int>> tam = chen(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
               else if (option == 2){
                    pair<int, vector<int>> tam = doicho(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
               else{
                    pair<int, vector<int>> tam = traodoiqualai(pop[i]);
                    if (tam.first != pop[i].first)
                        pop.push_back(tam);
                    if (tam.first < pop[i].first)
                        swap(pop[i], pop[pop.size()-1]);
               }
          // }
           //cout << "Best Lan can cua ca the trong p-h " << i << " = " << pop[pop.size()-1].first << '\n';
        }
        soLanLapLocalSearch /= nsp;
        //for (int i = p+1; i < N; i++)
            //pop.push_back(randomSolution(n));
        sort(pop.begin(), pop.end(), [](pair<int, vector<int>> a, pair<int, vector<int>> b){return a.first < b.first;});

        cout << "pop.size truoc xoa = " << pop.size() << '\n';

        if (pop[0].first < best_cost)
        {
            best_cost = pop[0].first;
            dem = 1;
        }
        // Chon loc: 20% ca the tot nhat
        int k = (int)(0.8*N);
        //random_shuffle(pop.begin()+1, pop.end());

        cout << "Quan the theo lan lan lap " << dem << '\n';
        for (auto i : pop)
            cout << i.first << ' ';
        cout << '\n';

        for (int i = 0; i <= h; i++)
        {
            tmp.push_back(pop[i]);
        }
        vector<bool> vis(pop.size()+10);
        for (int i = h+1; i <= p; i++)
        {
            int x;
            do{
                x = rand()%(pop.size()-1-k+1)+k;
            }while(vis[x]);
            vis[x] = true;
            tmp.push_back(pop[x]);
        }
        pop = tmp;
        tmp.clear();
        for (int i = p+1; i < N; i++)
            pop.push_back(randomSolution(n));
        random_shuffle(pop.begin()+1, pop.end());
        cout << dem << " lan bee khong cai thien, cost = " << pop[0].first << ", popsize = " << pop.size() << "\n";
    }

    return pop[0];
}


int main()
{
    srand(time(nullptr));
    clock_t st, en;
    s1 = "tsp1.atsp";
    loigiatoiuu = 736; // Dành cho bài toán đã biết lời giải tối ưu, nếu thuật toán tìm ra lời giải kết thúc ! Bình thường để = 0
    string s = "INPUTDATA/"+s1;
    docFile(s);
    cout << "n = " << n << '\n';


    N = 75;
    pop.resize(N);
    soLanLapLocalSearch = 100*n;
    p = (int)(0.8*N);
    h = (int)(0.15*N);
    cout << "h = " << h << '\n';
    nep = 6, nsp = 2;

    st = clock();
    pair<int, vector<int>> sol = bee();
    en = clock();
    cout << "\n*****************************\n";
    cout << "KET QUA THUAT TOAN BEE\n";
    cout << "cost = "  << sol.first << '\n';
    cout << "Duong di\n";
    for (auto i : sol.second)
        cout << i << ' ';
    cout << '\n';
    cout << "Thoi gian = " << (en - st)/1000.0 << '\n';


    ofstream f("./bee/bee_"+s1);
    f << "cost = "  << sol.first << '\n';
    f << "Duong di\n";
    for (auto i : sol.second)
        f << i << ' ';
    f << '\n';
    f << "Thoi gian = " << (en - st)/1000.0 << '\n';
    f.close();
    return 0;
}

/// Ham thich nghi
int tinhCost(vector<int> path)
{
    int cost = 0;
    for (int i = 0; i < n-1; i++)
        cost += graph[path[i]][path[i+1]];
    cost += graph[path[n-1]][path[0]];
    return cost;
}


pair<int, vector<int>> randomSolution(int n)
{
   // ofstream fo("check250.tsp", ofstream::app);
    vector<bool> vis(n);
    for (int i = 0; i < n; i++)
        vis[i] = false;
    vector<int> res(n);
     int x;
    for (int i = 0; i < n; i++){
        do{
            x = rand()%(n);
        }while(vis[x]);
        res[i] = x+1;
        vis[x]=true;
    }
    int cost = tinhCost(res);
   // fo << cost << '\n';
    //for (auto i : res)
       // fo << i << ' ';
//fo << "\n\n";
//fo.close();
    return {cost, res};
}

void randomPop(int N)
{
    //25% la greedy, 75% la ngau nhien
    int k = round(0.25*N);

   // ofstream fo("check250.tsp");

    ifstream f("./greedy/greedy_"+s1);
    int x;
    vector<int> tmp(n);
    k = min(k, n);
    cout << "k = " << k << '\n';
    for (int i = 1; i <= k; i++)
    {
        f >> x;
        //fo << x << '\n';
        for (int j = 0; j < n; j++){
            f >> tmp[j];
           // fo << tmp[j] << ' ';
        }

       // fo << "\n\n";
        pop[i-1] = {x, tmp};
    }
    //fo.close();
    for (int i = k+1; i <= N; i++){
        //cout << i << '-';
        pop[i-1] = randomSolution(n);
    }
    cout << "pop size trong ham random pop= " << pop.size() << '\n';
    f.close();
    ///return sol;
}

/// Local search

pair<int, vector<int>> dao(pair<int, vector<int>> s)
{
    int dem = 0;
    while (dem <= soLanLapLocalSearch/10){
        dem ++;
        int u, v;
        do{
            u = rand()%(n);
            v = rand()%n;
        }while (u == v);
        vector<int> tmp = s.second;
        reverse(tmp.begin()+u, tmp.begin()+v+1);
        int chiPhi = tinhCost(tmp);
        if (chiPhi < s.first){
            s = {chiPhi, tmp};
            dem = 1;
        }

        //if (dem%(soLanLapLocalSearch/10) == 0)
            //cout << dem << "LS - dao chua thay doi\n";
    }
    return s;
}

pair<int, vector<int>> chen(pair<int, vector<int>> s)
{
    int dem = 0;
    while (dem <= soLanLapLocalSearch/10){
        dem ++;
        int u, v;
        do{
            u = rand()%(n);
            v = rand()%n;
        }while (u == v);
        vector<int> tmp = s.second;
        int x = tmp[v];
        tmp.erase(tmp.begin()+v);
        tmp.insert(tmp.begin()+u, x);
        int chiPhi = tinhCost(tmp);
        if (chiPhi < s.first){
            s = {chiPhi, tmp};
            dem = 1;
        }

       // if (dem%(soLanLapLocalSearch/10) == 0)
            //cout << dem << "Ls chen chua thay doi\n";
    }
    return s;
}

pair<int, vector<int>> doicho(pair<int, vector<int>> s)
{
    int dem = 0;
    while (dem <= soLanLapLocalSearch*20){
        dem ++;
        int u, v, w;
        do{
            u = rand()%(n);
            v = rand()%n;
            w = rand()%n;
        }while (u == v || v == w || u == w);
        if (u > v)
            swap(u, v);
        vector<int> tmp = s.second;
        vector<int> sub_tmp(tmp.begin()+u, tmp.begin()+v);
        tmp.erase(tmp.begin()+u, tmp.begin()+v);
        if (w > tmp.size())
            w = tmp.size()-1;
        tmp.insert(tmp.begin()+w, sub_tmp.begin(), sub_tmp.end());

        int chiPhi = tinhCost(tmp);
        if (chiPhi < s.first){
            s = {chiPhi, tmp};
            dem = 1;
        }

       // if (dem%(soLanLapLocalSearch/10) == 0)
           // cout << dem << "Ls doi cho chua thay doi\n";
    }
    return s;
}

pair<int, vector<int>> traodoiqualai(pair<int, vector<int>> s)
{
     int dem = 0;
    while (dem <= soLanLapLocalSearch*10){
        dem ++;
        int u, v;
        do{
            u = rand()%(n);
            v = rand()%n;
        }while (u == v);
        vector<int> tmp = s.second;
        swap(tmp[u], tmp[v]);
        int chiPhi = tinhCost(tmp);
        if (chiPhi < s.first){
            s = {chiPhi, tmp};
            dem = 1;
        }

        //if (dem%(soLanLapLocalSearch/10) == 0)
            //cout << dem << "LS - dao chua thay doi\n";
    }
    return s;
}




void docFile(string s)
{
    cout << s << '\n';
    ifstream f(s);
    string s1;

    for (int i = 1; i <= 7; i++)
    {
        getline(f, s1);
        //cout << s1 << "\n";
        if (i == 4){
          n = stoi(s1.substr(11));
        }
    }
    graph.resize(n+1);
    for (int i = 1; i <= n; i++)
        graph[i].resize(n+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            f >> graph[i][j];
    }
    f.close();
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
