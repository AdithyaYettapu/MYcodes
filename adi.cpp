#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    long long n,k;
    cin >> n;

    vector<long long> size;

    for (long long i = 0; i < n; ++i)
    {
        cin >> k;
        size.push_back(k);
    }

    sort(size.begin(), size.end());
    bool vis[n] = {0};

    long long j,l;

    j = upper_bound(size.begin(), size.end(), ((size[n-1])/2)) - size.begin();

    if(j != 0){
        vis[n-1] = 1;
        vis[j-1] = 1;
        l = j;
    }
    else{
        cout << n << endl;
        return 0;
    }

    j = n-2;

    for (long long i = l-2; i >= 0; i--)
    {
        if(vis[j]==1) break;
        if(size[j] >= (size[i]*2)){
            vis[j] = 1;
            vis[i] = 1;
            j--;
        }
    }

    long long count1 = 0;
    
    for (long long i = 0; i < n; ++i)
    {
        if(vis[i]){
            count1++;
        }
    }


    cout << n - (count1/2) << endl;

    return 0;
}