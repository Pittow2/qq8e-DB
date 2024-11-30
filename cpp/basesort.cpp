#include<cstdio>
#include"io.h"
Input I;
Output O[256];
u64 n,i,k,u,v,x,c[4][256];//base sum
int main(){
	I.Open("binary");
	n=(I.s-8)/8;
	if(n!=I.get8())return 8086;
	for(i=0;i<n;++i){
		for(k=3;~k;--k)++c[k][I.gc()];
		I.get4();
	}
	I.Close();
	for(k=0;k<4;++k){
		I.Open("binary");
		I.get8();
		O->Open("sorted");
		O->put8(n);
		for(u=8,i=1;i<256;++i){
			u+=c[k][i-1]*8;
			O[i].Copy(O,u);
		}
		for(i=0;i<n;++i){
			u=I.get4();
			v=I.get4();
			x=(u>>(k*8))&255;
			O[x].put4(u);
			O[x].put4(v);
		}
		I.Close();
		for(i=0;i<256;++i)O[i].Close();
		DeleteFileA("binary");
		MoveFileA("sorted","binary");
		printf("%llu sorted\n",k+1);
	}
	return 0;
}
