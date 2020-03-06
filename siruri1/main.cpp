#include <iostream>
using namespace std;

void citire(int X[], int &n)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>X[i];
}
void tiparire(int Y[],int m)
{
    for(int i=1;i<=m;i++)
        cout<<Y[i]<<' ';
}
bool NrPrim(int a)
{
    if(a<=1) return false;
    if(a==2||a==3)
        return true;
    int d=2;
    while(d*d<=a&&a%d!=0)
        d++;
    if(d*d>a)
        return true;
    return false;
}
bool putere(int a, int b)
{
    int p=0;
    while(a%b==0)
        p++;
    if(p==1) return true;
    return false;
}
void construire(int X[],int n,int Y[],int &m)
{
    for(int i=1;i<=n;i++)
    {
        int d=2;
        while(d<X[i])
        if(NrPrim(d))
            if(putere(X[i],d)) Y[++m]=d;
    }
}
int main()
{
    int n,X[500],Y[2500],m=0;
    citire(X,n);
    construire(X,n,Y,m);
    if(m==0) cout<<"Sirul Y este vid";
    else tiparire(Y,m);
    return 0;
}
