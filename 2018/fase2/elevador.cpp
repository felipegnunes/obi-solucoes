// Ordenação

#include <iostream>

using namespace std;

void selection_sort(int N, int v[])
{
    for (int i = 0; i < N; i++)
    {
        int min = v[i], min_index = i;

        for (int j = i + 1; j < N; j++)
        {
            if (v[j] < min)
            {
                min = v[j];
                min_index = j;
            }
        }

        if (min_index != i)
        {
            int tmp = v[i];
            v[i] = v[min_index];
            v[min_index] = tmp;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int box_weights[N];
    for (int i = 0; i < N; i++)
    {
        cin >> box_weights[i];
    }

    selection_sort(N, box_weights);

    bool possible = true;

    if (box_weights[0] > 8)
        possible = false;

    for (int i = 0; i < N - 1; i++)
    {
        if (box_weights[i + 1] - box_weights[i] > 8)
            possible = false;
    }

    if (possible)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}