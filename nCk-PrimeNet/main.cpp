//  ***********************************************************************
//  main.cpp
//  nCk-PrimeNet
//
//  Created by Alan Vitullo on 4/1/18.
//  Copyright © 2018 Alan Vitullo. All rights reserved.
//  ***********************************************************************

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void comb(int N, int K)
{
    //
    ofstream outputStream;
    string file_location = "/Users/avitullo/Documents/PrimeNet/Labels/";
    string filename = "nCk_n(";
    string log_file = "/Users/avitullo/Documents/PrimeNet/Labels/input_log.txt";
    filename.append(to_string(N));
    filename.append(")");
    filename.append(",k(");
    filename.append(to_string(K));
    filename.append(").txt");
    file_location.append(filename);
    //
    outputStream.open(file_location);
    if (!outputStream) {  // Test for error.
        std::cerr << "Error opening output file:\n";
        exit(1);
    }
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
    int count =0;
    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            
            //
            if (bitmask[i]) {
                outputStream << i;
                count++;
                //
                if (count<K) outputStream << " ";
                //
                if (count==K) count =0;

            }
            
        }
        outputStream << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
    //
    outputStream.close();
    //
    outputStream.open(log_file, ios::out | ios::app);
    if (!outputStream) {  // Test for error.
        std::cerr << "Error opening output file:\n";
        exit(1);
    }
    outputStream << filename << endl;
    outputStream.close();
}

int main(int argc, const char * argv[]) {
    // IMP- MAIN VARIABLE CHECKING/ HANDLING
    //
    int MAX = 16;
    

        for (int k=1; k<=MAX; k++) {
            //
            comb(MAX, k);
        }
    
    
    return 0;
}
