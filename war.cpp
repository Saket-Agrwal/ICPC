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
int n;
cin>>n;
set <int> st[n];
int i;
for(i=0;i<n;i++)
	{
	parent[i]=i;
	rank1[i]=0;
	}
while(1)
	{
	int a,b,c,x,y;
	cin>>a>>b>>c;
	if(a==0)
		break;
	if(a==1)
		{
        x=find1(b);
        y=find1(c);
		if(st[x].find(y)==st[b].end())
			union1(x,y);
		else
			cout<<"-1"<<endl;
		}
	if(a==2)
		{
        x=find1(b);
        y=find1(c);
		if(x==y)
			cout<<"-1"<<endl;
		else
			{
			st[x].insert(y);
			st[y].insert(x);
			}
		}
	if(a==3)
		{
		if(find1(b)==find1(c))
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
		}
	if(a==4)
		{
		x=find1(b);
        y=find1(c);
		if(st[x].find(y)!=st[b].end())
			cout<<"1"<<endl;
		else
			cout<<"0"<<endl;
		}
	}
}
