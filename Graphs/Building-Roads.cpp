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

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = find(parent[node]); // Path compression
    }

    void Union(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

void Solve()
{
    int n, m;
    cin >> n >> m;
    DisjointSet dsu(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        dsu.Union(u, v);
    }

    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        st.insert(dsu.find(i)); // Collect unique parent representatives
    }

    vector<int> v(st.begin(), st.end());

    cout << v.size() - 1 << Endl; // Number of edges needed to connect all components

    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i - 1] << " " << v[i] << Endl; // Connecting components
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