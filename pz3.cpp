#include <iostream>

struct Node {
	unsigned char data;
	Node* prev;
	Node* next;
};

class Deque {
private:
	Node* front;
	Node* rear;

public:
	Deque() {
		front = nullptr;
		rear = nullptr;
	}

	void pushFront(unsigned char data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = nullptr;
		newNode->next = front;

		if (front != nullptr) {
			front->prev = newNode;
		} else {
			rear = newNode;
		}

		front = newNode;
	}

	void pushRear(unsigned char data) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = rear;
		newNode->next = nullptr;
		
		if (rear != nullptr) {
			rear->next = newNode;
		} else {
			front = newNode;
		}
		
		rear = newNode;
	}

	unsigned char popFront() {
		if (isEmpty()) {
			std::cout « "Deque is empty." « std::endl;
			return 0;
		}

		Node* temp = front;
		unsigned char data = temp->data;
		
		front = front->next;
		
		if (front != nullptr) {
			front->prev = nullptr;
		} else {
			rear = nullptr;
		}
		
		delete temp;
		
		return data;
	}

	unsigned char popRear() {
		if (isEmpty()) {
			std::cout « "Deque is empty." « std::endl;
			return 0;
		}
		
		Node* temp = rear;
		unsigned char data = temp->data;
		
		rear = rear->prev;
		
		if (rear != nullptr) {
			rear->next = nullptr;
		} else {
			front = nullptr;
		}
		
		delete temp;
		
		return data;
	}

	bool isEmpty() {
		return (front == nullptr && rear == nullptr);
	}
};

void sortArray(unsigned int arr[], unsigned int size) {
	// Сортировка элементов с четными индексами в порядке возрастания
	for (unsigned int i = 0; i < size; i += 2) {
		for (unsigned int j = i + 2; j < size; j += 2) {
			if (arr[j] < arr[i]) {
				unsigned int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}	
		}
	}
}

int main() {
	const unsigned int size = 10;
	unsigned int arr[size] = {5, 2, 8, 1, 9, 3, 7, 4, 6, 0};
	
	sortArray(arr, size);
	
	// Вывод отсортированного массива с четными индексами
	for (unsigned int i = 0; i < size; i += 2) {
		std::cout « arr[i] « " ";
	}
	std::cout « std::endl;
	
	Deque deque;
	
	deque.pushFront('A');
	deque.pushFront('B');
	deque.pushRear('C'); 
	deque.pushRear('D'); 
	std::cout « deque.popFront() « std::endl; // Выводит 'B' 
	std::cout « deque.popRear() « std::endl; // Выводит 'D' 
	return 0; 
}
