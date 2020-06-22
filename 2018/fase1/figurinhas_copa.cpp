// Ad hoc

#include <iostream>

using namespace std;

int main()
{
    int N, C, M;
    cin >> N >> C >> M;

    bool album[N] = {false}; // Algumas versões do compilador não reconhecem esse comando
    
    int figurinhas_carimbadas[C];
    for (int i = 0; i < C; i++){
        cin >> figurinhas_carimbadas[i];
    }

    for (int i = 0; i < M; i++){
        int jah_comprada;
        cin >> jah_comprada;
        album[jah_comprada - 1] = true;
    }

    int faltantes = 0;
    for (int i = 0; i < C; i++){
        if (!album[figurinhas_carimbadas[i] - 1])
            faltantes++;
    }

    cout << faltantes << endl;
}