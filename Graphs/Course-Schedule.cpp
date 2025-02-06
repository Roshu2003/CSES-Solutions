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

vector<int> vis;
stack<int> st;
vector<int> recStack;
bool isCycle = false;
void dfs(vector<int> adj[], int node)
{
    vis[node] = 1;

    recStack[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(adj, it);
        }
        else if (recStack[it])
        {
            isCycle = true;
        }
    }
    recStack[node] = 0;
    st.push(node);
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
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, i);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    if (!isCycle)
    {
        for (auto it : topo)
            cout << it + 1 << " ";
        cout << Endl;
    }
    else
        cout << "IMPOSSIBLE" << Endl;
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