#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    int s[n],f[n];
    for(i=0;i<n;i++)
    {
        cin>> s[i] >> f[i];
    }
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<n;l++)
        {
            if(f[k]>f[l])
            {
                int temp=f[l];
                f[l]=f[k];
                f[k]=temp;
                temp=s[l];
                s[l]=s[k];
                s[k]=temp;
            }
        }
    }
    int counter = 1,k=0;
    for(int j = k+1;j<n;j++)
    {
        if(s[j]>=f[k])
        {
            k=j;
            counter++;
        }
    }
    cout << counter << endl;
}
