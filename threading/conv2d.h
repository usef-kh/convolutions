#pragma once
#include <thread>

void conv2d(double ** output, double ** input, double ** kernel, int N, int K);
void init(double ** res, double ** image, double ** kernel, int n, int k);

void conv2d(double ** output, double ** input, double ** kernel, int N, int K)
{
	// Fill output matrix: rows and columns are i and j respectively
	
    for (int i = 0; i < N - K; i++)
	{
		// #pragma acc loop independent
        for (int j = 0; j <  N - K; j++)
		{
		    double convolute = 0;
			// Kernel rows and columns are k and l respectively
			// #pragma acc loop independent
            for (int k = 0; k < K; k++)
			{
				// #pragma acc loop independent
                for (int l = 0; l < K; l++)
				{
					// Convolute here.
					convolute += kernel[k][l] * input[i + k][j + l];
				}
			}
			output[i][j] = convolute; // Add result to output matrix.
		}
	}
}

void init(double ** output, double ** image, double ** kernel, int n, int k){
    
    int z = n - k;

    for (int i = 0; i < k; i++){
        kernel[i] = new double[k];
    }

    for (int i = 0; i < n; i++) {
        image[i] = new double[n];
    }

    for(int i = 0; i < z; i++)  {
        output[i] = new double[z];
    }

     //  initialize 2D Kernel
    for (int y = 0; y < k; y++) {
        for (int x = 0; x < k; x++) {
           if (x % 2 == 0) {
                kernel[x][y] = 1.0/9;
            } else {
                kernel[x][y] = 2.0/9;
            }
            
        }
    }
    
    //  initialize 2D images
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (x % 2 == 0) {
                image[x][y] = 1.0;
            } else {
                image[x][y] = 2.0;
            }
        }
    }
    
    //  initialize 2D output
    for (int y = 0; y < z; y++) {
        for (int x = 0; x < z; x++) {
            output[x][y] = 0.0;
        }
    }
}
