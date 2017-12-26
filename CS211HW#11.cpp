#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//man = current man
//col = new man
//q[man] = current woman
//q[col] = new woman
bool ok(int q[], int col){

    int mp[3][3]={{0, 2, 1},
                {0, 2, 1},
                {1, 2, 0}};
    int wp[3][3]={{2, 1, 0},
                {0, 1, 2},
                {2, 0, 1}};

    int cm, cw, nm, nw;

    for(int i=0; i<col; i++){
        cm = i;
        cw = q[i]; //woman assigned to man i
        nm = col;
        nw = q[col];
        if(nw == cw) return false;
    }

    for(int i=0; i<col; i++){
        cm = i;
        cw = q[i]; //woman assigned to man i
        nm = col;
        nw = q[col];

        /*
           a. if the current man prefers the new woman to his partner and
           b. if the new woman prefers the current man to her partner
        */
        if(mp[cm][cw] > mp[cm][nw]&&
            wp[nw][cm] < wp[nw][nm]) return false;

        /*
           a.if the current woman prefers the new man to her partner and
           b. if the new man prefers the current woman to his partner
        */
        if(mp[nm][cw] < mp[nm][nw]&&
            wp[cw][nm] < wp[cw][cm]) return false;
            }
        
            return true;
        };
        
        void backtrack(int &col){
            col--;
            if(col==-1) exit(1);
        };

void print(int q[]){
    static int count=0;
    cout << "SOLUTION " << ++count << endl;
    cout << "Man Woman" << endl;
    for(int i=0; i<3; i++){
        cout << " " << i << "    " << q[i] << endl;
    }
    cout << endl << endl;
};

int main(){
    int q[3]; q[0]=0;
    int c=0;
    bool from_backtrack=false;

    while(true){
        while(c<3){
        if(!from_backtrack)
            q[c]=-1;
            while(q[c]<3){
                q[c]++;
                if(q[c]==3){
                    backtrack(c);
                    continue;
                }
                if(ok(q,c)) break;
            }
            c++;
            from_backtrack=false;
        }
        print(q);
        backtrack(c);
        from_backtrack=true;
    }
    return 0;
}