#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
using namespace std::chrono;

const string DATA_FILE = "codes.txt";
const string TEST_VALUE = "TESTCODE";
const int NUM_ELEMENTS = 20000;

// Read data into vector
long long read_vector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    ifstream file(DATA_FILE);
    string line;
    while (getline(file, line)) {
        vec.push_back(line);
    }
    file.close();
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Read data into list 
long long read_list(list<string>& lst) {
    auto start = high_resolution_clock::now();
    ifstream file(DATA_FILE);
    string line;
    while (getline(file, line)) {
        lst.push_back(line);
    }
    file.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Read data into set
long long read_set(set<string>& st) {
    auto start = high_resolution_clock::now();
    ifstream file(DATA_FILE);
    string line; 
    while (getline (file, line)) {
        st.insert(line);
    }
    file.close();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Sort vector
long long sort_vector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    sort(vec.begin(), vec.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Sort list
long long sort_list(list<string>& lst) {
    auto start = high_resolution_clock::now();
    lst.sort();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Insert into middle of vector
long long insert_vector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, TEST_VALUE);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Insert into middle of list
long long insert_list(list<string>& lst) {
    auto start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size() / 2);
    lst.insert(it, TEST_VALUE);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Insert into set 
long long insert_set(set<string>& st) { 
    auto start = high_resolution_clock::now(); 
    st.insert(TEST_VALUE);
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Delete from middle of vector
long long delete_vector(vector<string>& vec) {
    auto start = high_resolution_clock::now();
    vec.erase(vec.begin() + vec.size() / 2);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

// Delete from middle of set
long long delete_set(set<string>& st) {
    auto start = high_resolution_clock::now();
    if (!st.empty()) {
        auto it = st.begin();
        advance(it, st.size() / 2);
        st.erase(it);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

int main() {
    

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/