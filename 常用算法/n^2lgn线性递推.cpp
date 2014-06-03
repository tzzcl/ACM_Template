using namespace std;
typedef long long LL;
#define N 405
LL n , Q = 1e9 + 7 ;
int m , a[N] , K , b[N] , M;
int d[N] , c[N];
struct poly {
    int a[N];
    poly() {
        memset(a , 0 , sizeof(a));
    }
    int& operator [] (int x) {
        return a[x];
    }
}f[N];
inline void add(int& A , int B) {
    A += B;
    if (A >= Q)
        A -= Q;
}
poly operator * (poly x , poly y) {
    int i , j; poly ans;
    for (i = 0 ; i < M ; ++ i)
        for (j = 0 ; j < M ; ++ j)
            add(ans[i + j] , (LL)x[i] * y[j] % Q);
    for (i = M ; i < M + M - 1 ; ++ i)
        for (j = 0 ; j < M ; ++ j)
            add(ans[j] , (LL)ans[i] * f[i][j] % Q);
    return ans;
}

poly cal(LL k)
{
    if (k < M + M - 1)
        return f[k];
    poly tmp = cal(k >> 1);
    if (k & 1)
        return tmp * tmp * f[1];
    else
        return tmp * tmp;
}

void work()
{
    int i , j;
    memset(c , 0 , sizeof(c));
    memset(d , 0 , sizeof(d));
    memset(f , 0 , sizeof(f));
    /*  c Ϊת�ƹ�ϵ
        d Ϊ��ֵ �� M Ϊ����
        �������������Fibonacci������ */
    M = 2;
    d[0] = 1 , d[1] = 1;
    c[1] = 1 , c[2] = 1;

    for (i = 0 ; i < M ; ++ i) f[i][i] = 1;
    for (i = 1 ; i <= M ; ++ i)
        f[M][M - i] = c[i];
    for (i = M + 1 ; i < M + M - 1 ; ++ i) { //��poly^i ��Գ�������Ա�ʾ
        for (j = 0 ; j < M ; ++ j) {
            if (j) f[i][j] = f[i - 1][j - 1];
            add(f[i][j] , (LL)f[M][j] * f[i - 1][M - 1] % Q);
        }
    }
    poly ans = cal(n);
    int res = 0;
    for (i = 0 ; i < M ; ++ i)
        add(res , (LL)d[i] * ans[i] % Q);
    printf("%d\n" , res);
}