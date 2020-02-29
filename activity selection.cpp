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
        for(int l=k+1;l<n;l++)
        {
            if(f[k]>f[l])
            {
                swap(f[k],f[l]);
                swap(s[k],s[l]);
            }
        }
    }
    int counter = 1,k=0;
    cout << counter <<"---Start time :" << s[0] << " Finish time :" << f[0] << "\n";
    for(int j = 1;j<n;j++)
    {
        if(s[j]>=f[k])
        {

            k=j;
            counter++;
            cout << counter << "---Start time :" << s[j] << " Finish time :" << f[j] << "\n";
        }
    }
}
