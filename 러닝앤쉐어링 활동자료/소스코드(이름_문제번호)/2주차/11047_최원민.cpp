#include <iostream>
using namespace std;


int main(void)
{

    int n, k;//동전 종류개수, 결과값k원
    int nArr[10] = { 0, };
    int result = 0;
    int in_put;
    cin >> n;
    cin >> k;

    //집어 넣기
    for (int i = 0; i < n; i++)
    {
        cin >> in_put;
        nArr[i] = in_put;
    }
    //k에서 차감시키자
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            while (1)
            {
                if (nArr[n - 1 - i] <= k)//동전이 남은 돈보다 작거나 같아
                {
                    k -= nArr[n - 1 - i];
                    result++;
                }
                else
                    break;
            }
            if (k == 0)
                break;
        }
        break;
    }


    cout << result;
    return 0;
}