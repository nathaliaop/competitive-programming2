#define lcm(a,b) (a*b)/gcd(a,b)

int gcd(int a, int b) {
 if (b == 0) return a;
 return gcd(b, a % b);
}

// number of elements
long long sum_of_n_first_squares(int n) {
 return (n * (n - 1) * (2 * n - 1)) / 6;
}

// first element, last element, number of elements
long long sum_pa(int a1, int an, int n) {
 return ((a1 + an) * n) / 2;
}

// first element, number of elements, ratio
long long general_term_pa(int a1, int n, int r) {
 return a1 + (n - 1) * r;
}

// first term, numbers of elements, ratio
long long sum_pg(int a1, int n, int q) {
 return (a1 * (fexp(q, n) - 1)) / (q - 1);
}

// -1 < q < 1
// first term, ratio
long long sum_infinite_pg(int a1, double q) {
 return a1 * (1 - q);
}

// first term, number of elements, ratio
long long general_term_pg(int a1, int n, int q) {
 return a1 * fexp(q, n -1);
}

// first element of original pa, first element of derived pa, number of elements of original pa, ratio of derived pa
long long sum_second_order_pa(int a1, int b1, int n, int r) {
 return a1 * n + (b1 * n * (n - 1)) / 2 + (r * n * (n - 1) * (n - 2)) / 6
}