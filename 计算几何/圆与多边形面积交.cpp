double area2(Point pa,Point pb,Circle& Ci){//三角剖分
	//cout<<pb.x<<' '<<pb.y<<endl;
	if (pa.abs()<pb.abs()) swap(pa,pb);
	if (pb.abs()<eps) return 0;
	double a,b,c,B,C,sinB,cosB,sinC,cosC,S,h,theta;
	S=0;
	a=pb.abs();b=pa.abs();c=(pb-pa).abs();
	cosB=(pb.dot(pb-pa))/a/c;
	B=acos(cosB);
	cosC=(pa.dot(pb))/a/b;
	C=acos(cosC);
	if (a>Ci.r){
		S=(C/2)*Ci.r*Ci.r;
		h=a*b*sin(C)/c;
		if (h<Ci.r&&B<pi/2) S-=(acos(h/Ci.r)*Ci.r*Ci.r-h*sqrt(Ci.r*Ci.r-h*h));
	}
		else if (b>Ci.r){
			theta=pi-B-asin(sin(B)/Ci.r*a);
			S=0.5*a*Ci.r*sin(theta)+(C-theta)/2*Ci.r*Ci.r;
		}
		else S=0.5*sin(C)*a*b;
	return S;
}
double crossarea(Poly a,Circle& c,int total){//求多边形与圆的面积交 //注意total为点总数，a[n]=a[0]
	double S=0;
	for (int i=0;i<total-1;i++)
		S+=area2(a[i],a[i+1],c)*sign((a[i].det(a[i+1])));
	return fabs(S);
}