#include <bits/stdc++.h>
using namespace std;

class SegTree{
    vector<int> seg;
    vector<int> v;
    int size;
    int el_neutro = INT_MAX;
    
    int f(int a, int b){
        return min(a,b);
    }

    void update_range(int pos, int ini, int fim, int l, int r, int val){
        if(r < ini or l > fim) return;
        if(l <= ini and fim <= r){
            seg[pos] += val;
        } 

        int mid = (ini+fim)/2;

        update_range(2*pos, ini, mid, l, r, val);
        update_range(2*pos+1, mid+1, fim, l, r, val);
    } 

    int query_point(int pos, int ini, int fim, int i){
        if(ini == fim) return seg[pos];

        int mid = (ini + fim)/2;
        if(i<=mid)
            return query_point(2*pos, ini, mid, i);
        else
            return query_point(2*pos+1, mid+1, fim, i);
    }

    void build(int pos, int ini, int fim){
        if(ini == fim){
            seg[pos] = v[ini]; return;
        }

        int m = (ini+fim)/2;
        int e = 2*pos, d=2*pos+1;
        
        build(e,ini,m);
        build(d,m+1,fim);
        
        seg[pos] = f(seg[e], seg[d]);
    }

public:
    SegTree(int n, vector<int> source): seg(4*size), v(size){
        size = n;
        for(int i=0; i<size; i++) v[i] = source[i];
    }

    void update(int l, int r, int val){ return update_range(1,1,size,l, r,val); }

    int query(int i){ return query_point(1,1,size,i); }

    void build(){ return build(1,1,size); }
};