#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;

struct Node {
	int key, val, cnt, siz, ch[2];
}nd[maxn];

int sizn;

int newNode (int key) {  
    sizn++;  
    nd[sizn].key = key;  
    nd[sizn].val = rand();  
    nd[sizn].cnt = nd[sizn].siz = 1;  
    nd[sizn].ch[0] = nd[sizn].ch[1] = 0;  
    return sizn;
}  
  
void maintain(int u) {  
    nd[u].siz = nd[nd[u].ch[0]].siz + nd[nd[u].ch[1]].siz + nd[u].cnt;  
}  
  
void rotate (int& u, int d) {  
    int k = nd[u].ch[d];    
    nd[u].ch[d] = nd[k].ch[d^1];  
    nd[k].ch[d^1] = u;  
    maintain(u);  
    maintain(k);    
    u = k;  
}  
  
void insert (int& u, int key) {  
    if (u == 0) u = newNode(key);  
    else if (nd[u].key == key) nd[u].cnt++;  
    else {  
        int d = nd[u].key < key;  
        insert(nd[u].ch[d], key);  
        if (nd[u].val < nd[nd[u].ch[d]].val) rotate(u, d);  
    }  
    maintain(u);  
}  
  
void erase (int& u, int key) {  
    if (nd[u].key == key) {  
        if (nd[u].cnt == 1) {  
            if (nd[u].ch[0] == 0 && nd[u].ch[1] == 0) {  
                u = 0; return;  
            }  
            rotate(u, nd[nd[u].ch[0]].val < nd[nd[u].ch[1]].val);  
            erase(u, key);  
        } else  
            nd[u].cnt--;  
    } else  
        erase(nd[u].ch[nd[u].key < key], key);  
    maintain(u);  
}  
  
int count (int u, int p) {  
    if (u == 0) return 0;  
    if (nd[u].key > p) return count(nd[u].ch[0], p);  
  
    return nd[u].cnt + nd[nd[u].ch[0]].siz + count(nd[u].ch[1], p);  
}  

int main () {
	return 0;
}
