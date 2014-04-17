const double eps = 1e-10;//����0
inline int sign(double a) {//�жϷ���
	return a < -eps ? -1 : a > eps;
}
struct Point {//��Ķ���
	double x, y;
	Point() {
	}
	Point(double _x, double _y) :
			x(_x), y(_y) {
	}
	Point operator+(const Point&p) const {
		return Point(x + p.x, y + p.y);
	}
	Point operator-(const Point&p) const {
		return Point(x - p.x, y - p.y);
	}
	Point operator*(double d) const {
		return Point(x * d, y * d);
	}
	Point operator/(double d) const {
		return Point(x / d, y / d);
	}
	bool operator<(const Point&p) const {
		int c = sign(x - p.x);
		if (c)
			return c == -1;
		return sign(y - p.y) == -1;
	}
	double dot(const Point&p) const {//���
		return x * p.x + y * p.y;
	}
	double det(const Point&p) const {//���
		return x * p.y - y * p.x;
	}
	Point rotate_left(double ang) const {
        double c = cos(ang), s = sin(ang);
        return Point(x * c - y * s, y * c + x * s);
    }
    Point rotate_right(double ang) const {
        double c = cos(ang), s = sin(ang);
        return Point(x * c + y * s, y * c - x * s);
    }
    Point rotate_left() const {
        return Point(-y, x);
    }
    Point rotate_right() const {
        return Point(y, -x);
	}
	double alpha() const {//����X�����ɼн�
		return atan2(y, x);
	}
	double distTo(const Point&p) const {//�������
		double dx = x - p.x, dy = y - p.y;
		return hypot(dx, dy);
	}
	double alphaTo(const Point&p) const {//����㵽�����ɽ�
		double dx = x - p.x, dy = y - p.y;
		return atan2(dy, dx);
	}
	void read() {
		scanf("%lf%lf", &x, &y);
	}
	double abs() {//��㵽ԭ�����
		return hypot(x, y);
	}
	double abs2() {//��㵽ԭ�����ƽ��
		return x * x + y * y;
	}
	void write() {//���
		cout << "(" << x << "," << y << ")" << endl;
	}
};
struct Line{//�߶�(ֱ��)����
	Point s,e;
	double a,b,c;
	Line(){
		a=b=c=0;
	}
	Line(Point s,Point e){
		this->s=s;
		this->e=e;
		a=s.y-e.y;
		b=e.x-s.x;
		c=s.x*e.y-s.y*e.x;
	}
};
struct Circle{
	Point center;
	double r;
};
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y)) 
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))//�Ƿ��ཻ

typedef vector<Point> Poly;