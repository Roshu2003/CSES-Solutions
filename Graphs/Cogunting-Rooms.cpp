#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'
const int MOD = 1e9 + 7;

#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }
void dfs(int i, int j, vector<vector<char>> &v, vector<vector<int>> &vis)
{
    vis[i][j] = 1;

    int drow[4] = {1, 0, -1, 0};
    int dcol[4] = {0, 1, 0, -1};

    for (int k = 0; k < 4; k++)
    {
        int nr = i + drow[k];
        int nc = j + dcol[k];
        if (nr >= 0 && nr < v.size() && nc >= 0 && nc < v[0].size() && v[nr][nc] == '.' && !vis[nr][nc])
        {
            dfs(nr, nc, v, vis);
        }
    }
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '.' && vis[i][j] == 0)
            {
                dfs(i, j, v, vis);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

int32_t main()
{
    Roshan();
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        Solve();
    }
    return 0;
}