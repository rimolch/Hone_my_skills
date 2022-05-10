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
    int c=0;
    for(int i=31;i>=0;i--)//using 32 bit
    {
        if((a&(1<<i))!=0)
        {
            c++;
        }
    }
    printBinary(a);
    cout<<c<<endl;
    return 0;
}
//2nd method using __builtin_popcount() 
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
    int c=0;
    printBinary(a);
    cout<<__builtin_popcount(a)<<endl;
    return 0;
}
