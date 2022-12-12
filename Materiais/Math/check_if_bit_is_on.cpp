#define msb(n) (32 - __builtin_clz(n))
// #define msb(n) (64 - __builtin_clzll(n) )

bool bit_on(int n) {
    for (int i = 0; i < 32; i++) {
        if(1 & (n >> i)) return true;
        else return false;
    }
}