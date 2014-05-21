struct Point3{//µã
	double x,y,z;
	Point3(){x=0,y=0,z=0;}
	Point3(double a,double b,double c){
		x=a,y=b,z=c;
	}
	void read(){
		scanf("%lf %lf %lf",&x,&y,&z);
	}
	double len(){
		return sqrt(sqr(x)+sqr(y)+sqr(z));
	}
	double Distto(const Point3 &b){
		return sqrt(sqr(b.x-x)+sqr(b.y-y)+sqr(b.z-z));
	}
	void write(){
		printf("%lf %lf %lf\n",x,y,z);
	}
	Point3 operator -(const Point3& b)const{
		return Point3(x-b.x,y-b.y,z-b.z);
	}
	Point3 operator +(const Point3& b)const{
		return Point3(x+b.x,y+b.y,z+b.z);
	};
	Point3 operator *(const double& d)const{
		return Point3(x*d,y*d,z*d);
	}
	Point3 operator /(const double& d)const{
		return Point3(x/d,y/d,z/d);
	}
	double operator *(const Point3& b)const{
		return x*b.x+y*b.y+z*b.z;
	}
	Point3 operator ^(const Point3& b)const{
		return Point3(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);
	}
};
struct Line3{//Ïß
	Point3 s,e;
};
struct Plane3{//Ãæ
	Point3 a,b,c;
};
