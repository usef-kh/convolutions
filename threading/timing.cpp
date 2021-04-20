#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "conv2d.h"
#include <vector>

using namespace std;

int main() {
    
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    
    string filename = "conv2d_timing_threading.csv";
    
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
            

            int n_threads = z;
            std::vector<std::thread> thread_array;
            for (int i = 0; i < n_threads; i++) {
                thread_array.push_back(thread(conv2d, output, image, kernel, n, k, i));
            }

            for (int i = 0; i < n_threads; i++) {
                thread_array[i].join();
            }
                

            end_time = std::chrono::steady_clock::now();        // end time
            
            // end - start
            std::chrono::duration<double> elapsed_time = end_time - start_time;
            
            cout << n << "\t" << k << "\t" << elapsed_time.count() << "\n";
            file << n << "," << k << "," << elapsed_time.count() << "\n";
        }
    }
        
    return 0;
}
