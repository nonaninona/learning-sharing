#include <iostream>

int n, m;
int tree[1000000];

int main()
{
    int i;
    int start = 1, end = 0, sum;
    long long int middle;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
        if (tree[i] - end > 0)   end = tree[i];
    }

    while (start <= end) {
        middle = (start + end) / 2;
        sum = 0;

        for (i = 0; i < n && sum <= m; i++) {
            if (tree[i] - middle > 0)
                sum += tree[i] - middle;
        }

        if (!(sum - m)) {
            printf("%d\n", (int)middle);
            return 0;
        }
        else if (sum - m > 0)
            start = middle + 1;
        else end = middle - 1;
    }

    printf("%d\n", end);

    return 0;
}