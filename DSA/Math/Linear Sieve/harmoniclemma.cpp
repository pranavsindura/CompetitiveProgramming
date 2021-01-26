// d(i) = int div (n/i)
// distinct i
// O(sqrt(n))
int st[2 * int(sqrt(n)) + 1], k = 0;
for (int i = 1, x; i <= n; i = x + 1)
{
    x = n / (n / i);
    st[k] = n / i;
    k++;
}