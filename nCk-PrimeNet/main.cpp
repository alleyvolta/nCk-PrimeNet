//
//  main.cpp
//  nCk-PrimeNet
//
//  Created by Alan Vitullo on 4/1/18.
//  Copyright © 2018 Alan Vitullo. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

void comb(int N, int K)
{
    //
    ofstream outputStream;
    // IMP- CHRONO FILE NAME SCHEME
    outputStream.open("/Users/avitullo/Documents/nCk-(n=16,k=11).txt", ios::out | ios::app);
    if (!outputStream)   // Test for error.
    {
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
            if (i==0) outputStream << "{";
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
        outputStream << "}" << std::endl;
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int main(int argc, const char * argv[]) {
    // IMP- MAIN VARIABLE CHECKING/ HANDLING
    //
    int n = 16, k = 11;
    //
    comb(n, k);
    
    return 0;
}
