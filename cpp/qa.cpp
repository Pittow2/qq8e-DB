#include<cstdio>
#include"io.h"
#include"query.h"
Input I0,I1,I2;
u64 n,m,a,b;
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
	init();
	printf("Successsfully load %llu keys\n",n);
	freopen("CON","r",stdin);
	while(1)scanf("%llu",&a),query();
	return 0;
}
