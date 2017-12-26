#include <iostream>

using namespace std;


bool okay(int q[], int col, int adj[][5]);
void backtrack(int &col);
void print(int q[], int solutions);

int main(){
	//board setup 
	int q[8]; q[0]= 1;
	int adj[8][5] = {
		{-1},
		{0, -1},
		{0, 1, -1},
		{0, 2, -1},
		{1, 2, -1},
		{1, 2 , 3, 4, -1},
		{2, 3, 5, -1},
		{4, 5, 6, -1},
	};
	int box=0, solutions=0;
	bool from_backtrack = false; 

	while(true) {

		while (box<7){

			if (box==-1) return 0;
			if (!from_backtrack) {
				box++;
				q[box]=0;
			}

			from_backtrack=false;

			while(true){
				q[box]++;
				if (q[box]==9){
					backtrack(box);
					from_backtrack=true;
					break;
				}

				if (okay(q, box, adj)) break;
			}
		}

			//print sections
			print(q, solutions++);
			backtrack(box);
			from_backtrack=true;
		}
	}

	bool okay(int q[], int box, int adj[][5]) {
		int i;

  // Check that the number that hasn't been placed yet
  for(i=0; i < box; i++) {
    if(q[i] == q[box])
    	return false;
  }

  // Check the neighboring boxes for adjacent numbers using adjacency matrix
  i = 0 ;
  while(adj[box][i] != -1) {
    if(abs(q[adj[box][i]] - q[box]) == 1)
    	return false;
    i++;
  }

  return true;
}

void backtrack(int &box){
	box--;
}

void print(int q[], int solutions){
	int i;

	//prints solution #'s
	cout << "solution # " << solutions << "\n";

	//prints current solution 1D array
	cout << "{";
	for (int i = 0; i < 8; ++i){
		cout << q[i];
		if (i!=7) cout <<", ";
	}
	cout <<"}\n";

	//prints current solution in cross board
	cout <<" "<<q[1] <<" "<<q[4]<<endl <<q[0]<<" "<<q[2]<<" "<<q[5]<<" "<<q[7]<<endl <<" "<<q[3]<<" "<<q[6]<<endl;
	}




