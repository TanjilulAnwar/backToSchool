//http://www.shafaetsplanet.com/?p=1072

#include <stdio.h>
#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#define MAX_N 5
#define INF 99999999
#define EMPTY_VALUE -1


int w[MAX_N][MAX_N]=
 {
  INF,2,INF,1,INF,
  INF,INF,1,INF,9,
  INF,INF,INF,INF,3,
  INF,3,INF,INF,INF,
  INF,INF,INF,INF,INF
  }; 
int mem[MAX_N]={-1,-1,-1,-1,-1};

int f(int u, int n) {
    
    if (u == n - 1) {
        return 0;
    }
   
    if (mem[u] != EMPTY_VALUE) {
     
        return mem[u];
    }
   
    int ans = INF;
    for (int v = 0;v < n;v++) {
        if (w[u][v] != INF) {
            ans = min(ans, f(v, n) + w[u][v]);
        }
    }
   
    mem[u] = ans;
     printf("%d-",u);

    return mem[u];
}

int main(){
int h = f(0,5);
printf("\n%d",h);
return 0;
}
