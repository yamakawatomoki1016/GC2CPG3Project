#include <iostream>
#include <thread>

using namespace std;

void PrintThread(uint32_t num) {
	cout << "thread" << num << endl;
}

int main() {
	thread t1(PrintThread, 1);
	t1.join();

	thread t2(PrintThread, 2);
	t2.join(); 

	thread t3(PrintThread, 3);
	t3.join();

	return 0;
}
