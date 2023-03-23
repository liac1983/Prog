#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cfloat>

using namespace std;

//! Show file name and its contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

bool average(const string& input_fname, const string& output_fname) {
    //open file 
    ifstream in( input_fname);
    if (in.fail())    // failed!
        return false;
    ofstream out(output_fname);
    int lines = 0;
    for (string line; getline(in, line); ) { 
        lines ++;
        istringstream iss(line);
        double x;
        double soma=0;
        int values=0;        
        while (iss >> x) {
            soma += x;
            values++;
        }
        out << fixed << setprecision(3) << soma/values << endl;
    }
    out << "lines=" << lines;
    return true;
}

int main() {
    	
if (average("p1a-1.txt", "p1a-1_out.txt"))
  show_file("p1a-1_out.txt");
    return 0;
}