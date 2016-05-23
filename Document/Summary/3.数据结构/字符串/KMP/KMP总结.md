
# KMP总结

@(柯帅)[算法总结|数据结构|字符串|KMP|2015-05-19]

-------------------

[TOC]

-------------------

### KMP简介
> KMP算法的关键是利用匹配失败后的信息，尽量减少模式串与主串的匹配次数以达到快速匹配的目的。具体实现就是实现一个fail数组，数组本身包含了模式串的局部匹配信息。

**KMP**主要用于字符串匹配，fail[i]表示T[i-fail[i]+1~i]和T[1~fail[i]]是相同的。

**循环节**也就是前缀后缀串，p从fail[n]开始，所有的p=fail[p]，1~p均为循环节。

#### 基本操作
- 初始化（get_fail）：获得失配函数。
- 匹配操作（match）：匹配查询串。

#### 模板
``` C++
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;
int fail[maxn];

void getFail (char* str) {
	int n = strlen(str+1);
    int p = fail[0] = fail[1] = 0;

    for (int i = 2; i <= n; i++) {
        while (p && str[p+1] != str[i])
            p = fail[p];

        if (str[p+1] == str[i])
            p++;
        fail[i] = p;
    }
}

int match (char* S, char* T) {
	getFail(T);

    int p = 0, ret = 0, n = strlen(S);
    for (int i = 1; i <= n; i++) {
        while (p && T[p+1] != S[i])
            p = fail[p];

        if (T[p+1] == S[i])
            p++;

        ret = max(ret, p);
    }
    return ret;
}
```

-------------------

### KMP题型

#### 匹配问题
匹配位置、最大匹配次数、最大匹配长度。通过修改match函数的终止条件来实现。

#### 循环子串
根据fail数组的特性解决的一系列问题。

-------------------

### KMP经典题

#### hdu 4763 Theme Section
- [题目链接](http://blog.csdn.net/keshuai19940722/article/details/21591369)

砍掉头尾后，用模式串去匹配中间是否存在。

#### uva 11888 - Abnormal 89's
- [题目链接](http://blog.csdn.net/keshuai19940722/article/details/39061559)

将字符串翻转后做匹配。

#### uva 1358 - Generator
- [题目链接](http://blog.csdn.net/keshuai19940722/article/details/39060475)

利用fail数组的性质，推导出递推式计算期望。

-------------------

### KMP习题补充

#### 匹配问题
#####匹配位置
- [hdu 1711 Number Sequence](http://blog.csdn.net/keshuai19940722/article/details/21402721)
- [hdu 2203 亲和串](http://blog.csdn.net/keshuai19940722/article/details/21470939)

##### 最大匹配个数
- [hdu 4749 Parade Show](http://blog.csdn.net/keshuai19940722/article/details/21339045)
- [hdu 1686 Oulipo](http://blog.csdn.net/keshuai19940722/article/details/21402853)
- [hdu 2087 剪花布条](http://blog.csdn.net/keshuai19940722/article/details/21403039)
- [hdu 3374 String Problem](http://blog.csdn.net/keshuai19940722/article/details/21561689)

##### 最长匹配长度
- [uva 11557 - Code Theft](http://blog.csdn.net/keshuai19940722/article/details/39061223)
- [poj 2185 Milking Grid](http://blog.csdn.net/keshuai19940722/article/details/40509745)


#### 循环子串问题
- [hdu 3746 Cyclic Nacklace](http://blog.csdn.net/keshuai19940722/article/details/21403723)
- [uva 1328 Period](http://blog.csdn.net/keshuai19940722/article/details/21469381)
- [hdu 2954 Simpsons’ Hidden Talents](http://blog.csdn.net/keshuai19940722/article/details/21483799)
- [uva 10298 - Power Strings ](http://blog.csdn.net/keshuai19940722/article/details/21559361)
- [poj 2752 Seek the Name, Seek the Fame](http://blog.csdn.net/keshuai19940722/article/details/21559543)
- [hdu 3336 Count the string](http://blog.csdn.net/keshuai19940722/article/details/21560117)
- [hdu 4300 Clairewd’s message](http://blog.csdn.net/keshuai19940722/article/details/21560417)
- [hdu 1238 Substrings](http://blog.csdn.net/keshuai19940722/article/details/21561001)
- [fzu 1901 Period II](http://blog.csdn.net/keshuai19940722/article/details/21562525)
- [uva 12012 - Detection of Extraterrestrial](http://blog.csdn.net/keshuai19940722/article/details/39062629)
- [Codeforces 432D Prefixes and Suffixes(KMP+dp)](http://blog.csdn.net/keshuai19940722/article/details/26098533)
- [uva 11475 - Extend to Palindrome](http://blog.csdn.net/keshuai19940722/article/details/38987221)

-------------------

### 拓展KMP算法

#### 简介
给出两个字符串A（称为模板串）和B（称为子串），长度分别为lenA和lenB，要求在线性时间内，对于每个A[i]（0<i≤lenA），求出A[i]往前和B的前缀匹配的最大匹配长度，即T[i~i+cpfix[i]-1]和T[1~cpfix[i]]相等。

#### 模板
``` C++
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;
int cpfix[maxn], extand[maxn];

void getCPfix(char* str) {
	int n = strlen(str + 1), tmp = 1;
	cpfix[1] = n;

	while (tmp < n && str[tmp] == str[tmp+1])
		tmp++;
	cpfix[2] = tmp-1;

	int p = 2;
	for (int k = 3; k <= n; k++) {
		int e = p + cpfix[p] - 1, l = cpfix[k-p+1]; // e 为目前匹配过的最末位置, l 为对应的偏移;

		if (k + l - 1 >= e) {
			int j = e - k > 0 ? e - k : 0;
			while (k + j <= n && str[k+j] == str[j+1])
				j++;
			cpfix[k] = j, p = k;
		} else
			cpfix[k] = l;
	}
}

void getExtand(char* S, char* T) {
	getCPfix(T);

	int sn = strlen(S+1), tn = strlen(T+1);
	int n = min(sn, tn), tmp = 1;

	while (tmp <= n && S[tmp] == T[tmp])
		tmp++;
	extand[1] = tmp-1;

	int p = 1;
	for (int k = 2; k <= sn; k++) {
		int e = p + extand[p] - 1, l = cpfix[k-p+1];
		if (k + l - 1 >= e) {
			int j = e - k > 0 ? e - k : 0;
			while (k + j <= sn && j < tn && S[k+j] == T[j+1])
				j++;
			extand[k] = j, p = k;

		} else
			extand[k] = l;
	}
}
```

#### 习题
- [hdu 4333 Revolving Digits(拓展KMP)](http://blog.csdn.net/keshuai19940722/article/details/41172991)

