//���ؾ˰��� 11000��
//Ǭ ��¥ : 2019-03-26
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n, a, b;
	vector<pair<int, int>> v;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > q; //��������

	//input
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({a,b});
	}

	//���۽ð� ������ ����
	sort(v.begin(), v.end());
	
	for (int i = 0; i < n; i++) {
		int start = v[i].first;
		int end = v[i].second;

		if (q.empty()) //�ʱⰪ
			q.push({end, start});
		else if (q.top().first <= start) { //���� ���� ������ ������ ���ð� <= ���� �����ϴ� ������ ���۽ð�
			q.pop(); 
			q.push({end, start});
		}
		else //���ǽ� �߰�
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
			cout << "s[" << i << "] ("<<s[i]<<")�� t[" << j << "] ("<<t[j]<<")�� ���մϴ�." << endl;
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
