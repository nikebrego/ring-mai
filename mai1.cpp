#include <iostream>
#include <cstdlib>

class Queue
	{
	public:
		Queue( int size )
		{
			head = tail = length = 0;
			bufferSize = size;
			arr = new int[bufferSize];
			for ( int i = 0; i < bufferSize; ++i )
			arr[i] = 0;
		}
	~Queue() {
		delete[] arr;
	}
	void put( int value )
	{
		if ( length == bufferSize )
		{
			std::cout << "Queue is full!\n";
			return;
		}
	if ( tail == bufferSize )
	tail = 0;
	arr[tail] = value;
	++tail;
	++length;
	}
void get()
	{
		if ( length == 0 )
		{
			std::cout << "Queue is empty!\n";
			return;
		}	
	if ( head == bufferSize )
	head = 0;
	std::cout << "Element = " << arr[head] << "\n";
	arr[head] = 0;
	++head;
	--length;
	}
	void printQueue() const
		{
		int i;
		std::cout << "Queue is: ";
		if ( length == 0 )
		std::cout << " empty";
	else if ( tail > head )
		{
		for ( i = head; i < tail; ++i )
		std::cout << arr[i] << ' ';
		}
	else
		{
		for ( i = head; i < bufferSize; ++i )
		std::cout << arr[i] << ' ';
		for ( i = 0; i < tail; ++i )
		std::cout << arr[i] << ' ';
		}
	std::cout << '\n';
		}
		
		void printBuffer() const
		{
	std::cout << "Array is: ";
	for ( int i = 0; i < bufferSize; ++i )
	std::cout << arr[i] << ' ';
	std::cout << '\n';
	}
	private:
		int * arr;
		int bufferSize;
		int length;
		int tail;
		int head;
	};

int main()
{
	
	Queue myQueue(5);
	myQueue.printBuffer();
	myQueue.printQueue();
	
	std::cout << "______________________________\n";
	
	
	for ( int i = 1; i <= 6; ++i )
		{
		myQueue.put( i * 2 );
		myQueue.printBuffer();
		myQueue.printQueue();
		std::cout << "______________________________\n";
		}
	
	
	for ( int i = 1; i <= 3; ++i )
		{
		myQueue.get();
		myQueue.printBuffer();
		myQueue.printQueue();
		std::cout << "______________________________\n";
		
		}
	
	
	for ( int i = 1; i <= 3; ++i )
		{
		myQueue.put( i * 3 );
		myQueue.printBuffer();
		myQueue.printQueue();
		std::cout << "______________________________\n";
		}
	
	
	for ( int i = 1; i <= 6; ++i )
		{
		myQueue.get();
		myQueue.printBuffer();
		myQueue.printQueue();
		std::cout << "______________________________\n";
		
		}
	
	system ("pause");
	return 0;
	}
