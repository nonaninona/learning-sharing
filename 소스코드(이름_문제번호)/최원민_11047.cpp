#include <iostream>
using namespace std;


int main(void)
{

    int n, k;//���� ��������, �����k��
    int nArr[10] = { 0, };
    int result = 0;
    int in_put;
    cin >> n;
    cin >> k;

    //���� �ֱ�
    for (int i = 0; i < n; i++)
    {
        cin >> in_put;
        nArr[i] = in_put;
    }
    //k���� ������Ű��
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            while (1)
            {
                if (nArr[n - 1 - i] <= k)//������ ���� ������ �۰ų� ����
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