#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct Edge
{
	int u,v,cap,flow;
};
struct Dinic
{
	int source,to,m,n;
	vector<Edge>edge;
	vector<int>g[N];
	int vis[N];
	int dis[N];
	int cur[N];
	void clearall(int n)
	{
		for(int i=0;i<n;i++)
			g[i].clear();
		edge.clear();
	}
	void addedge(int u,int v,int cap)
	{
		edge.push_back({u,v,cap,0});
		edge.push_back({v,u,0,0});
		m=edge.size();
		g[u].push_back(m-2);
		g[v].push_back(m-1);
	}
	bool bfs()
	{
		queue<int>q;
		memset(vis,0,sizeof(vis));
		q.push(source);
		dis[source]=0;
		vis[source]=1;
		while(q.size())
		{
			int x=q.front();q.pop();
			vis[x]=1;
			for(auto m:g[x])
			{
				Edge& e=edge[m];
				if(!vis[e.v]&&e.cap>e.flow)
				{
					vis[e.v]=1;
					dis[e.v]=dis[x]+1;
					q.push(e.v);
				}
			}
		}
		return vis[to];
	}
	int dfs(int x,int a)
	{
		if(x==to||a==0)return a;
		int flow=0,f;
		for(int &i=cur[x];i<g[x].size();i++)
		{
			Edge& e=edge[g[x][i]];
			if(dis[e.v]==dis[x]+1&&(f=dfs(e.v,min(a,e.cap-e.flow)))>0)
			{
				e.flow+=f;
				edge[g[x][i]^1].flow-=f;
				flow+=f;
				a-=f;
				if(!a)break;
			}
		}
		return flow;
	}
	int maxflow(int source,int to)
	{
		this->source=source;
		this->to=to;
		int res=0;
		while(bfs())
		{
			memset(cur,0,sizeof(cur));
			res+=dfs(source,to);
		}
		return res;
	}
}dinic;

void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
int main(int argc, char const *argv[])
{
	io();
	int n,m,a,b,i,j;
	scanf("%d%d",&n,&m);
	dinic.clearall(m+2);
	for(int i=m;i>0;i--)
		dinic.addedge(0,i,1);
	for(int i=n;i>m;i--)
		dinic.addedge(i,n+1,1);
	while(scanf("%d%d",&a,&b)==2)
	{
		dinic.addedge(a,b,1);
	}
	int flow=dinic.maxflow(0,n+1);
	printf("%d\n",flow );
	return 0;
}