#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define Endl '\n'

#define Roshan()                          \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
        cout.tie(0);                      \
    }

void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        u--;
        v--;
        adj[u].push_back({v, x});
        // adj[v].push_back({u, x});
    }
    vector<vector<int>> dp(n, vector<int>(2, LLONG_MAX));
    dp[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {0, 0}});
    while (!q.empty())
    {
        auto it = q.top();
        q.pop();
        int d = it.first;
        int node = it.second.first;
        int op = it.second.second;
        if (d > dp[node][op])
            continue;
        for (auto it : adj[node])
        {
            int wt = it.second;
            int adjnode = it.first;
            if (op == 1)
            {
                if (d + wt < dp[adjnode][1])
                {
                    dp[adjnode][1] = d + wt;
                    q.push({dp[adjnode][1], {adjnode, 1}});
                }
            }
            else
            {
                if (d + wt < dp[adjnode][0])
                {
                    dp[adjnode][0] = d + wt;
                    q.push({dp[adjnode][0], {adjnode, 0}});
                }
                if (d + wt / 2 < dp[adjnode][1])
                {
                    dp[adjnode][1] = d + wt / 2;
                    q.push({dp[adjnode][1], {adjnode, 1}});
                }
            }
        }
    }
    int ans = LLONG_MAX;
    ans = min(ans, dp[n - 1][0]);
    ans = min(ans, dp[n - 1][1]);
    if (ans != LLONG_MAX)
    {
        cout << ans << Endl;
        return;
    }
    cout << -1 << Endl;
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