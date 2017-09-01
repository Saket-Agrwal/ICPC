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
int n;
cin>>n;
float x[n],y[n];
int i;
for(i=0;i<n;i++)
	cin>>x[i]>>y[i];
int j;
vector < pair <float,  pair <int,int>  > > vect;
float dist;
for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
		{
		if(i==j)
			continue;
		dist=sqrt(     (x[i]-x[j])*(x[i]-x[j])  +    (y[i]-y[j])*(y[i]-y[j])      );
		pair <int,int> temp;
		temp.first=i;
		temp.second=j;
		vect.push_back(make_pair(dist,temp));
		}
	}
sort( vect.begin(),vect.end() );
for(i=0;i<n;i++)
	{
	parent[i]=i;
	rank[i]=0;
	}
int a,b;
float ans=0;
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
std::cout << std::fixed;
std::cout << std::setprecision(2);
cout <<ans << endl;
}
