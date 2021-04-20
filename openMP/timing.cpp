#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "conv2d.h"

using namespace std;

int main() {
    
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    
    string filename = "conv2d_timing_openMP.csv";
    
    ofstream file;
    file << setprecision(20);
    file.open(filename);
    
    file << "n,k,Time (sec)\n";    
    cout << "n\tk\tTime\n";

    for (int n = 128; n <= 4096; n *= 2) {
        for (int k = 3; k <= 20; k += 2) {

            int z = n - k;

            double ** kernel = new double * [k];
            double ** image = new double * [n];
            double ** output = new double * [z]; 

            init(output, image, kernel, n, k);
            
            start_time = std::chrono::steady_clock::now();      // start time
            conv2d(output, image, kernel, n, k);
            end_time = std::chrono::steady_clock::now();        // end time
            
            // end - start
            std::chrono::duration<double> elapsed_time = end_time - start_time;
            
            cout << n << "\t" << k << "\t" << elapsed_time.count() << "\n";
            file << n << "," << k << "," << elapsed_time.count() << "\n";
        }
    }
        
    return 0;
}
