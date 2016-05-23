#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 2 * 1e5 + 5;

int rad[maxn];
char str[maxn];

int manachar(char* tmpstr) {  
	int len = strlen(tmpstr), cnt = 0;  
	str[cnt++] = '$'; 
	for (int i = 0; i <= len; i++) {  
		str[cnt++] = '#';  
		str[cnt++] = tmpstr[i];  
	} 

	int ans = 0, mix = 0, id = 0;
	for (int i = 1; i <= cnt; i++) {  
		if (mix > i)  
			rad[i] = min(rad[2 * id - i], mix - i);  
		else  
			rad[i] = 1;  

		for ( ; str[i - rad[i]] == str[i + rad[i]]; rad[i]++) {  
			if (mix < i + rad[i]) {  
				mix = i + rad[i];  
				id = i;  
			}  
		}  

		ans = max(ans, rad[i]);  
	}  
	return ans - 1;  
}  
