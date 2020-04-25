#include <iostream>
using namespace std;

int main(void)
{
    int n;//사람의 수
    int t;//인출 하는데 시간
    int nArr[1000] = { 0, };
    int temp;
    int nResult = 0;//각 쌓인 값
    int result = 0;//총합
    //정렬
    //값 입력
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        nArr[i] = t;
    }

    //정렬
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (nArr[j] > nArr[j + 1])
            {
                temp = nArr[j];
                nArr[j] = nArr[j + 1];
                nArr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            nResult = nArr[i];
            result += nResult;
        }
        else
        {
            nResult += nArr[i];
            result += nResult;
        }

    }
    cout << result;
}