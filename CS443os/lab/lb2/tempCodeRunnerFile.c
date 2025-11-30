
int main() {
    int n;
    printf("Enter number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int pid[n], arrival[n], burst[n];
    for (int i = 0; i < n; ++i) {
        pid[i] = i + 1;
        printf("Process %d arrival time and burst time: ", pid[i]);
        if (scanf("%d %d", &arrival[i], &burst[i]) != 2) return 0;
    }
