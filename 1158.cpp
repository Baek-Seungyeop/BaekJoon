/*#include <iostream>
using namespace std;

class Queue { // 환형큐
public:
	Queue(int s);
	bool IsEmpty() { return (rear_ == front_); }
	bool IsFull() { return ((rear_ + 1) % size == front_); }
	bool InsertQ(int el);
	int DeleteQ();
private:
	int arr_[5001]; // 문제에서 제시한 값보다 1 커야 함
	int front_;
	int rear_;
	int size;
};

Queue::Queue(int s) {
	front_ = 0;
	rear_ = 0;
	size = s + 1; // 사이즈를 1 크게 잡는다
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
// 환형 큐 구현

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
				kcnt = 0; // 요세푸스 카운트
				pcnt++; // 출력 카운트
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
// brute force, 배열