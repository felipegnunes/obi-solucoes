// Ad hoc

#include <iostream>

using namespace std;

int main(){
    int L, C;
    cin >> L >> C;

    int type1 = (C * L) + ((C - 1) * (L - 1));
    int type2 = (2 * (C - 1)) + (2 * (L - 1));
    
    cout << type1 << endl << type2 << endl;
}