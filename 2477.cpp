//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int convertIndex(int i)
//{
//	if (i == -1)return 5;
//	if (i == 6) return 0;
//	return i;
//}
//
//int main()
//{
//	int n, result;
//	int rectMax, rectMin, ri, ci; // ������ : ū ���簢��(rectMax) - ���� ���簢��(rectMin), ri, ci : ū ���簢���� �ε��� ���� ����
//	int RM = 0, CM = 0, rm, cm; // ū ������� ���� ���� : RM, CM, ���� ���簢�� ����, ���� : rm, cm
//	pair<int, int> p[6], rowMax, colMax;
//
//	rectMin = 1;
//	cin >> n;
//
//	for (int i = 0; i < 6; i++) { // first : 1, 2 -> ����, first : 3, 4 -> ����
//		cin >> p[i].first >> p[i].second;
//
//		if (p[i].first < 3)RM = max(RM, p[i].second);
//		else CM = max(CM, p[i].second);
//	} // �Է� �����鼭 ū ���簢���� ���� ���� ���̸� �� RM, CM�� �����Ѵ�
//	cout << "RM : " << RM << endl;
//	cout << "CM : " << CM << endl;
//	for (int i = 0; i < 6; i++)  {
//		if (p[i].second == RM && p[i].first < 3) {
//			rowMax = p[i];
//			ri = i;
//		}
//		else if (p[i].second == CM && p[i].first >= 3) {
//			colMax = p[i];
//			ci = i;
//		}
//	} // ū ���簢���� ã���� �ش� �ε����� �����Ѵ�
//	rectMax = rowMax.second * colMax.second;
//
//	int r1 = convertIndex(ri - 1);
//	int r2 = convertIndex(ri + 1);
//	cm = abs(p[r1].second - p[r2].second);
//	// ���� �� ���� ���̿� ����� ���� ���� ���� �翡 ���ԵǴ� ���̱⿡ ����� ���� ���밪 ���̰� ���� ���簢���� ���� ����
//
//	int c1 = convertIndex(ci - 1);
//	int c2 = convertIndex(ci + 1);
//	rm = abs(p[c1].second - p[c2].second);
//	// ���� �� ���� ���̿� ����� ���� ���� ���� �翡 ���ԵǴ� ���̱⿡ ����� ���� ���밪 ���̰� ���� ���簢���� ���� ����
//
//	rectMin = cm * rm; // ���� ���簢�� ũ��
//	result = (rectMax - rectMin) * n; // (ū ���簢�� - ���� ���簢��) * m^2�� ���� ����
//
//	cout << result;
//
//	return 0;
//}