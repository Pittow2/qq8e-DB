#include"io.h"
Input I;
Output O;
u64 n,i;
int main(){
	I.Open("binary");
	n=I.get8();
	O.Open("reverse");
	O.put8(n);
	for(i=0;i<n;++i)I.get4(),O.put4(I.get4());
	I.Close();
	O.Close();
	return 0;
}
