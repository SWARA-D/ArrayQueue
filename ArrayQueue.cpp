#include <iostream>

using namespace std;

template <typename E>
class Queue {
public:
	Queue(const int& c)
	{
		capacity = c;
		arr = new E[capacity];
		n = 0;
		f = 0;
		r = 0;
	}
	int size() const
	{
		return n;
	}
	bool empty() const
	{
		return (n==0);
	}
	const E& front() const;
	void enqueue (const E& e)
	{
		if(n==capacity)
		{
			cout << "cant" << endl;
		}
		else
		{
			arr[r] = e;
			n++;
			r = (r + 1) % (n+1);
		}
	}
	void dequeue()
	{
		if(empty())
		{
			cout << "cant" << endl;
		}
		else
		{
			f = (f + 1) % (n+1);
			n--;
		}
	}
	void print()
	{
		//cout << f << " " << r;
		for(int i = f; i != r; i=(i+1)%(n+2))
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
private:
	E* arr;
	int n;
	int f;
	int r;
	int capacity;
};
int main()
{
	Queue<int> q(4);	
	q.enqueue(5);
	q.enqueue(6);
	q.print();
	
	q.enqueue(1);
	q.enqueue(10);
	q.print();
	
	q.dequeue();
	q.print();
	
	return EXIT_SUCCESS;
}
