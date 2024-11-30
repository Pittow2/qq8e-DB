#include<cstdio>
#include"io.h"
Input I;
u64 n,i,u,a[32],cnt;
int id(u64 k){
	if(k>=(1<<16))return 16+id(k>>16);
	if(k>=(1<<8))return 8+id(k>>8);
	if(k>=(1<<4))return 4+id(k>>4);
	if(k>=(1<<2))return 2+id(k>>2);
	if(k==2)return 1;
	return 0;
}
int lb(int x){return x&(-x);}
int main(){
	I.Open("binary");
	n=I.get8();
	for(i=1;i<=n;++i){
		u=I.get4();
		a[id(lb(i))]=u;
		if(i!=lb(i))u-=a[id(lb(i-lb(i)))];
		if(u>=256)++cnt;
		I.get4();
	}
	printf("%llu",cnt);
	return 0;
}
