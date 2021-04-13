#pragma once
void conv2d(double ** res, double ** image, double ** kernel, int n, int k);

void conv2d(double ** res, double ** image, double ** kernel, int n, int k) {
 
    float sum = 0.0;
    #pragma acc init
    // #pragma acc kernels copy(image[0:n][0:n]), copy(kernel[0:n][0:n]), copyout(res[0:n][0:n])
    #pragma acc loop independent//t vector(16)
    for (int y = 1; y < n - 1; y++) {
        #pragma acc loop independent// vector(16)
        for (int x = 1; x < n - 1; x++) {
            sum = 0.0;
            #pragma acc loop independent// vector(16)
            for(int i = -1; i <= 1;i++){
                #pragma acc loop independent// vector(16)
                for(int j = -1; j <=1; j++){
                    sum += kernel[j+1][i+1]*image[y - j][x - i];
                }
            }
            res[y][x] = sum;
        }
    }
}
