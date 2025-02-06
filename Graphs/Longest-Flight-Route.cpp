#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
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

const int N = 1e5 + 5;
vector<int> adj[N], order;
vector<int> parent(N, -1), dp(N, INT_MIN);
int n, m;

void topologicalSort(int node, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            topologicalSort(neighbor, visited);
        }
    }
    order.push_back(node);
}
void Solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            topologicalSort(i, visited);
        }
    }
    reverse(order.begin(), order.end());

    dp[1] = 1;
    for (int u : order)
    {
        if (dp[u] == INT_MIN)
            continue;
        for (int v : adj[u])
        {
            if (dp[u] + 1 > dp[v])
            {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }
    if (dp[n] == INT_MIN)
    {
        cout << "IMPOSSIBLE" << Endl;
        return;
    }
    vector<int> path;
    for (int i = n; i != -1; i = parent[i])
    {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto it : path)
        cout << it << " ";
    cout << Endl;
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