#pragma once
void conv2d(double ** res, double ** image, double ** kernel, int n, int k);

void conv2d(double ** res, double ** image, double ** kernel, int n, int k) {
 
    float sum = 0.0;
    
    for (int y = 1; y < n - 1; y++) {
        for (int x = 1; x < n - 1; x++) {
            sum = 0.0;
            
            for(int i = -1; i <= 1;i++){
                for(int j = -1; j <=1; j++){
                    sum += kernel[j+1][i+1]*image[y - j][x - i];
                }
            }
            res[y][x] = sum;
        }
    }
}