#include<cstdio>
#include"io.h"
#include"query.h"
Input I;
Output o1,o2,o3;
u64 n,i,u,a[32],cnt;
int id(u64 k){
	if(k>=(1<<16))return 16+id(k>>16);
	if(k>=(1<<8))return 8+id(k>>8);
	if(k>=(1<<4))return 4+id(k>>4);
	if(k>=(1<<2))return 2+id(k>>2);
	if(k==2)return 1;
	return 0;
}
int main(){
	I.Open("binary");
	n=I.get8();
	if(n!=(I.s-8)/8)return n;
	o1.Open("lowbyte");
	o2.Open("highbyte");
	o3.Open("number");
	o1.put8(n);
	o2.put8(0);
	o3.put8(n);
	for(i=1;i<=n;++i){
		u=I.get4();
		a[id(lb(i))]=u;
		if(i!=lb(i))u-=a[id(lb(i-lb(i)))];
		o1.put(u&255);
		if(u>=256){
			++cnt;
			o2.put4(i);
			o2.put3(u>>8);
		}
		o3.put4(I.get4());
	}
	o2.setpos(0);
	o2.put8(cnt);
	o1.Close();
	o2.Close();
	o3.Close();
	printf("%llu",cnt);
	return 0;
}
