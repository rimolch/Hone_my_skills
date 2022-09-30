#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int ar[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>ar[i][j];
		}
	}
	int pref[n][m];
	pref[0][0]=ar[0][0];
	for(int i=1;i<m;i++){
		pref[0][i]=pref[0][i-1]+ar[0][i];
	}
	for(int i=1;i<n;i++){
		pref[i][0]=pref[i-1][0]+ar[i][0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			pref[i][j]=pref[i][j-1]+pref[i-1][j]+ar[i][j]-pref[i-1][j-1];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<pref[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
