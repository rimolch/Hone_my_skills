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
   printBinary(a&(~(1<<3)));
  /*
     wanting 4rth(from index 0) bit unset(unset means 0) 
     ~(tilda) it acts as binary compliment(reverse)
   */
    return 0;
}
