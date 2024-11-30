#include<stdio.h>
#include"io.h"
Input I;
Output O;
u64 i,k;
u64 read(){
	char c;
	u64 r=0;
	while(c=I.gc(),c<'0'||c>'9')if(I.flag)return 0;
	while(c>='0'&&c<='9'){
		(r*=10)+=c-'0';
		c=I.gc();
	}
	return r;
}
u64 ca[100086],cc;
int main(){
	I.Open((char*)"6.9.txt");
	O.Open((char*)"lib");
	freopen("err.log","w",stderr);
	O.put8(0);
	while(1){
		while(i=read(),i&&i<=(1ull<<32))ca[cc++]=i;
		if(!i)goto end;
		if(cc==1&&(ca[0]==7||ca[0]==1||ca[0]==237))--cc;
		if(cc==2&&ca[0]==ca[1])--cc;
		if((cc&&ca[0]<10000)||cc==0||cc>2||i<13000000000ull||i>19999990000ull){
			for(int x=0;x<cc;++x)fprintf(stderr,"%llu ",ca[x]);
			fprintf(stderr,"%llu\n",i);
		}
		while(cc--)O.put5(ca[cc]),O.put5(i),++k;
		cc=0;
	}
	end:;
	printf("%llu %llu",k,I.ptr());
	I.Close();
	O.Close();
	getchar();
	return 0;
}
