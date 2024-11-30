#include"io.h"
#include"query.h"
Input I;
Output O;
u64 n,a,b;
int main(){
	freopen("map.txt","r",stdin);
	I.Open((char*)"lib");
	O.Open((char*)"binary");
	I.get8();
	n=(I.s-8)/10;
	O.put8(n);
	while(n--){
		a=I.get5();
		b=I.get5();
		O.put4(a);
		O.put4(zip(b));
	}
	I.Close();
	O.Close();
	return 0;
}
