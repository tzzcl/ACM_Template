#define MAXN 55 //矩阵维数
typedef long long LL;//元素类型
typedef  LL Type;
Type buffer[MAXN][MAXN];
const int mod = 998244353;//模数
struct Matrix{
    Type x[MAXN][MAXN];
    int n;
    Matrix(){this->n=0;}
    Matrix(int n){this->n = n;}
    void mul(Matrix &m){
        double tot = 0;
        tot = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                buffer[i][j] = 0;
                for(int k = 0;k<n;k++){
                    buffer[i][j]=(buffer[i][j]+x[i][k]*m.x[k][j])%mod;
                }
            }
        }
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++) x[i][j] = buffer[i][j];
    }
    
    void print(){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++) cout<<x[i][j]<<" ";
            cout<<endl;
        }
    }
    
    void init(){
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++) x[i][j] = 0;
        for(int i = 0;i<n;i++) x[i][i] = 1;
    }
    Matrix Pow(Matrix &x,LL p){ //矩阵快速幂，p为指数，注意矩阵x会变化，不能重用
        Matrix m(x.n);
        m.init();
        while(p){
            if(p&1){
                m.mul(x);
            }
            x.mul(x);
            p>>=1;
        }
        return m;
    }
};
