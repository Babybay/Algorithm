//fibbonaci
#include <stdio.h>

int fibo(int n){
	if(n == 0) return 0;
	else if(n == 1) return 1;
	return fibo(n-1) + fibo(n-2);
}

//precompute


int main(){
	//constraint: T test case 1 < T < 100
	//constraint: N = 1 < N < 40
	int t,n;
	int deretFibo[35];
	
	//precompute
	for(int i=0; i<30; i++){
		deretFibo[i] = fibo(i);
	}
	
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		printf("Case #%d: %d\n", i+1, deretFibo[n]);

	}		
	
	return 0;	
}
