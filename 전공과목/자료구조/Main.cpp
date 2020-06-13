#include <iostream>
#define M 5
#define N 10
#define SIZE (M)*(N)+2
using namespace std;

char map[M][N];

class  Point {
public:               //좌표들
	int xpos;
	int ypos;

	void Init()       //초기화
	{
		this->xpos = 0;
		this->ypos = 0;
	}
};


class  Stack {
private:
	Point sPos;
	int arr[SIZE][2];      //스택 배열 x,y값 저장하니까 이차원
	int SP;                //스택포인터
public:
	void Init()            //스택포인터 초기화
	{
		this->SP = 0;
		this->sPos.Init();      //스택클래스의 좌표 초기화
		
	}
	
	void Push(Point &sPos)     //푸쉬
	{
		this->arr[this->SP][0] = sPos.xpos;
		this->arr[this->SP][1] = sPos.ypos;
		this->sPos = sPos;
		this->SP++;
	}

	Point Pop()                     //팝
	{
		SP--;
		if (SP < 0)
		{
			sPos = { -1,-1 };
			cout << "나갈 수 없는 미로입니다" << endl;
			return sPos;
		}
		this->sPos.xpos = arr[SP][0];
		this->sPos.ypos = arr[SP][1];
		return this->sPos;
	}

	void Movement(Point& pos)                     //다음 행동 함수 전진하거나 실패해서 뒤로가거나 한 번 간 곳은 *로 표시
	{                                              
		if (map[pos.xpos][pos.ypos + 1] == 48 && pos.ypos < 9 )     
		{
			map[pos.xpos][pos.ypos+1] = '*'; Push(pos); pos.ypos++;
		}
		else if (map[pos.xpos][pos.ypos - 1] == 48 && pos.ypos > 0)
		{
			map[pos.xpos][pos.ypos-1] = '*'; Push(pos); pos.ypos--;
		}
		else if (map[pos.xpos + 1][pos.ypos] == 48 && pos.xpos < 4)
		{
			map[pos.xpos+1][pos.ypos] = '*'; Push(pos); pos.xpos++;
		}
		else if (map[pos.xpos - 1][pos.ypos] == 48 && pos.xpos > 0)
		{
			map[pos.xpos-1][pos.ypos] = '*'; Push(pos); pos.xpos--;
		}
		else //전진을 못한다!! // 실패조건 SP가 음수
		{
			cout << "되돌아가기! " << endl;
			pos = Pop();
		}
	}
};




int main(void)
{
	Point pos;                   //주인공 점
	Stack stack;                 //스택
	int m;  //맵에 값 할당할 변수

	//초기화
	pos.Init();                   
	stack.Init();
	
	//맵 설정
	
	cout << "맵 5X10 사이즈로 만들어주세요" << endl << "1) 벽  0) 길" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m;
			map[i][j] = m+48;                    //아스키코드식으로 숫자변경
			map[0][0] = '*';
		}
	}
	
	//맵 보여주기
	cout<<endl<<endl<<"-----------------MAP---------------------"<<endl;
	cout << "     ";
	for (int i = 0; i < N; i++)
	{
		cout << "y[" << i << "] ";
	}
	cout << endl;
	for (int i = 0; i < M; i++)
	{
		cout << "x[" << i << "]  ";
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << "    ";
		}
		cout << endl<<endl;
	}

	while (pos.xpos != M-1 || pos.ypos != N-1)        //도착했을때 조건 **************
	{
		//사방에 0이 있으면 전진 없으면 후진
		cout << "(" << pos.xpos << ", " << pos.ypos << ")" << endl<<endl;
		stack.Movement(pos);
		if (pos.xpos == -1)
			return -1;
	}
	cout << "*******************성공***********************";
	//맵 보여주기
	cout << endl << endl << "-----------------MAP---------------------" << endl;
	cout << "     ";
	for (int i = 0; i < N; i++)
	{
		cout << "y[" << i << "] ";
	}
	cout << endl;
	for (int i = 0; i < M; i++)
	{
		cout << "x[" << i << "]  ";
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << "    ";
		}
		cout << endl << endl;
	}
}