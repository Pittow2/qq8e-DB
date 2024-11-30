#include<cstdio>
#include"io.h"
u64 A[20000],B[5000];
void init(){
	int n,i;
	freopen("map.txt","r",stdin);
	while(scanf("%d",&i),i)A[i]=n,B[n++]=i;
	fclose(stdin);
}
u64 zip(u64 a){
	u64 u=a/1000000;
	if(u>=20000)return 0;
	if(B[A[u]]!=u)return 0;
	return A[u]*1000000+a%1000000;
}
u64 unzip(u64 a){
	u64 u=a/1000000;
	return B[u]*1000000+a%1000000;
}
u64 read(Input *g,u64 pos,int w){
	g->setpos(pos);
	u64 r=0;
	while(w--)r=(r<<8)|g->gc();
	return r;
}
int lb(int x){return x&(-x);}
