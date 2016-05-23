/**********************
 * 欧拉函数：phi(x)等于不超过x且和x互质的整数个数
 *
 * phi(n)= n * (1-1/p1) * (1-1/p2) * ... * (1-1/pn); (pi为n的质因子)
**********************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int euler_phi(int n) { 
	int m = (int)sqrt(n+0.5);
	int ans = n; 
	for (int i = 2; i <= m; i++) { 
		if (n % i == 0) { 
			ans = ans / i * (i-1); 
			while (n%i==0) n /= i; 
		} 
	} 
	if (n > 1) 
		ans = ans / n * (n - 1); 
	return ans;
} 

void phi_table(int n, int* phi) { 
	for (int i = 2; i <= n; i++) 
		phi[i] = 0; 
	phi[1] = 1; 
	for (int i = 2; i <= n; i++) { 
		if (!phi[i]) { 
			for (int j = i*2; j <= n; j += i) { 
				if (!phi[j]) 
					phi[j] = j; 
				phi[j] = phi[j] / i * (i - 1); 
			} 
		} 
	} 
} 
