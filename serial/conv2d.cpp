#include <iostream>
#include "conv2d.h"
using namespace std;

// #define k 3
// #define n 10


void init(double ** res, double ** image, double ** kernel, int n, int k);

int main() {
    
    int k = 3, n = 10;
    double ** kernel = new double * [k];
    double ** image = new double * [n];
    double ** res = new double * [n];
   
    init(res, image, kernel, n, k);
    
    cout << "Kernel" << endl;
    for (int y = 0; y < k; y++) {
        for (int x = 0; x < k; x++) {
            cout << kernel[x][y] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Image" << endl;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << image[x][y] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Result Inital Array" << endl;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << res[x][y] << " ";
        }
        cout << endl;
    }
    
    conv2d(res, image, kernel, n, k);
    
        cout << "Kernel" << endl;
    for (int y = 0; y < k; y++) {
        for (int x = 0; x < k; x++) {
            cout << kernel[x][y] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Image" << endl;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << image[x][y] << " ";
        }
        cout << endl;
    }
    
    cout << endl << "Result Array" << endl;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cout << res[x][y] << " ";
        }
        cout << endl;
    }
    
    
    
    return 0;
}






// void init(double ** res, double ** image, double ** kernel, int n, int k){
    
//      for (int i = 0; i < k; i++) {
//         kernel[i] = new double[k];
//     }
    
//     for (int i = 0; i < n; i++) {
//         image[i] = new double[n];
//         res[i] = new double[n];
//     }
    
//      //  initialize 2D Kernel
//     for (int y = 0; y < k; y++) {
//         for (int x = 0; x < k; x++) {
//             kernel[x][y] = 1/ 9.0;
//         }
//     }
    
//     //  initialize 2D images
//     for (int y = 0; y < n; y++) {
//         for (int x = 0; x < n; x++) {
//             if (x % 2 == 0) {
//                 image[x][y] = 1.0;
//             } else {
//                 image[x][y] = 2.0;
//             }
            
//             res[x][y] = 0.0;
//         }
//     }
    
    
    
// }
