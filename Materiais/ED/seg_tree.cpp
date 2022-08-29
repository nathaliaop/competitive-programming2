class SegTree{
    vector<int> seg;
    vector<int> v;
    int size;
    int el_neutro = INT_MAX;
    
    int f(int a, int b){
        return min(a,b);
    }

    void update(int pos, int ini, int fim, int i, int val){
        if(i < ini or i > fim) return;
        if(ini == fim){
            seg[pos] = val; return;
        }

        int m = (ini+fim)/2;
        int e = 2*pos, d = 2*pos+1;
        update(e, ini, m, i, val);
        update(d, m+1, fim, i, val);

        seg[pos] = f(seg[e], seg[d]);
    }

    int query(int pos, int ini, int fim, int p, int q){
        if(q < ini or p > fim) return el_neutro; 
        if(p <= ini and fim <= q) return seg[pos]; 

        int m = (ini + fim)/2;
        int e = 2*pos, d = 2*pos+1;
        return f(query(e,ini,m,p,q), query(d,m+1,fim,p,q));
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

        void update(int i, int val){ return update(1,1,size,i,val); }

        int query(int p, int q){ return query(1,1,size,p,q); }

        void build(){ return build(1,1,size); }
};