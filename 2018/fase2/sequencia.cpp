// Maximum subarray

#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int N, L, H;
    cin >> N >> L >> H;

    int elements[N + 1], marked[N + 1];

    int marked_until_here[N + 1], sum_until_here[N + 1];
    marked_until_here[0] = sum_until_here[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> elements[i];
        sum_until_here[i] = sum_until_here[i - 1] + elements[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> marked[i];
        marked_until_here[i] = marked_until_here[i - 1] + marked[i];
    }

    int best_sum = INT_MIN;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            int num_marked_elements = marked_until_here[j] - marked_until_here[i - 1];
            if (num_marked_elements >= L && num_marked_elements <= H)
            {
                int sum = sum_until_here[j] - sum_until_here[i - 1];
                best_sum = max(best_sum, sum);
            }
        }
    }

    cout << best_sum << endl;
}