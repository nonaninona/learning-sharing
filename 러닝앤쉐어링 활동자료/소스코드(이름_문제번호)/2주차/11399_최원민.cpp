#include <iostream>
using namespace std;

int main(void)
{
    int n;//����� ��
    int t;//���� �ϴµ� �ð�
    int nArr[1000] = { 0, };
    int temp;
    int nResult = 0;//�� ���� ��
    int result = 0;//����
    //����
    //�� �Է�
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        nArr[i] = t;
    }

    //����
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