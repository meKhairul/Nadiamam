#include<bits/stdc++.h>

using namespace std;

int main()
{
    int value,s,coinCount[1000]={0};
    cout << "Enter the amount : \t";
    cin>>value;
    s=value;
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    for(int i=8;i>=0;i--)
    {
        if(arr[i]<=s)
        {
            coinCount[arr[i]] = s/arr[i];
            cout << arr[i] << " is " << coinCount[arr[i]] << " times\n";
            s-=(coinCount[arr[i]]*arr[i]);
        }
        if(s==0)
        {
            break;
        }
    }
    return 0;

}
