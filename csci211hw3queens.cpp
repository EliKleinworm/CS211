#include <iostream>
using namespace std;

int main() {
	int b[8][8] = {0}, r, c=0, i, Solution=1;
	b[0][0]=1;
Nc: c++; //Next column
	if(c == 8) goto print;
	r = - 1;

Nr: r++;
	if(r == 8) goto backtrack;

//row test
	for (int i = 0; i < c; i++)	{
		if (b[r][i] == 1) goto Nr;
	}

//up-diagonal test
	for (int j = 1; ((c-j) >= 0) &&((r-j) >= 0); j++) {
		if(b[r-j][c-j]==1) goto Nr;
	}

//down diagonal test
	for (int k = 1; ((c-k) >=0) && ((r+k) < 8); k++) {
		if (b[r+k][c-k] == 1) 
		goto Nr;
	}

	b[r][c] = 1;
	goto Nc;

	backtrack: c--;
	if(c == -1) return 0; //check if we are done
	r=0;
	while(b[r][c] !=1)
		r++;
	b[r][c] = 0;
	goto Nr;

	print:
	cout << "Solution" << Solution << ": " <<endl;
	for (int row = 0; row < 8; row++){
		for(int col=0; col<8; col++) {
			cout <<b[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
	Solution++;
	goto backtrack;
}



