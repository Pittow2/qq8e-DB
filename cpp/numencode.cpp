#include"io.h"
Input I;
Output O;
u64 n,i;
int main(){
	I.Open("number");
	n=I.get8();
	O.Open("binary");
	O.put8(n);
	for(i=0;i<n;++i)O.put4(I.get4()),O.put4(i);
	I.Close();
	O.Close();
	return 0;
}
