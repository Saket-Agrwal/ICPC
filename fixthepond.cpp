#include <bits/stdc++.h>
using namespace std;

bool check(int a,int b,string s[],int n,int ori)
{
if(a<1||a>2*n-1||b<1||b>2*n)
	return true;
else
	{
	if(a%2)
		{
		if(b%2)
			{
            if(ori==0&&s[a-1][(b-1)/2]=='H'||ori==1&&s[a-1][(b-1)/2]=='V')
                return false;
            else
                return true;
			}
		else
			return true;
		}
	else
		{
		if(b%2)
			return true;
		else
			{
            if(ori==0&&s[a-1][b/2-1]=='H'||ori==1&&s[a-1][b/2-1]=='V')
                return false;
            else
                return true;
			}
		}
	}
}

void DFS(int i,int j,vector <int> vect[],string s[],int n)
{
if(i<0||j<0||i>=2*n||j>2*n)
	return;
if(vect[i][j]==1)
	return;
vect[i][j]=1;
if(check(i,j,s,n,0)&&check(i,j+1,s,n,0))
    DFS(i-1,j,vect,s,n);
if(check(i+1,j+1,s,n,1)&&check(i,j+1,s,n,1))
    DFS(i,j+1,vect,s,n);
if(check(i+1,j,s,n,0)&&check(i+1,j+1,s,n,0))
    DFS(i+1,j,vect,s,n);
if(check(i,j,s,n,1)&&check(i+1,j,s,n,1))
    DFS(i,j-1,vect,s,n);
}

int main()
{
int t;
cin>>t;
while(t--)
	{
	int n;
	cin>>n;
	string s[2*n-1];
	int i;
	for(i=0;i<2*n-1;i++)
		cin>>s[i];
	vector <int> vect[2*n];
	int j;
	for(i=0;i<2*n;i++)
		{
		for(j=0;j<=2*n;j++)
			vect[i].push_back(0);
		}
	int count=0;
	for(i=0;i<2*n;i++)
		{
		for(j=0;j<=2*n;j++)
			{
			if(vect[i][j]==0)
				{
				DFS(i,j,vect,s,n);
				cout<<endl;
				count++;
				}
			}
		}
	cout<<count-1<<endl;
	}
}
