#include <bits/stdc++.h>
using namespace std;

void DFS1(int v,int arr[], vector <int> vect[])
{
arr[v]=1;
int i;
for(i=0;i<vect[v].size();i++)
	{
	if(arr[vect[v][i]]==0)
		DFS1(vect[v][i],arr,vect);
	}
return;
}

stack <int> DFS(int v,int arr[], vector <int> vect[],stack <int> st)
{
arr[v]=1;
int i;
for(i=0;i<vect[v].size();i++)
	{
	if(arr[vect[v][i]]==0)
		st=DFS(vect[v][i],arr,vect,st);
	}
st.push(v);
return st;
}

int find(vector <int> vect[],int r)
{
int arr[r],i,j;
for(i=0;i<r;i++)
    arr[i]=0;
stack <int> st;
for(i=0;i<r;i++)
	{
	if(arr[i]==0)
		st=DFS(i,arr,vect,st);
	}
vector <int> vec[r];
for(i=0;i<r;i++)
	{
	for(j=0;j<vect[i].size();j++)
		vec[vect[i][j]].push_back(i);
	}
for(i=0;i<r;i++)
    arr[i]=0;
int count=0;
while(!st.empty())
	{
	if(arr[st.top()]==0)
		{
		DFS1(st.top(),arr,vec);
		count++;
		if(count>1)
			break;
		}
	else
		st.pop();
	}
if(count==1)
	return 1;
else
	return 0;
}

int main()
{
int r,c;
while(1)
	{
	cin>>r>>c;
	if(r==0&&c==0)
		break;
	vector <int> vect[r];
	int a,b,d,i;
	for(i=0;i<c;i++)
		{
		cin>>a>>b>>d;
		if(d==1)
			vect[a-1].push_back(b-1);
		else
			{
			vect[a-1].push_back(b-1);
			vect[b-1].push_back(a-1);
			}
		}
	int count=find(vect,r);
	cout<<count<<endl;
	}
}
