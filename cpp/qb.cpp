#include<cstdio>
#include"io.h"
#include"query.h"
Input I0,I1,I2,I3;
u64 n,m;
u64 Re(u64 p){
	u64 k=read(&I0,p-1+8,1);
	u64 l=~0,r=m,mid,w;
	while(l+1!=r){
		mid=(l+r)>>1;
		w=read(&I1,mid*7+8,4);
		if(w<p)l=mid;
		else if(w>p)r=mid;
		else return k+(read(&I1,mid*7+12,3)<<8);
	}
	return k;
}
u64 BITquery(u64 id){
	u64 p=0;
	while(id)p+=Re(id),id-=lb(id);
	return p;
}
void qb(u64 a){
	a=zip(a);
	u64 l=0,r=n,mid,b;
	while(l+1!=r){
		mid=(l+r)>>1;
		if(read(&I2,read(&I3,mid*4+8,4)*4+8,4)<=a)l=mid;
		else r=mid;
	}
	while(b=read(&I3,l*4+8,4),read(&I2,b*4+8,4)==a){
		printf("%llu\n",BITquery(b+1));
		++l;
		if(l==n)break;
	}
	puts("");
}
void qa(u64 a){
	u64 p=0,A=a,b;
	for(int i=32;~i;--i)if(p+(1ull<<i)<=n){
		b=Re(p+(1ull<<i));
		if(a>=b)a-=b,p+=1ull<<i;
	}
	if(a||!p)return;
	do printf("%llu\n",unzip(read(&I2,(p-1)*4+8,4)));
	while(--p&&BITquery(p)==A);
	puts("");
}
u64 read(){
	char c;
	while(c=getchar(),c<'0'||c>'9');
	u64 r=0;
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	return r;
}
int main(){
	int i=I0.Open("lowbyte",16);
	if(i)return i;
	n=I0.get8();
	if(I0.s-8!=n)return 8086;
	i=I1.Open("highbyte",16);
	if(i)return i;
	m=I1.get8();
	if(I1.s-8!=m*7)return 8087;
	i=I2.Open("number",16);
	if(i)return i;
	if(I2.get8()!=n||I2.s-8!=n*4)return 8088;
	i=I3.Open("reverse",16);
	if(i)return i;
	if(I3.get8()!=n||I3.s-8!=n*4)return 8089;
	init();
	printf("Successsfully load %llu keys\n",n);
	freopen("CON","r",stdin);
	u64 a,b;
	while(1){
		a=read();
		printf("query %llu:\n",a);
		qa(a);
		qb(a);
	}
	return 0;
}
