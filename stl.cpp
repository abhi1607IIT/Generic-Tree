#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	
	vector<int> v1;
	for (int i = 0; i < 30; i++) {
		cout << "capacity " << v1.capacity() << endl;
		cout << "size" << v1.size() << endl;
		cout << endl;
		//v1[i] = i + 5;
	//	v1.push_back(i + 5);
	}
	//v1[0] = 10;
	v1.push_back(10);
	v1.push_back(20);

	vector<int> *v = new vector<int>();


	delete v;

	stack<int> s;
	s.push(10);
	s.push(20);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
}

