#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

//! Show file name and the contents.
void show_file(const string& file) {
  ifstream in(file);
  cout << "==> " << file << " <==\n";
  for (string line; getline(in, line); ) cout << line << '\n';
}

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream in_file(input_fname);
    ofstream out_file(output_fname);
    string line;
    double num;
    for (string line; getline(in_file, line);) {
        if (line[0] != '#') {
            string id = line.substr(0, line.find_first_of(' '));
            line = line.substr(id.length() + 1, line.length());
            istringstream lstream(line);
            vector<double> medianv;
            while(lstream >> num) medianv.push_back(num);
            sort(medianv.begin(), medianv.end());
            int size = medianv.size();
            if (size % 2 != 0) out_file << id << ' ' << fixed << setprecision(1) << medianv[size/2] << endl;
            else out_file << id << ' ' << fixed << setprecision(1) << 0.5*(medianv[size/2-1] + medianv[size/2]) << endl;
        }
    }
}

int main() {
    calc_medians("p5_test1.txt", "p5_test1_out.txt");
show_file("p5_test1_out.txt");
    return 0;
}