/* Eli Kleinworm
	CSC211
	HW#21 Continuted fractions
*/	

#include<cstdlib>
#include<iostream>
using namespace std;

double fraction (int a[], int size)
{
	double cur = 1.0/a[size-1];
	double sum;
	for(int i=size-2; i>=0; i--)
	{
	    	sum=(a[i]*1.0+cur);
	    	cur=1.0/sum;
	}
	return sum;
}

int* continuedFraction(int a[], int size)
{
    	int* array = new int[2];
    	int i=size-1;
    	int temp;
    	array[0]=a[size-1];
    	array[1]=1;
    	i=size-2;
    	while(i>=0)
    	{
    	    temp=array[0];
    	    array[0]=(temp*a[i])+array[1];
    	    array[1]=temp;
    	    i--;
    	}
    	return array;
}

int* recursiveFraction(int arr[], int n)
{
	int* b = new int[2];

	if(n == 1) {
		b[1] = 1;
		b[0] = arr[0];
		return b;
	}
	int* out = recursiveFraction( (arr+1), (n-1) );
	b[0] = arr[0] * out[0] + out[1];
	b[1] = out[0];
	delete[] out;
	return b;
}

int main()
{
	
	
    	int a[3]= {1,2,3};
    	cout<<"The result is: "<<fraction(a,3)<<endl;

    	int d[3]= {1,2,3};
    	int*pt = continuedFraction(d,3);
    	cout<<"The fraction using iteration: "<<*(pt+0)<<"/"<<*(pt+1)<<endl;

	int c[3]= {1,2,3};
	int*ptr = recursiveFraction(c,3);
	cout<<"The fraction using recursion: "<<*(ptr+0)<<"/"<<*(ptr+1)<<endl;
    
	return 0;
}
