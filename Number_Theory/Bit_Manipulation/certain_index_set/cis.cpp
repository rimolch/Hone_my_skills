#include<bits/stdc++.h>
using namespace std;
void printBinary(int n)
{
    for(int i=10;i>=0;i--)
    {
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
int main()
{
   int a=9;
   printBinary(a);
   printBinary(a|(1<<1));// wanting 2nd(from index 0) bit set(set means 1)
    return 0;
}
