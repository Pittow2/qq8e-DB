#include<cstdio>
#include"io.h"
typedef unsigned char byte;
typedef unsigned long long u64;
Input I;
u64 n,i,a,b;
int main(){
	I.Open("binary");
	n=(I.s-8)/8;
	if(n!=I.get8())return n;
	for(i=0;i<n;++i){
		a=I.get4();
		if(i&&a<b)return a;
		b=I.get4();
		if(a!=i)return a;
		if(b!=n-i-1)return n+b;
		b=a;
	}
	I.Close();
	puts("Pretest Passed");
	return 0;
}
