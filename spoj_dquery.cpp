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

struct query{
    int l, r, idx, bno;
};

int freq[1000001] = {0};
int distinct = 0;

void add(int x){
    if(freq[x] == 0)
        distinct++;
    freq[x]++;
}

void remove(int x){
    freq[x]--;
    if(freq[x] == 0)
        distinct--;
}

void adjust(int &currL, int &currR, query q, int *a){
    while(currL < q.l){
        remove(a[currL]);
        currL++;
    }
    while(currL > q.l){
        currL--;
        add(a[currL]);
    }
    while(currR < q.r){
        currR++;
        add(a[currR]);
    }
    while(currR > q.r){
        remove(a[currR]);
        currR--;
    } 
}

bool cmp(query q1, query q2){
    if(q1.bno < q2.bno)
        return 1;
    else if(q1.bno > q2.bno)
        return 0;
    else
        return q1.r < q2.r;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> q;
    vector<query> queries(q);
    for(int i = 0; i < q; i++){
        cin >> queries[i].l >> queries[i].r;
        queries[i].bno = queries[i].l/sqrt(n);
        queries[i].l--;
        queries[i].r--;
        queries[i].idx = i;
    }
    vi ans(q);
    sort(all(queries), cmp);
    for(int l = queries[0].l; l <= queries[0].r; l++){
        add(a[l]);
    }
    ans[queries[0].idx] = distinct;
    int currL = queries[0].l, currR = queries[0].r;
    for(int i = 1; i<q; i++){
        adjust(currL, currR, queries[i], a);
        ans[queries[i].idx] = distinct;
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return 0;
}