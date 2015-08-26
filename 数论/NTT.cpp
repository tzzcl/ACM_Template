using namespace std;
typedef long long LL;

const int N = 1 << 18; //N一定是P-1的约数
const int P = (479 << 21) + 1;//P为NTT的模数
const int G = 3;//原根，通过原根计算得出
const int NUM = 20;//开n次根下值

LL  wn[NUM];
LL  a[N], b[N];
char A[N], B[N];

LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

void GetWn()
{
    for(int i=0; i<NUM; i++)
    {
        int t = 1 << i;
        wn[i] = quick_mod(G, (P - 1) / t, P);
    }
}

void Prepare(char A[], char B[], LL a[], LL b[], int &len)
{
    len = 1;
    int len_A = strlen(A);
    int len_B = strlen(B);
    while(len <= 2 * len_A || len <= 2 * len_B) len <<= 1;
    for(int i=0; i<len_A; i++)
        A[len - 1 - i] = A[len_A - 1 - i];
    for(int i=0; i<len - len_A; i++)
        A[i] = '0';
    for(int i=0; i<len_B; i++)
        B[len - 1 - i] = B[len_B - 1 - i];
    for(int i=0; i<len - len_B; i++)
        B[i] = '0';
    for(int i=0; i<len; i++)
        a[len - 1 - i] = A[i] - '0';
    for(int i=0; i<len; i++)
        b[len - 1 - i] = B[i] - '0';
}

void Rader(LL a[], int len)
{
    int j = len >> 1;
    for(int i=1; i<len-1; i++)
    {
        if(i < j) swap(a[i], a[j]);
        int k = len >> 1;
        while(j >= k)
        {
            j -= k;
            k >>= 1;
        }
        if(j < k) j += k;
    }
}

void NTT(LL a[], int len, int on)
{
    Rader(a, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1)
    {
        id++;
        for(int j = 0; j < len; j += h)
        {
            LL w = 1;
            for(int k = j; k < j + h / 2; k++)
            {
                LL u = a[k] % P;
                LL t = w * (a[k + h / 2] % P) % P;
                a[k] = (u + t) % P;
                a[k + h / 2] = ((u - t) % P + P) % P;
                w = w * wn[id] % P;
            }
        }
    }
    if(on == -1)
    {
        for(int i = 1; i < len / 2; i++)
            swap(a[i], a[len - i]);
        LL Inv = quick_mod(len, P - 2, P);
        for(int i = 0; i < len; i++)
            a[i] = a[i] % P * Inv % P;
    }
}

void Conv(LL a[], LL b[], int n)
{
    NTT(a, n, 1);
    NTT(b, n, 1);
    for(int i = 0; i < n; i++)
        a[i] = a[i] * b[i] % P;
    NTT(a, n, -1);
}