#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <thread>
#include <cmath>
#include <algorithm>

using namespace std;

// The function each thread will run to process its assigned chunk of rows
void process_chunk(const vector<vector<double>>& input, vector<double>& results, size_t start, size_t end, int operation) {
    for (size_t i = start; i < end; ++i) {
        const auto& row = input[i];
        if (row.empty()) {
            results[i] = 0; // Default fallback for empty lines
            continue;
        }

        double res = 0;
        switch (operation) {
            case 1: // Sum
                res = 0;
                for (double val : row) res += val;
                break;
            case 2: // Multiply
                res = 1;
                for (double val : row) res *= val;
                break;
            case 3: // Power (first number ^ second number)
                if (row.size() >= 2) res = pow(row[0], row[1]);
                else res = row[0]; // Not enough numbers, just return the first
                break;
            case 4: // Square Root (of the first number)
                res = sqrt(row[0]);
                break;
        }
        results[i] = res; // Save to the pre-allocated results array (Thread-safe!)
    }
}

int main() {
    string input_filename, output_filename;
    int operation;

    // 1. Get user input
    cout << "Enter input filename (e.g., input.txt): ";
    cin >> input_filename;
    cout << "Enter output filename (e.g., output.txt): ";
    cin >> output_filename;

    cout << "\nSelect an operation:\n";
    cout << "1. Sum (adds all numbers in a row)\n";
    cout << "2. Multiply (multiplies all numbers in a row)\n";
    cout << "3. Power (Base = 1st number, Exponent = 2nd number)\n";
    cout << "4. Square Root (of the 1st number)\n";
    cout << "Selection (1-4): ";
    cin >> operation;

    // 2. Read the input file
    ifstream infile(input_filename);
    if (!infile) {
        cerr << "Error: Could not open input file!\n";
        return 1;
    }

    vector<vector<double>> input_data;
    string line;
    while (getline(infile, line)) {
        vector<double> row;
        stringstream ss(line);
        double num;
        while (ss >> num) {
            row.push_back(num);
        }
        if (!row.empty()) {
            input_data.push_back(row);
        }
    }
    infile.close();

    size_t total_rows = input_data.size();
    if (total_rows == 0) {
        cout << "Input file is empty or contains no valid numbers.\n";
        return 0;
    }

    // Pre-allocate the results array so threads don't trip over each other
    vector<double> results(total_rows, 0.0);

    // 3. Determine number of threads (Logical cores - 1, minimum of 1)
    unsigned int logical_cpus = thread::hardware_concurrency();
    int num_threads = max(1, (int)logical_cpus - 1);
    
    // Don't create more threads than we have rows!
    num_threads = min((int)total_rows, num_threads); 

    cout << "\nUsing " << num_threads << " thread(s) to process " << total_rows << " rows...\n";

    // 4. Split the work and launch threads
    vector<thread> threads;
    size_t chunk_size = total_rows / num_threads;
    size_t remainder = total_rows % num_threads;
    size_t current_start = 0;

    for (int i = 0; i < num_threads; ++i) {
        size_t current_end = current_start + chunk_size + (i < remainder ? 1 : 0);
        
        // Spawn the thread
        threads.push_back(thread(process_chunk, cref(input_data), ref(results), current_start, current_end, operation));
        
        current_start = current_end;
    }

    // 5. Wait for all threads to finish their work
    for (auto& t : threads) {
        t.join();
    }

    // 6. Write results to output file
    ofstream outfile(output_filename);
    if (!outfile) {
        cerr << "Error: Could not open output file for writing!\n";
        return 1;
    }

    for (double res : results) {
        outfile << res << "\n";
    }
    outfile.close();

    cout << "Done! Results written to " << output_filename << "\n";
    return 0;
}