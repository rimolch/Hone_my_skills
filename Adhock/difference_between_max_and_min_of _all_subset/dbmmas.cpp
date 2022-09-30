#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>ar(n);
	for(int i=0;i<n;i++){
		cin>>ar[i];
	}
	sort(ar.begin(),ar.end());
	int fixed1=1,maxi=0,mini=0;
	//for maximum
	for(int i=0;i<n;i++){
		maxi+=ar[i]*fixed1;
		fixed1*=2;
	}
	//for minimum
	int fixed2=1;
	for(int i=n-1;i>=0;i--){
		mini+=ar[i]*fixed2;
		fixed2*=2;
	}
	cout<<maxi-mini<<endl;
	return 0;
}
