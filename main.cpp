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

// Delete from middle of list
long long delete_list(list<string>& lst) {
    auto start = high_resolution_clock::now();
    auto it = lst.begin();
    advance(it, lst.size() / 2);
    lst.erase(it);
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

// Display results table
void display_results(const vector<string>& operations, 
                    const vector<long long>& vector_times,
                    const vector<long long>& list_times,
                    const vector<long long>& set_times) {
    cout << left << setw(12) << "Operation" 
         << setw(12) << "Vector" 
         << setw(12) << "List" 
         << "Set" << endl;
    cout << string(48, '-') << endl;

    for (size_t i = 0; i < operations.size(); i++) {
        cout << left << setw(12) << operations[i];
        cout << setw(12) << vector_times[i];
        cout << setw(12) << list_times[i];
        if (set_times[i] == -1) {
            cout << "-1" << endl;
        } else {
            cout << set_times[i] << endl;
        }
    }
}

int main() {
    cout << "Data Structures Race - Lab 25\n";
    cout << "=============================\n\n";
    
    // Storage for results
    vector<string> operations;
    vector<long long> vector_times, list_times, set_times;
    
    cout << "\n*** Race 1: READING ***\n";
    vector<string> vec1;
    list<string> lst1;
    set<string> st1;
    
    long long t1 = read_vector(vec1);
    long long t2 = read_list(lst1);
    long long t3 = read_set(st1);
    
    operations.push_back("Read");
    vector_times.push_back(t1);
    list_times.push_back(t2);
    set_times.push_back(t3);
    
    cout << "Vector: " << t1 << " microseconds\n";
    cout << "List:   " << t2 << " microseconds\n";
    cout << "Set:    " << t3 << " microseconds\n\n";
    
    cout << "\n*** Race 2: SORTING ***\n";
    vector<string> vec2 = vec1;
    list<string> lst2 = lst1;
    
    long long t4 = sort_vector(vec2);
    long long t5 = sort_list(lst2);
    
    operations.push_back("Sort");
    vector_times.push_back(t4);
    list_times.push_back(t5);
    set_times.push_back(-1);  // Set is already sorted
    
    cout << "Vector: " << t4 << " microseconds\n";
    cout << "List:   " << t5 << " microseconds\n";
    cout << "Set:    -1 (already sorted)\n\n";
    
    cout << "\n*** Race 3: INSERTING ***\n";
    vector<string> vec3 = vec2;
    list<string> lst3 = lst2;
    set<string> st3 = st1;
    
    long long t6 = insert_vector(vec3);
    long long t7 = insert_list(lst3);
    long long t8 = insert_set(st3);
    
    operations.push_back("Insert");
    vector_times.push_back(t6);
    list_times.push_back(t7);
    set_times.push_back(t8);
    
    cout << "Vector: " << t6 << " microseconds\n";
    cout << "List:   " << t7 << " microseconds\n";
    cout << "Set:    " << t8 << " microseconds\n\n";
    
    cout << "\n*** Race 4: DELETING ***\n";
    vector<string> vec4 = vec2;  // Use pre-insert state
    list<string> lst4 = lst2;
    set<string> st4 = st1;
    
    long long t9 = delete_vector(vec4);
    long long t10 = delete_list(lst4);
    long long t11 = delete_set(st4);
    
    operations.push_back("Delete");
    vector_times.push_back(t9);
    list_times.push_back(t10);
    set_times.push_back(t11);
    
    cout << "Vector: " << t9 << " microseconds\n";
    cout << "List:   " << t10 << " microseconds\n";
    cout << "Set:    " << t11 << " microseconds\n\n";
    
    cout << "\n*** FINAL RESULTS ***\n";
    display_results(operations, vector_times, list_times, set_times);
    
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/