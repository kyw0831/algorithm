//���ؾ˰��� 2231��
//Ǭ ��¥ : 2019-03-26
#include <iostream>
using namespace std;

//�ڸ���
int get_digit(int num) {
	int digit = 0;
	while (num != 0) {
		num /= 10;
		digit++;
	}
	return digit;
}

//������
int get_DecompositionSum(int num) {
	int result = num;
	while (num != 0) {
		result += num % 10;
		num /= 10;
	}
	return result;
}

int main() {
	int n;
	int flag = 0;
	cin >> n;
	for (int i = n - get_digit(n)*9 ; i < n; i++) { //�ڸ��� ����ȭ
		if (get_DecompositionSum(i) == n) {
			flag = 1;
			cout << i << endl;
			break;
		}
	}
	if (flag == 0) cout << 0 << endl;
}
