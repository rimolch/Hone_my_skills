include<bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
	// your code goes here
    int n;
    cin>>n;
    int ar[n+1];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int diff[n+1]={0};
    int q;
    cin>>q;
    while(q--){
        int l,r,v;
        cin>>l>>r>>v;
        diff[l]+=v;
        diff[r+1]-=v;
    }
    for(int i=1;i<n;i++){
        diff[i]+=diff[i-1];
    }
    for(int i=0;i<n;i++){
        ar[i]+=diff[i];
    }
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
	return 0;
}
