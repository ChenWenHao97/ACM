#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
template<class Type>
void knapsack(vector<Type> v,vector<Type> w,int c,int n,vector<vector<Type> > m)
{
    int minweight = min(w[n]-1,c);
    cout << "min:"<<minweight<<endl;
    for(int j = 0;j <minweight;j++)
        m[n][j] = 0;
    for(int j = w[n];j <= c;j++)
        m[n][j] = v[n];
    for(int i = n-1;i > 1;i--)
    {
        minweight = min(w[i],c);
        cout << "max:"<<minweight<<endl;
        for(int j = 0;j <= minweight;j++)
            m[i][j] = m[i+1][j];
        for(int j = w[i];j <= c;j++)
            m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
    }
    m[1][c] = m[2][c];
    if(c >= w[1])
        m[1][c] = max(m[1][c],m[2][c-w[1]]+v[1]);
}
template<class Type>
void traceback(vector<vector<Type> > m,vector<int> w,int c,int n,vector<int> x)
{
    for(int i = 1;i < n;i++)
    {
        if(m[i][c]==m[i+1][c])
            x[i] = 0;
        else
        {
            x[i] = 1;
            c -= w[i];
        }
    }
    x[n] = (m[n][c])?1:0;
}
template<class Type>
void print(vector<Type> x,int n)
{
    for(int i = 1;i <=n;i++)
        if(x[i] != 0)
            cout << i <<" ";
}

int main()
{
    vector<int> x(100);
    vector< vector<int> > m(100,vector<int>(100));//创建二维的vector
    vector<int> w(100);
    vector<int> v(100);
    cout <<"请输入物品个数:";
    int n;
    cin >>n;
    cout <<"请输入能装下的重量:";
    int c;
    cin >> c;
    cout <<"请输入重量列表:";
    int weight;
    for(int i = 1;i <= n;i++)
    {
        cin >> weight;
        w[i] = weight;
    }
    cout <<"请输入价值列表:";
    int value;
    for(int i = 1;i <= n;i++)
    {
        cin >>value;
        v[i] = value;
    }
    knapsack(v,w,c,n,m);
    // for(int i = 1;i <= c;i++)
    //     for(int j = 1;j <= c;j++)
    //         cout <<m[i][j]<<" ";
    cout <<"m:"<<m[1][c]<<" ";
    traceback(m,w,c,n,x);
    // for(int i =1;i<=n;i++)
    //     cout <<x[i]<<" ";
    print(x,n);

    return 0;
}