#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define forr(i, n) for(int i=0;i<(n);i++)
#define forv(i, v) for(int i=0;i<(int)v.size();i++)
#define fords(it, ds) for(auto it = ds.begin();it!=ds.end();it++)
#define OO (int)1e9
#define fr first
#define se second
#define II pair<int, int>
#define pb push_back
#define dist(x,y,xx,yy) sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy))
///////////////////// Solution Code
struct UnionFind{
	vector<int> rank, parent;
	int forests;
	UnionFind(int n)
	{
		rank = vector<int>(n);
		parent = vector<int> (n);
		forests = n;
		for(int i=0;i<n;i++) parent[i]=i,rank[i]=1;
	}
	int find_set(int x)
	{
		if(parent[x] == x)
			return x;
		return parent[x]= find_set(parent[x]);
	}
	void link(int x, int y)
	{
		if(rank[x]>rank[y]) swap(x,y);
		parent[x] = y;
		if(rank[x] == rank[y]) rank[y]++;
	}
	bool union_sets(int x, int y)
	{
		x = find_set(x), y = find_set(y);
		if(x != y)
		{
			link(x,y);
			forests -- ;
		}
		return x!=y;
	}
};
struct edge{
	int from,to;
	ll cost;
	edge(int from=0, int to=0, ll cost=0):from(from),to(to),cost(cost){}
	bool operator < (const edge & e )const{return cost>e.cost;}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
		#ifdef _WIN64
		freopen("C:\\Users\\mamdouh\\Desktop\\a1.in","r",stdin);
		freopen("C:\\Users\\mamdouh\\Desktop\\A2.out","w",stdout);
		#elif __linux__
		freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/a1.in","r",stdin);
		freopen("/media/mamdouh/System/Users/Mamdouh/Desktop/A2.out","w",stdout);
		#endif
	#endif
	int T,CNT=0;
	cin>>T;
	while(T--)
	{
		cout<<"Case "<<++CNT<<":\n";
		int n;
		cin>>n;
		priority_queue<edge> q;
		UnionFind u(n);
		string s;
		int v;
		forr(i,n)
		{
			forr(j,n)
			{
				cin>>s;
				if(i>j) continue;
				if(s.find(",")!=-1)
				{
					s=s.substr(0,s.length()-1);
				}
				if(s =="0")continue;
				v = stoi(s);
				q.push(edge(i,j,v));
			}
		}	
		edge lord;
		while(!q.empty())
		{
			lord = q.top();
			q.pop();
			if(u.find_set(lord.from)!=u.find_set(lord.to))
			{
				u.union_sets(lord.from,lord.to);
				cout<<(char)('A'+lord.from)<<"-"<<(char)('A'+lord.to)<<" "<<lord.cost<<"\n";
			}
		}
	}
	return 0;
}