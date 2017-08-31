#include <bits/stdc++.h>
using namespace std;

int dfs(vector <int> vect[],int val[],int d[],int i,int sum)
{
d[i]=1;
sum+=val[i];
int j;
for(j=0;j<vect[i].size();j++)
	{
	if(d[vect[i][j]]==0)
		sum=dfs(vect,val,d,vect[i][j],sum);
	}
return sum;
}

bool find(vector <int> vect[],int val[],int n)
{
int d[n],i;
for(i=0;i<n;i++)
	d[i]=0;
for(i=0;i<n;i++)
	{
	if(d[i]==0)
		{
		int sum=dfs(vect,val,d,i,0);
		if(sum==0)
			continue;
		else
			return false;
		}
	}
return true;
}

int main()
{
int N;
cin>>N;
while(N--)
	{
	int n,m;
	cin>>n>>m;
	int val[n],i,x,y;
	for(i=0;i<n;i++)
		cin>>val[i];
	vector <int> vect[n];
	for(i=0;i<m;i++)
		{
		cin>>x>>y;
		vect[x].push_back(y);
		vect[y].push_back(x);
		}
	if(find(vect,val,n))
		cout<<"POSSIBLE"<<endl;
	else
		cout<<"IMPOSSIBLE"<<endl;
	}
}
