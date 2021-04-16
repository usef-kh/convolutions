#pragma once


void conv2d(double ** output, double ** input, double ** kernel, int N, int K);
void init(double ** res, double ** image, double ** kernel, int n, int k);

void conv2d(double ** output, double ** input, double ** kernel, int N, int K)
{

	// Fill output matrix: rows and columns are i and j respectively
	for (int i = 0; i < N - K; i++)
	{
		for (int j = 0; j <  N - K; j++)
		{
		    double convolute = 0;
			// Kernel rows and columns are k and l respectively
			for (int k = 0; k < K; k++)
			{
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
    
    for (int i = 0; i < k; i++){
        kernel[i] = new double[k];
    }

    for (int i = 0; i < n; i++) {
        image[i] = new double[n];
    }

    for(int i = 0; i < n; i++)  {
        output[i] = new double[n];
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
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {

            output[x][y] = 0.0;
        }
    }
}
