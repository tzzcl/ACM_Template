inline double f(double x){//计算函数值
	return 1;
}
double Romberg(double a, double b) {//龙贝格积分，其中x为对应的须计算的函数值 MAX为迭代次数
	int MAX=10000;
    double  h = b - a, buf, y[4];            
    y[0] = h * (f(b) + f(a)) / 2.0;            
    int m = 1, n = 1,k;                        
    do {
        buf = 0.0;
        for (int i=0; i<n; i++)                
            buf += f(a + (i + 0.5) * h);
        buf = (y[0] + h * buf) / 2.0;        

        double tmp, s = 1.0;                
        for (k=1; k<=m && k<=3; k++) {
            s *= 4.0;
            tmp = (s * buf - y[k-1]) / (s - 1.0);
            y[k-1] = buf;                    
            buf = tmp;
        }
        buf = (k == 4) ? fabs(tmp - y[k-1]) : eps+1;
        y[k-1] = tmp;                       
        n *= 2;    h /= 2;    
    } while ((m++ <= MAX) && (buf > eps));  
    return y[0];
}