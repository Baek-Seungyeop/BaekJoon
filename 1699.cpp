//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int dp[100001];
//
//int main() {
//
//	int N;
//	cin >> N;
//
//	for (int i = 0; i <= N; i++)
//		dp[i] = i;
//
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j * j <= i; j++) {
//
//			dp[i] = min(dp[i], dp[i - j * j] + 1);
//			// 참고 : https://chanhuiseok.github.io/posts/baek-10/
//			// min 함수 : https://blog.naver.com/kks227/220246545025
//		}
//	}
//	cout << dp[N];
//}

/*

1 = 1^2    
2 = 1^2 + 1        
3 = 1^2 + 2   

4 = 2^2              
5 = 2^2 + 1         
6 = 2^2 + 2        
7 = 2^2 + 3       
8 = 2^2 + 4  

9 = 3^2          
10 = 3^2 + 1        
11 = 3^2 + 2        
12 = 3^2 + 3       
13 = 3^2 + 4           
14 = 3^2 + 5             
15 = 3^2 + 6   

16 = 4^2               
17 = 4^2 + 1        
18 = 4^2 + 2           
19 = 4^2 + 3          
20 = 4^2 + 4           
21 = 4^2 + 5
22 = 4^2 + 6
23 = 4^2 + 7
24 = 4^2 + 8

25 = 5^2

*/