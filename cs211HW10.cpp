//Eli Kleinworm Cs211 HW#10 FancyPrint

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

void printBoard(int qArray[], int &counter) {
string strSol="";
int i, j, k, l;
typedef char box[5][7];
box bb, wb, bQ, wQ, *board[8][8];
for (i = 0; i<5; i++)
for (j = 0; j<7; j++) {
wb[i][j] = ' ';
bb[i][j] = char(219);
}
for (i = 0; i<5; i++)
for (j = 0; j<7; j++) {
if (i == 0 || i == 4 || j == 0 || j == 6 || (i==1 && j==2) || (i==1 && j==4)) {
wQ[i][j] = ' ';
bQ[i][j] = char(219);
}
else {
wQ[i][j] = char(219);
bQ[i][j] = ' ';
}
}

for (i = 0; i < 8; i++) {
for (j = 0; j < 8; j++) {
if ((i + j) % 2 == 0) {
if (qArray[i] == j) board[i][j] = &wQ;
else board[i][j] = &wb;
}
else {
if (qArray[i] == j) board[i][j] = &bQ;
else board[i][j] = &bb;
}
}
//strSol = strSol + (to_string(qArray[i] + 1)) + " "; 
}
cout << "  ";
for (i = 0; i<7 * 8; i++)
cout << '_';
cout << endl;
for (i = 0; i < 8; i++) {
for (k = 0; k < 5; k++) 
{
cout << " " << char(179); 
for (j = 0; j < 8; j++) 
for (l = 0; l < 7; l++) { // 7 subCols loop
cout << (*board[i][j])[k][l]; // (pointer)[][] 
}
cout << char(179) << endl; // at end of line print bar and then newline
}
}

cout << "  ";
for (i = 0; i<7 * 8; i++)
cout << char(196);
cout << endl;


cout << "The solution number is" << ++counter << " ( " << strSol << ")" << endl;

}

int main()
{
int Q[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };
int col = 0, sol = 0;
bool stopLoop = 1, rowTest = 1;

while (stopLoop)
{
rowTest = 1; 
Q[col]++;

if (Q[col] == 8) 
{
col--;
if (col < 0) return 0;
if (Q[col] == 7) continue;
Q[col]++;
}

for (int i = 0; i < col; i++)
{
if (Q[col] == Q[i] || (col - i) == abs(Q[col] - Q[i]))
{
rowTest = 0; 
break;
}
}
if (!rowTest) continue; 
col++;
if (col<8) Q[col] = -1; 
else 
{
printBoard(Q,sol);// Call Print function;
col = 7;// reset col for next sol;
//if (sol%20==0) system("Stop");
}// Printing end;
}
return 0;
}
