#include <bits/stdc++.h>
using namespace std;

int c[1130][1130], n;


int main()
{
    ifstream if1("./bee/bee_tsp1.atsp");
    ifstream f("../TSPLIB/tsp1.atsp");

    int costTrenFile;
    vector<int> duongdi;

    string s1;
    for (int i = 1; i <= 7; i++)
    {
        getline(f, s1);
        //cout << s1 << '\n';
        if (i == 4){
          n = stoi(s1.substr(11));
        }
    }
    cout << "n = " << n << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            f >> c[i][j];
    }

    getline(if1, s1);
    costTrenFile = stoi(s1.substr(7));
    getline(if1, s1);

    duongdi.resize(n);
    for (int i = 0; i < n; i++)
        if1 >> duongdi[i];

    cout << "Kiem tra 1: Tinh Chi phi hanh trinh: \n";
    int tinh = 0;
    for (int i = 0; i < n-1; i++)
        tinh += c[duongdi[i]][duongdi[i+1]];
    tinh += c[duongdi[n-1]][duongdi[0]];

    if (tinh == costTrenFile)
        cout << "Kiem tra 1 pass voi chi phi = " << tinh << '\n';
    else
        cout << "Khong pass kiem tra 1, chi phi trong file " << costTrenFile << ", chi phi thuc tinh = " << tinh << '\n';

    cout << "Kiem tra 2: hanh trinh la chu trinh halmilton: \n";
    sort(duongdi.begin(), duongdi.end());
    bool flag = true;
    for (int i = 0; i < n-1; i++)
        if (duongdi[i] == duongdi[i+1]){
            cout << "Hanh trinh tim bi sai, trung o thanh pho " << i <<  "\n";
            flag = false;
            break;
        }

    if (flag)
        cout << "Kiem tra 2 - pass\n";

    return 0;
}
