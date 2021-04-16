#include "conv2d.h"
#include <vector>
using namespace std;

int main() {
    
    int k = 6, n = 12;
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
    
    int n_threads = z;
    std::vector<std::thread> thread_array;
    for (int i = 0; i < n_threads; i++) {
        thread_array.push_back(thread(conv2d, output, image, kernel, n, k, i));
    }

    for (int i = 0; i < n_threads; i++) {
        thread_array[i].join();
    }
   
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