//백준알고리즘 11000번
//푼 날짜 : 2019-03-26
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b;
	vector<pair<int, int>> v;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > q; //오름차순

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a,b});
	}

	//시작시간 순서로 정렬
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int end = v[i].second;

		if (q.empty()) //초기값
			q.push({end, start});
		else if (q.top().first <= start) { //가장 빨리 끝나는 수업의 끝시간 <= 새로 시작하는 수업의 시작시간
			q.pop(); 
			q.push({end, start});
		}
		else //강의실 추가
			q.push({end, start});
	}

	//output
	cout << q.size();
	return 0;
}






















/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int max_num = 1;
void maximum(int num) {
	if (num > max_num)
		max_num = num;
}

int main() {
	int n;
	int a, b;
	int max = 1;

	vector<int> s;
	vector<int> t;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		s.push_back(a);
		t.push_back(b);
	}
	sort(s.begin(), s.end(), less<int>());
	sort(t.begin(), t.end(), less<int>());
	//vector<int>::iterator iter_a = a.begin();
	//vector<int>::iterator iter_b = b.begin();
	
	for (int i=1;i<n;i++) {
		for (int j=0;j<n;j++) {
			cout << "s[" << i << "] ("<<s[i]<<")와 t[" << j << "] ("<<t[j]<<")를 비교합니다." << endl;
			if (s[i] < t[j]) {
				max++;
				break;
			}
		}
		maximum(max);
		max = 1;
	}
	cout << max_num << endl;
}

/*
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	int s, t;
	int count = 0;

	priority_queue<int, vector<int>, less<int>> sq;
	priority_queue<int, vector<int>, greater<int>> tq;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> t;
		sq.push(s);
		tq.push(t);
	}

	for (int i = 0; i < n; i++)
	{
		if (tq.top() <= sq.top())
			count++;
		tq.pop();
	}

	cout << n - count << endl;
}
*/
