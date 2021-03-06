#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[1000000]={};
int visit[1000000]={};
vector <int> tree[1000000];

void find_parent(int cur)
{
    visit[cur]=1;
    for (int j=0; j<tree[cur].size(); j++)
    {
        int next=tree[cur][j];
        if (visit[next]==0)
        {
            parent[next]=cur;
            find_parent(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=0; i<n-1; i++)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    find_parent(1);
    for (int i=2; i<=n; i++) cout << parent[i] << "\n";
    return 0;
}
