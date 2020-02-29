#include<bits/stdc++.h>

using namespace std;

int main()
{
    int item,Capasity;
    cout << "Enter the number of items : \t";
    cin>>item;
    cout << "Enter Capasity : \t";
    cin>>Capasity;
    int weight[item],value[item];
    double rat[item];
    for(int i=0;i<item;i++)
    {
        cout << "Enter item " << i+1 << " Weight and Value : \t";
        cin>> weight[i] >> value[i];
        rat[i]=(value[i]*1.0)/weight[i];
    }
    for(int i=0;i<item;i++)
    {
        for(int j=i+1;j<item;j++)
        {
            if(rat[i]<rat[j])
            {
                swap(rat[i],rat[j]);
                swap(weight[i],weight[j]);
                swap(value[i],value[j]);
            }
        }
    }
    int curWeight=0;
    double totalValue=0.0;
    for(int i=0;i<item;i++)
    {
        if(curWeight+weight[i]<=Capasity)
        {
            curWeight += weight[i];
            totalValue += value[i];
        }
        else
        {
            double remain = Capasity - curWeight;
            totalValue += value[i]*((remain*1.0)/weight[i]);
            break;
        }
    }
    cout << totalValue << "\n";
    return 0;
}
