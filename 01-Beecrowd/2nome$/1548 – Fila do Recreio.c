#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        
        scanf("%d", &m);
        int p[m], q[m];

        for (int j = 0; j < m; j++) {
            scanf("%d", &p[j]);
            q[j] = p[j]; 
        }

        for (int a = 0; a < m - 1; a++) {
            
            for (int b = 0; b < m - 1 - a; b++) {
                
                if (q[b] < q[b + 1]) { 
                    int temp = q[b];
                    q[b] = q[b + 1];
                    q[b + 1] = temp;
                }
            }
        }

        int certo = 0;
        for (int a = 0; a < m; a++) {
            if (p[a] == q[a]) 
                certo++;
        }


        printf("%d\n", certo);
    }

    return 0;
}