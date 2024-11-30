#include"io.h"
Output O;
int n,i;
int main(){
	n=10000000;
	O.Open("binary");
	O.put8(n);
	for(i=0;i<n;++i)O.put4(n-i-1),O.put4(i);
	O.Close();
	return 0;
}
