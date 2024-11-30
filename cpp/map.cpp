#include<cstdio>
#include"io.h"
Input I;
int i;
u64 n,a,b,cc[20005],cd[20005];
int main(){
	I.Open((char*)"lib");
	n=(I.s-8)/10;
	I.get8();
	while(n--){
		a=I.get5();
		b=I.get5();
		++cc[b/1000000];
	}
	I.Close();
	freopen("map.txt","w",stdout);
	for(i=0;i<20000;++i)if(cc[i])printf("%d ",i);
	puts("0");
	for(i=1;i<=20000;++i)cd[i]=cc[i-1]+cd[i-1];
	for(i=13000;i<=20000;++i)printf("%d %llu\n",i,cd[i]);
	return 0;
}
