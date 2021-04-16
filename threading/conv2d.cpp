#include <iostream>
#include "conv2d.h"
using namespace std;

int main() {
    
    int k = 4, n = 7;
    int z = n - k;
    double ** kernel = new double * [k];
    double ** image = new double * [n];
    double ** output = new double * [z];
   
    init(output, image, kernel, n, k);
    
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
    for (int y = 0; y < z; y++) {
        for (int x = 0; x < z; x++) {
            cout << output[x][y] << " ";
        }
        cout << endl;
    }
    
    conv2d(output, image, kernel, n, k);
    
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
    for (int y = 0; y < z; y++) {
        for (int x = 0; x < z; x++) {
            cout << output[x][y] << " ";
        }
        cout << endl;
    }
    
    return 0;
}