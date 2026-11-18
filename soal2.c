#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to find the minimum operations to obtain
// d liters in one jug
int minSteps(int m, int n, int d) {
  
    // Check if the target is achievable
    if (d > (m > n ? m : n)) return -1; 
	
  	//  Queue for BFS: each state is (jug1, jug2, steps)
    int q[10000][3], front = 0, rear = 0;

    // For tracking the visited states, initialized to false
    bool visited[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            visited[i][j] = false;
        }
    }

    // Start with both jugs empty, pushing the initial
    // state (0, 0, 0) 
    q[rear][0] = 0;
    q[rear][1] = 0;
    q[rear][2] = 0;
    rear++;
    visited[0][0] = true;

    while (front != rear) {
      
        // Extract the front of the queue
        int jug1 = q[front][0];
        int jug2 = q[front][1];
        int steps = q[front][2];
        front++;

        if (jug1 == d || jug2 == d) return steps;

        // 1: Fill jug1 to its maximum capacity
        if (!visited[m][jug2]) {
            visited[m][jug2] = true;
            q[rear][0] = m;
            q[rear][1] = jug2;
            q[rear][2] = steps + 1;
            rear++;
        }

        // 2: Fill jug2 to its maximum capacity
        if (!visited[jug1][n]) {
            visited[jug1][n] = true;
            q[rear][0] = jug1;
            q[rear][1] = n;
            q[rear][2] = steps + 1;
            rear++;
        }

        // 3: Empty jug1
        if (!visited[0][jug2]) {
            visited[0][jug2] = true;
            q[rear][0] = 0;
            q[rear][1] = jug2;
            q[rear][2] = steps + 1;
            rear++;
        }

        // 4: Empty jug2
        if (!visited[jug1][0]) {
            visited[jug1][0] = true;
            q[rear][0] = jug1;
            q[rear][1] = 0;
            q[rear][2] = steps + 1;
            rear++;
        }

        // 5: Pour jug1 into jug2
        int pour1to2 = jug1 < (n - jug2) ? jug1 : (n - jug2);
        if (!visited[jug1 - pour1to2][jug2 + pour1to2]) {
            visited[jug1 - pour1to2][jug2 + pour1to2] = true;
            q[rear][0] = jug1 - pour1to2;
            q[rear][1] = jug2 + pour1to2;
            q[rear][2] = steps + 1;
            rear++;
        }

        // 6: Pour jug2 into jug1
        int pour2to1 = jug2 < (m - jug1) ? jug2 : (m - jug1);
        if (!visited[jug1 + pour2to1][jug2 - pour2to1]) {
            visited[jug1 + pour2to1][jug2 - pour2to1] = true;
            q[rear][0] = jug1 + pour2to1;
            q[rear][1] = jug2 - pour2to1;
            q[rear][2] = steps + 1;
            rear++;
        }
    }

    return -1;
}

int main() {
  
    int m, n, d;
    scanf("%d %d %d", &m, &n, &d);
    //int m = 2, n = 3, d = 1;
    int result = minSteps(m, n, d);
    printf("%d\n", result);
    return 0;
}
