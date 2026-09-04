
#include <stdio.h>
#include <math.h>
#include <complex>

using namespace std;

#define MAX 128
#define PI 3.141592653589793

// FFT Function
void FFT(complex<double> a[], int n, int inverse)
{
    if (n == 1)
        return;

    complex<double> even[MAX], odd[MAX];

    // Divide into even and odd elements
    for (int i = 0; i < n / 2; i++)
    {
        even[i] = a[2 * i];
        odd[i] = a[2 * i + 1];
    }

    // Recursive calls
    FFT(even, n / 2, inverse);
    FFT(odd, n / 2, inverse);

    // Combine
    for (int k = 0; k < n / 2; k++)
    {
        double angle = 2 * PI * k / n;

        if (!inverse)
            angle = -angle;

        complex<double> w(cos(angle), sin(angle));

        a[k] = even[k] + w * odd[k];
        a[k + n / 2] = even[k] - w * odd[k];
    }
}

// Convolution Function
void convolution(int A[], int m, int B[], int n)
{
    int N = 1;

    // Find required FFT size
    while (N < m + n - 1)
        N = N * 2;

    complex<double> FA[MAX] = {};
    complex<double> FB[MAX] = {};

    // Copy A into FA
    for (int i = 0; i < m; i++)
        FA[i] = A[i];

    // Copy B into FB
    for (int i = 0; i < n; i++)
        FB[i] = B[i];

    // FFT of A and B
    FFT(FA, N, 0);
    FFT(FB, N, 0);

    // Point-wise multiplication
    for (int i = 0; i < N; i++)
        FA[i] = FA[i] * FB[i];

    // Inverse FFT
    FFT(FA, N, 1);

    // Display result
    printf("Convolution = ");

    for (int i = 0; i < m + n - 1; i++)
        printf("%.0f ", FA[i].real() / N);

    printf("\n");
}

int main()
{
    int A[MAX], B[MAX];
    int m, n;

    printf("Enter size of A: ");
    scanf("%d", &m);

    printf("Enter elements of A: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &A[i]);

    printf("Enter size of B: ");
    scanf("%d", &n);

    printf("Enter elements of B: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    convolution(A, m, B, n);

    return 0;
}