#ifndef _IO_H
#define _IO_H

#include<windows.h>
typedef unsigned char byte;
typedef unsigned int u32;
typedef unsigned long long u64;
void set(HANDLE g,u64 P){
	LONG h=P>>32;
	SetFilePointer(g,P,&h,FILE_BEGIN);
}
struct Input{
	int Block;
	HANDLE in;
	byte *buf;
	u64 s,cnt,R;
	DWORD sh;
	bool flag;//1:file end
	int *C;
	void setpos(u64 pos){
		R=pos/Block;
		cnt=pos%Block;
		set(in,R*Block);
		ReadFile(in,buf,Block,&sh,0);
	}
	int Open(const char *path,int B=1048576){
		Block=B;
		C=new int;
		*C=1;
		flag=0;
		in=CreateFileA(path,GENERIC_READ,0,0,OPEN_EXISTING,0,0);
		if(in==INVALID_HANDLE_VALUE)return GetLastError();
		buf=new byte[Block];
		s=GetFileSize(in,&sh);
		s|=(u64)sh<<32;
		setpos(0);
		return 0;
	}
	void Copy(Input *g,u64 pos){
		Block=g->Block;
		C=g->C;
		++*C;
		flag=0;
		in=g->in;
		buf=new byte[Block];
		s=g->s;
		setpos(pos);
	}
	void Close(){
		--*C;
		if(*C==0){
			delete C;
			CloseHandle(in);
		}
		delete buf;
	}
	u64 ptr(){return R*Block+cnt;}
	u32 gc(){
		if(ptr()==s)flag=1;
		if(flag)return 0;
		if(cnt==Block){
			cnt=0;++R;
			set(in,R*Block);
			ReadFile(in,buf,Block,&sh,0);
		}
		return buf[cnt++];
	}
	u32 get2(){return (gc()<<8)|gc();}
	u64 get4(){return (get2()<<16)|get2();}
	u64 get5(){return (get4()<<8)|gc();}
	u64 get8(){return (get4()<<32)|get4();}
};
struct Output{
	int Block;
	HANDLE out;
	byte *p;
	u64 P,S;
	DWORD sh;
	int *C;
	void flush(){
		set(out,P);
		WriteFile(out,p,S,&sh,0);
		P+=S;S=0;
	}
	void setpos(u64 pos){
		if(S)flush();
		P=pos;S=0;
	}
	int Open(const char *path,int B=1048576){
		Block=B;
		C=new int;
		*C=1;
		out=CreateFileA(path,GENERIC_WRITE,0,0,OPEN_ALWAYS,0,0);
		if(out==INVALID_HANDLE_VALUE)return GetLastError();
		p=new byte[Block];
		setpos(0);
		return 0;
	}
	void Copy(Output *g,u64 pos){
		Block=g->Block;
		C=g->C;
		++*C;
		out=g->out;
		p=new byte[Block];
		setpos(pos);
	}
	void Close(){
		flush();
		--*C;
		if(*C==0){
			delete C;
			CloseHandle(out);
		}
		delete p;
	}
	void put(byte a){
		p[S++]=a;
		if((P+S)%Block==0)flush();
	}
	void put2(u32 a){put(a>>8);put(a&255);}
	void put3(u32 a){put2(a>>8);put(a&255);}
	void put4(u32 a){put2(a>>16);put2(a&65535);}
	void put5(u64 a){put(a>>32);put4(a);}
	void put8(u64 a){put4(a>>32);put4(a);}
};

#endif
