#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "conv2d.h"

using namespace std;

int main() {
    
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    
    string filename = "conv2d_timing_openACC.csv";
    
    ofstream output;
    output << setprecision(20);
    output.open(filename);
    
    output << "n,k,Time (sec)\n";    
    cout << "n\tk\tTime\n";
    

    for (int n = 128; n <= 8192; n *=2) {
        for (int k = 4; k <= n/2; k *=2) {
            
            double ** kernel = new double * [k];
            double ** image = new double * [n];
            double ** res = new double * [n];
            
            for (int i = 0; i < k; i++) {
                kernel[i] = new double[k];
            }
            
            for (int i = 0; i < n; i++) {
                image[i] = new double[n];
                res[i] = new double[n];
            }
            
            for (int y = 0; y < k; y++) {
                for (int x = 0; x < k; x++) {
                    kernel[x][y] = 1/ 9.0;
                }
            }
            
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < n; x++) {
                    if (x % 2 == 0) {
                        image[x][y] = 1.0;
                    } else {
                        image[x][y] = 2.0;
                    }
                    
                    res[x][y] = 0.0;
                }
            }
            
            start_time = std::chrono::steady_clock::now();      // start time
            conv2d(res, image, kernel, n, k);
            end_time = std::chrono::steady_clock::now();        // end time
            
            // end - start
            std::chrono::duration<double> elapsed_time = end_time - start_time;
            
            cout << n << "\t" << k << "\t" << elapsed_time.count() << "\n";
            output << n << "," << k << "," << elapsed_time.count() << "\n";
            
        }
    }
    
    
    return 0;
}
