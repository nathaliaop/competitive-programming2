map<ll, ll> expo;

void primeFactors(ll n) {
    while (n % 2 == 0) {
        expo[2]++;
        n = n/2;
    }
 
    for (ll i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            expo[i]++;
            n = n/i;
        }
    }
 
    if (n > 2) expo[n]++;
}