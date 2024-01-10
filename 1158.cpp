/*#include <iostream>
using namespace std;

class Queue { // ȯ��ť
public:
	Queue(int s);
	bool IsEmpty() { return (rear_ == front_); }
	bool IsFull() { return ((rear_ + 1) % size == front_); }
	bool InsertQ(int el);
	int DeleteQ();
private:
	int arr_[5001]; // �������� ������ ������ 1 Ŀ�� ��
	int front_;
	int rear_;
	int size;
};

Queue::Queue(int s) {
	front_ = 0;
	rear_ = 0;
	size = s + 1; // ����� 1 ũ�� ��´�
}

bool Queue::InsertQ(int el) {
	if (IsFull()) return false;
	arr_[rear_++] = el;
	rear_ = rear_ % size;
	return true;
}

int Queue::DeleteQ() {
	if (IsEmpty()) return -1;
	int el = arr_[front_++];
	front_ = front_ % size;
	return el;
}

int main() {
	int N, K, num, kcnt, pcnt;
	kcnt = pcnt = 0;

	cin >> N >> K;

	Queue* q = new Queue(N);
	
	for (int i = 1; i <= N; i++)
	{
		q->InsertQ(i);
	}

	cout << "<";

	while (pcnt != N)
	{
		if (kcnt == K - 1)
		{
			pcnt++;
			kcnt = 0;
			num = q->DeleteQ();

			if (pcnt == N) cout << num << ">";
			else cout << num << ", ";
		}	
		else
		{
			num = q->DeleteQ();
			q->InsertQ(num);
			kcnt++;
		}	
	}

	return 0;
}*/
// ȯ�� ť ����

/*int main()
{
	int N, K, pcnt, kcnt, index;
	int jose[5000];

	pcnt = kcnt = index = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		jose[i] = i + 1;
	}

	cout << "<";
	while (pcnt != N)
	{
		if (index == N)
		{
			index = 0;
		}
		if (jose[index] != 0)
		{
			if (kcnt == K - 1)
			{
				kcnt = 0; // �似Ǫ�� ī��Ʈ
				pcnt++; // ��� ī��Ʈ
				if (pcnt == N) cout << jose[index];		
				else cout << jose[index] << ", ";

				jose[index] = 0;
			}
			else
			{
				kcnt++;
			}
			index++;
		}
		else
		{
			index++;
		}
	}
	cout << ">";

	return 0;
}*/
// brute force, �迭