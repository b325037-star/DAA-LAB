
#include <stdio.h>
#include <math.h>

#define MAX 10

// (i) Matrix Addition
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// (ii) Matrix Multiplication
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0;

            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// (iii) Check Zero Matrix
int isZeroMatrix(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
                return 0;
        }
    }

    return 1;
}

// (iv) Check Symmetric Matrix
int isSymmetric(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != A[j][i])
                return 0;
        }
    }

    return 1;
}

// (v) Determinant using Gaussian Elimination
double determinant(int A[MAX][MAX], int n)
{
    double B[MAX][MAX];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[i][j] = A[i][j];

    double det = 1;

    for (int i = 0; i < n; i++)
    {
        if (B[i][i] == 0)
        {
            int row = -1;

            for (int j = i + 1; j < n; j++)
            {
                if (B[j][i] != 0)
                {
                    row = j;
                    break;
                }
            }

            if (row == -1)
                return 0;

            for (int j = 0; j < n; j++)
            {
                double temp = B[i][j];
                B[i][j] = B[row][j];
                B[row][j] = temp;
            }

            det = -det;
        }

        det = det * B[i][i];

        for (int j = i + 1; j < n; j++)
        {
            double factor = B[j][i] / B[i][i];

            for (int k = i; k < n; k++)
            {
                B[j][k] = B[j][k] - factor * B[i][k];
            }
        }
    }

    return det;
}

// (vi) Transpose In-Place
void transpose(int A[MAX][MAX], int n)
{
    int temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

// Display Matrix
void displayMatrix(int A[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }

        printf("\n");
    }
}

// (vii) Dominant Eigenvalue and Eigenvector
void eigen(int A[MAX][MAX], int n)
{
    double x[MAX], y[MAX];
    double eigenvalue = 0;
    double max;

    // Initial vector
    for (int i = 0; i < n; i++)
        x[i] = 1;

    for (int iteration = 0; iteration < 100; iteration++)
    {
        // y = A * x
        for (int i = 0; i < n; i++)
        {
            y[i] = 0;

            for (int j = 0; j < n; j++)
            {
                y[i] += A[i][j] * x[j];
            }
        }

        // Find maximum absolute value
        max = fabs(y[0]);

        for (int i = 1; i < n; i++)
        {
            if (fabs(y[i]) > max)
                max = fabs(y[i]);
        }

        // Normalize
        for (int i = 0; i < n; i++)
            x[i] = y[i] / max;

        eigenvalue = max;
    }

    printf("Dominant Eigenvalue = %.4f\n", eigenvalue);

    printf("Corresponding Eigenvector:\n");

    for (int i = 0; i < n; i++)
        printf("%.4f\n", x[i]);
}

// Main Function
int main()
{
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter order of matrix: ");
    scanf("%d", &n);

    printf("\nEnter elements of Matrix A:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nEnter elements of Matrix B:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    // (i) Addition
    addMatrix(A, B, C, n);

    printf("\n1. Matrix Addition:\n");
    displayMatrix(C, n);

    // (ii) Multiplication
    multiplyMatrix(A, B, C, n);

    printf("\n2. Matrix Multiplication:\n");
    displayMatrix(C, n);

    // (iii) Zero Matrix
    if (isZeroMatrix(A, n))
        printf("\n3. Matrix A is a Zero Matrix\n");
    else
        printf("\n3. Matrix A is NOT a Zero Matrix\n");

    // (iv) Symmetric Matrix
    if (isSymmetric(A, n))
        printf("\n4. Matrix A is Symmetric\n");
    else
        printf("\n4. Matrix A is NOT Symmetric\n");

    // (v) Determinant
    printf("\n5. Determinant of Matrix A = %.2f\n",
           determinant(A, n));

    // (vi) Transpose
    transpose(A, n);

    printf("\n6. Transpose of Matrix A:\n");
    displayMatrix(A, n);

    // (vii) Eigenvalue and Eigenvector
    printf("\n7. Eigenvalue and Eigenvector:\n");
    eigen(A, n);

    return 0;
}