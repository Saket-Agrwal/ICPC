#include <bits/stdc++.h>
using namespace std;

int parent[100000],rank1[100000];

void link1(int a,int b)
{
if(rank1[a]>rank1[b])
	parent[b]=a;
else
	{
	parent[a]=b;
	if(rank1[a]==rank1[b])
		rank1[b]+=1;
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
int x=1;
while(t--)
	{
	int r,c,a1;
	cin>>r>>c>>a1;
	int i,a,b,dist;
	vector < pair <int,  pair <int,int>  > > vect;
	for(i=0;i<c;i++)
		{
		cin>>a>>b>>dist;
		pair <int,int> temp;
		temp.first=a-1;
		temp.second=b-1;
		if(dist<a1)
            vect.push_back(make_pair(dist,temp));
		}
	sort( vect.begin(),vect.end() );
	for(i=0;i<r;i++)
		{
		parent[i]=i;
		rank1[i]=0;
		}
	int ans=0,e=0;
	for(i=0;i<vect.size();i++)
		{
		a=vect[i].second.first;
		b=vect[i].second.second;
		if(find1(a)!=find1(b))
			{
            e++;
			ans+=vect[i].first;
			union1(a,b);
			}
		}
    ans=a1*(r-e)+ans;
    e=r-e;
    printf("Case #%d: %d %d\n", x++ , ans, e);
	}
}
