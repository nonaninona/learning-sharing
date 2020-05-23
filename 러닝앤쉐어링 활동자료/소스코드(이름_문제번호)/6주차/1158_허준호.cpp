#include <iostream>

using namespace std;

void save(int* now, int* result, int N, int K)
{
	int count = 0, i = 0, j = 0;
	while (j <= N-1) //result의 index값이 유효한 범위인 동안
	{
		count = 0; //숫자를 세기 전 항상 0으로 초기화
		while (count < K)
		{
			if (i > N - 1) //now 배열에서 유효 index를 초과한 경우
			{
				i = 0; //처음으로 돌아간다
			}

			if (now[i] == 0)//해당 칸이 이미 방이 빠진 경우
			{ 
				i++; //인덱스만 증가
				continue;
			}

			else //방이 안 빠진 경우에만
			{
				count++; //count 증가
				i++; //now 인덱스 증가
			}
		}

		//위 while문을 돈 경우 제거할 칸의 정보가 i에 저장되있을 것이다
		now[i-1] = 0; //방 비우기
		result[j] = i; //방 정보 저장
		j++;
	}

	//결과 출력
	cout << "<";
	for (int z = 0; z < N; z++)
	{
		if (z == N - 1) //마지막인 경우
			cout << result[z];
		else //나머지는..
			cout << result[z] << ", ";
	}
	cout << ">" << endl;
}

int main()
{
	int N, K;
	cin >> N >> K;
	int* now = new int[N]; //현재 상태를 저장하는 배열
	int* result = new int[N]; //결과를 저장하는 배열
	for (int i = 0; i < N; i++) //현재 상태를 저장하는 배열에는 모두 1로 채운다
		now[i] = 1;

	for (int i = 0; i < N; i++) //결과를 저장하는 배열에는 모두 0으로 채운다
		result[i] = 0;


	save(now, result, N, K);
	delete[] now;
	delete[] result;
}