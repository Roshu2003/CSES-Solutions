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

// int N;
vector<int> parent;
vector<int> vis;
vector<int> recStack;
int startPoint = -1;
bool dfs(vector<int> adj[], int node)
{
    vis[node] = 1;
    recStack[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            parent[it] = node;
            if (dfs(adj, it))
            {
                return true;
            }
        }
        else if (recStack[it])
        {
            parent[it] = node;
            startPoint = it;
            return true;
        }
    }
    recStack[node] = 0;
    return false;
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    vis.assign(n, 0);
    recStack.assign(n, 0);
    parent.assign(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && dfs(adj, i) == true)
        {
            break;
        }
    }
    if (startPoint != -1)
    {
        vector<int> cycle;
        cycle.push_back(startPoint + 1);

        int curr = parent[startPoint];
        while (curr != startPoint)
        {
            cycle.push_back(curr + 1);
            curr = parent[curr];
        }
        cycle.push_back(startPoint + 1);
        reverse(all(cycle));

        cout << cycle.size() << Endl;
        for (auto it : cycle)
        {
            cout << it << " ";
        }
        cout << Endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << Endl;
    }
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