#include <iostream>
#define M 5
#define N 10
#define SIZE (M)*(N)+2
using namespace std;

char map[M][N];

class  Point {
public:               //��ǥ��
	int xpos;
	int ypos;

	void Init()       //�ʱ�ȭ
	{
		this->xpos = 0;
		this->ypos = 0;
	}
};


class  Stack {
private:
	Point sPos;
	int arr[SIZE][2];      //���� �迭 x,y�� �����ϴϱ� ������
	int SP;                //����������
public:
	void Init()            //���������� �ʱ�ȭ
	{
		this->SP = 0;
		this->sPos.Init();      //����Ŭ������ ��ǥ �ʱ�ȭ
		
	}
	
	void Push(Point &sPos)     //Ǫ��
	{
		this->arr[this->SP][0] = sPos.xpos;
		this->arr[this->SP][1] = sPos.ypos;
		this->sPos = sPos;
		this->SP++;
	}

	Point Pop()                     //��
	{
		SP--;
		if (SP < 0)
		{
			sPos = { -1,-1 };
			cout << "���� �� ���� �̷��Դϴ�" << endl;
			return sPos;
		}
		this->sPos.xpos = arr[SP][0];
		this->sPos.ypos = arr[SP][1];
		return this->sPos;
	}

	void Movement(Point& pos)                     //���� �ൿ �Լ� �����ϰų� �����ؼ� �ڷΰ��ų� �� �� �� ���� *�� ǥ��
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
		else //������ ���Ѵ�!! // �������� SP�� ����
		{
			cout << "�ǵ��ư���! " << endl;
			pos = Pop();
		}
	}
};




int main(void)
{
	Point pos;                   //���ΰ� ��
	Stack stack;                 //����
	int m;  //�ʿ� �� �Ҵ��� ����

	//�ʱ�ȭ
	pos.Init();                   
	stack.Init();
	
	//�� ����
	
	cout << "�� 5X10 ������� ������ּ���" << endl << "1) ��  0) ��" << endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> m;
			map[i][j] = m+48;                    //�ƽ�Ű�ڵ������ ���ں���
			map[0][0] = '*';
		}
	}
	
	//�� �����ֱ�
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

	while (pos.xpos != M-1 || pos.ypos != N-1)        //���������� ���� **************
	{
		//��濡 0�� ������ ���� ������ ����
		cout << "(" << pos.xpos << ", " << pos.ypos << ")" << endl<<endl;
		stack.Movement(pos);
		if (pos.xpos == -1)
			return -1;
	}
	cout << "*******************����***********************";
	//�� �����ֱ�
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