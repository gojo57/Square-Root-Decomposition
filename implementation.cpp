#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ones(x) __builtin_popcountll(x)
#define int long long
#define pii pair<int,int>
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
using namespace std;
const int mod = 1e9+7;
const int N = 2e5+5;

// Range Sum Query
int query(int *blocks, int *a, int l, int r, int rn){
    int ans = 0;
    // Left Part
    while(l<r && l!=0 && l%rn!=0){
        ans += a[l];
        l++;
    }
    // Middle Part
    while(l+rn <= r){
        int block_id = l/rn;
        ans += blocks[block_id];
        l += rn;
    }
    // Right Part
    while(l<=r){
        ans += a[l];
        l++;
    }
    return ans;
}

// Update
void update(int *blocks, int *a, int i, int val, int rn){
    int block_id = i/rn;
    blocks[block_id] += (val - a[i]);
    a[i] = val;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[] = {1,3,5,2,7,6,3,1,4,8};
    int n = sizeof(a)/sizeof(a[0]);
    int rn = sqrt(n);
    int blocks[rn+1] = {0};

    // Build blocks array
    int block_id = -1;
    for(int i = 0; i < n; i++){
        if(i%rn == 0)
            block_id++;
        blocks[block_id] += a[i];
    }

    // Updates and Queries
    update(blocks, a, 2, 15, rn);
    cout<<query(blocks, a, 2, 8, rn)<<"\n";

    return 0;
}
