#include <bits/stdc++.h>
using namespace std;

int main()
{
int r,c,xx=0;
while(1)
	{
	xx++;
	cin>>r>>c;
	if(r==0&&c==0)
		break;
	map <string,int> mp;
	string s,t;
	int i,j,count=0,dist,k;
	int arr[r][r];
	for(i=0;i<r;i++)
		{
		for(j=0;j<r;j++)
			arr[i][j]=0;
		}
	for(i=0;i<c;i++)
		{
		cin>>s>>t>>dist;
		if(mp.find(s)==mp.end())
			{
			mp[s]=count;
			count++;
			}
		if(mp.find(t)==mp.end())
			{
			mp[t]=count;
			count++;
			}
		arr[mp[s]][mp[t]]=dist;
		arr[mp[t]][mp[s]]=dist;
		}
	for(k=0;k<r;k++)
		{
		for(i=0;i<r;i++)
			{
			for(j=0;j<r;j++)
				arr[i][j]=max(arr[i][j],min(arr[i][k],arr[k][j]));
			}
		}
	cin>>s>>t;
	cout<<"Scenario #"<<xx<<endl;
	cout<<arr[mp[s]][mp[t]]<<" "<<"tons"<<endl<<endl;
	}
}
