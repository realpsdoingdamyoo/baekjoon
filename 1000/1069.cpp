#include <stdio.h>
#include <math.h>

int main() {
    int x, y, d, t;
    scanf("%d %d %d %d", &x, &y, &d, &t);
    double dist = sqrt(x * x + y * y);
    int jump = dist / d;
    double remain = dist - jump * d;
    double ans = fmin(dist, remain + jump * t);
    ans = fmin(ans, (jump + 1) * d - dist + (jump + 1) * t);
    if (jump > 0) {
        ans = fmin(ans, (double)(jump + 1) * t);
    } else {
        if (dist < d) ans = fmin(ans, t * 2.0);
    }
    printf("%.9lf", ans);
    return 0;
}
