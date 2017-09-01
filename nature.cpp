#include <bits/stdc++.h>
using namespace std;

void DFS(int v,int arr[], vector <int> vect[],int *count)
{
arr[v]=1;
*count+=1;
int i;
for(i=0;i<vect[v].size();i++)
	{
	if(arr[vect[v][i]]==0)
		DFS(vect[v][i],arr,vect,count);
	}
return;
}

int find(vector <int> vect[],int r)
{
int arr[r],i;
for(i=0;i<r;i++)
    arr[i]=0;
int j,maxi=0,count;
for(i=0;i<r;i++)
	{
	if(arr[i]==0)
		{
		count=0;
		DFS(i,arr,vect,&count);
		if(count>maxi)
			maxi=count;
		}
	}
return maxi;
}

int main()
{
int r,c;
while(1)
	{
	cin>>r>>c;
	if(r==0&&c==0)
		break;
	map <string,int> mp;
	string s,t;
	int i,j;
	for(i=0;i<r;i++)
		{
		cin>>s;
		mp[s]=i;
		}
	vector <int> vect[r];
	for(i=0;i<c;i++)
		{
		cin>>s>>t;
		vect[mp[t]].push_back(mp[s]);
		vect[mp[s]].push_back(mp[t]);
		}
	int count=find(vect,r);
	cout<<count<<endl;
	}
}
