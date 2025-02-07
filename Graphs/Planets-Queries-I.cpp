#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define roundUp(a, b) ((a + b - 1) / b)
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'
#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }
const int MOD = 1e9 + 7;

void Solve()
{
    int n, q;
    cin >> n >> q;
    int m = 30;
    vector<vector<int>> sparseTable(m + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
    {
        cin >> sparseTable[0][i];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sparseTable[i - 1][j] != -1)
                sparseTable[i][j] = sparseTable[i - 1][sparseTable[ i- 1][j]];
        }
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        int ans = x;
        for (int i = 0; i < m; i++)
        {
            if (k & (1 << i))
            {
                if(ans == -1)break;
                ans = sparseTable[i][ans];
            }
        }
        cout << ans << endl;
    }
}

int32_t main()
{
    Roshan();
    int t;
    t = 1;
    // cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}