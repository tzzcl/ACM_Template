class fraction{
	BigInteger a,b;
	public fraction(){
		a=new BigInteger("0");
		b=new BigInteger("1");
	}
	fraction(BigInteger a1,BigInteger b1){
		this.a=a1;this.b=b1;
	}
	void reduction(){
	BigInteger temp=a.gcd(b);
	a=a.divide(temp);
	b=b.divide(temp);
	if (b.compareTo(BigInteger.ZERO)==-1){
		b=b.multiply(BigInteger.valueOf(-1));
		a=a.multiply(BigInteger.valueOf(-1));
	}
	}
	fraction add(fraction t){
		fraction temp=new fraction(a.multiply(t.b).add(b.multiply(t.a)),b.multiply(t.b));
		temp.reduction();
		return temp;
	}
	fraction sub(fraction t){
		fraction temp=new fraction(a.multiply(t.b).subtract(b.multiply(t.a)),b.multiply(t.b));
		temp.reduction();
		return temp;
	}
	fraction mult(fraction t){
		fraction temp=new fraction(a.multiply(t.a),b.multiply(t.b));
		temp.reduction();
		return temp;
	}
	fraction div(fraction t){
		fraction temp=new fraction(a.multiply(t.b),b.multiply(t.a));
		temp.reduction();
		return temp;
	}
	public void abs(){
		if (this.a.compareTo(BigInteger.ZERO)==-1){
			this.a=this.a.multiply(BigInteger.valueOf(-1));
		}
	}
	void out(){
		this.reduction();
		if (b.compareTo(BigInteger.ONE)==0)
			System.out.println(a);
		else 
			System.out.println(a+"/"+b);
	}
	boolean biger(fraction p){
		fraction temp=new fraction(a,b);
		fraction t=new fraction(p.a,p.b);
		temp.reduction();
		if (temp.a.compareTo(BigInteger.ZERO)==-1)
		{
			temp.a=temp.a.multiply(BigInteger.valueOf(-1));
		}
		if (t.a.compareTo(BigInteger.valueOf(-1))==-1){
			t.a=t.a.multiply(BigInteger.valueOf(-1));
		}
		temp=temp.sub(t);
		return temp.a.compareTo(BigInteger.ZERO)>-1;
	}
}
