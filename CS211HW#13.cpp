/* Eli Kleinworm CS211
	HW#13 fibonacci
*/

#include <iostream>
#include <time.h>
using namespace std;

//Return the nth fibonacci number

//Recursive
int fib(int n){
	if(n==1||n==2) return 1;
	return fib(n-1)+fib(n-2);
}

//Iterative
long ifib(int n){
	int n1=1, n2=1, f=1;
	for(int i=2; i<n; i++){
		f=n1+n2;
		n1=n2;
		n2=f;
	}
	return f;
}

int main(){
	double begin = time(NULL);
	cout << " # | n " << endl;
	cout << "-------" << endl;
	for(int i=1; i<=75; i++)
		cout << " " << i << " | " << ifib(i) << " " << endl;
	double end = time(NULL);
	cout << "TIME ELAPSED: " << double(end-begin);
	return 0;
}