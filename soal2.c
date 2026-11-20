#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int langkahMinimal(int g1, int g2, int takar) {

    if (takar > (g1 > g2 ? g1 : g2)) return -1; 
	
    int q[10000][3], front = 0, rear = 0;

    bool terkunjungi[g1 + 1][g2 + 1];
    for (int i = 0; i <= g1; i++) {
        for (int j = 0; j <= g2; j++) {
            terkunjungi[i][j] = false;
        }
    }

    q[rear][0] = 0;
    q[rear][1] = 0;
    q[rear][2] = 0;
    rear++;
    terkunjungi[0][0] = true;

    while (front != rear) {
      
        int gelas1 = q[front][0];
        int gelas2 = q[front][1];
        int langkah = q[front][2];
        front++;

        if (gelas1 == takar || gelas2 == takar) return langkah;

        if (!terkunjungi[g1][gelas2]) {
            terkunjungi[g1][gelas2] = true;
            q[rear][0] = g1;
            q[rear][1] = gelas2;
            q[rear][2] = langkah + 1;
            rear++;
        }

        if (!terkunjungi[gelas1][g2]) {
            terkunjungi[gelas1][g2] = true;
            q[rear][0] = gelas1;
            q[rear][1] = g2;
            q[rear][2] = langkah + 1;
            rear++;
        }

        if (!terkunjungi[0][gelas2]) {
            terkunjungi[0][gelas2] = true;
            q[rear][0] = 0;
            q[rear][1] = gelas2;
            q[rear][2] = langkah + 1;
            rear++;
        }

        if (!terkunjungi[gelas1][0]) {
            terkunjungi[gelas1][0] = true;
            q[rear][0] = gelas1;
            q[rear][1] = 0;
            q[rear][2] = langkah + 1;
            rear++;
        }

        int tuang1ke2 = gelas1 < (g2 - gelas2) ? gelas1 : (g2 - gelas2);
        if (!terkunjungi[gelas1 - tuang1ke2][gelas2 + tuang1ke2]) {
            terkunjungi[gelas1 - tuang1ke2][gelas2 + tuang1ke2] = true;
            q[rear][0] = gelas1 - tuang1ke2;
            q[rear][1] = gelas2 + tuang1ke2;
            q[rear][2] = langkah + 1;
            rear++;
        }

        int tuang2ke1 = gelas2 < (g1 - gelas1) ? gelas2 : (g1 - gelas1);
        if (!terkunjungi[gelas1 + tuang2ke1][gelas2 - tuang2ke1]) {
            terkunjungi[gelas1 + tuang2ke1][gelas2 - tuang2ke1] = true;
            q[rear][0] = gelas1 + tuang2ke1;
            q[rear][1] = gelas2 - tuang2ke1;
            q[rear][2] = langkah + 1;
            rear++;
        }
    }

    return -1;
}

int main() {
  
    int g1, g2, takar;
    scanf("%d %d %d", &g1, &g2, &takar);
    int result = langkahMinimal(g1, g2, takar);
    printf("%d\n", result);
    return 0;
}

/*
REFERENSI
[1] https://www.geeksforgeeks.org/c/operators-in-c/
[2] https://www.geeksforgeeks.org/dsa/two-water-jug-puzzle/#approach-1
[3] https://www.w3schools.com/c/c_user_input.php
*/
