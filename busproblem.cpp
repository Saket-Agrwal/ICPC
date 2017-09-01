#include <bits/stdc++.h>
using namespace std;

int parent[1000000],rank[1000000];

void link1(int a,int b)
{
if(rank[a]>rank[b])
	parent[b]=a;
else
	{
	parent[a]=b;
	if(rank[a]==rank[b])
		rank[b]+=1;
	}
}

int find1(int a)
{
if(a!=parent[a])
	parent[a]=find1(parent[a]);
return parent[a];
}

void union1(int a,int b)
{
link1(find1(a),find1(b));
return;
}

int main()
{
int t;
cin>>t;
while(t--)
	{
	int r,c;
	cin>>r>>c;
	int i,a,b,dist;
	vector < pair <int,  pair <int,int>  > > vect;
	int sum=0;
	for(i=0;i<c;i++)
		{
		cin>>a>>b>>dist;
		sum+=dist;
		pair <int,int> temp;
		temp.first=a;
		temp.second=b;
		vect.push_back(make_pair(dist,temp));
		}
	sort( vect.begin(),vect.end() );
	for(i=0;i<r;i++)
		{
		parent[i]=i;
		rank[i]=0;
		}
	int ans=0;
	for(i=0;i<vect.size();i++)
		{
		a=vect[i].second.first;
		b=vect[i].second.second;
		if(find1(a)!=find1(b))
			{
			ans+=vect[i].first;
			union1(a,b);
			}
		}
	cout<<sum-ans<<endl;
	}
}
