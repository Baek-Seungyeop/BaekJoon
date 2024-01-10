#include <iostream>
using namespace std;

class node {
public:
	node(int d, node* n = 0) {
		next_ = n;
		data_ = d;
	}
	node* next_;
	int data_;
};

class Queue {
public:
	Queue();
	bool IsEmpty();
	void InsertQ(int el);
	int DeleteQ();
private:
	node* front_;
	node* rear_;
};

Queue::Queue() {
	front_ = 0;
	rear_ = 0;
}

bool Queue::IsEmpty() {
	if (front_ == 0) return true;
	return false;
}

void Queue::InsertQ(int el) {
	if (IsEmpty()) {
		front_ = rear_ = new node(el);
		return;
	}
	rear_->next_ = new node(el);
	rear_ = rear_->next_;
}

int Queue::DeleteQ() {
	if (IsEmpty()) return -1;
	int el = front_->data_;
	node* ptr = front_;
	front_ = front_->next_;
	if (front_ == 0) rear_ = 0;
	delete ptr;
	return el;
}

int main()
{
	int N, lastCard;
	Queue *Card = new Queue();

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Card->InsertQ(i);
	}

	int i = 0;
	while(!Card->IsEmpty())
	{

		if (i % 2 == 0)
		{
			lastCard = Card->DeleteQ();
		}
		else
		{
			lastCard = Card->DeleteQ();
			Card->InsertQ(lastCard);
		}
		i++;
	}
	
	cout << lastCard;

	return 0;
}