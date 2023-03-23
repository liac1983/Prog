#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//! Show file contents with line number information and 
//! the '|' character indicating the begining and end of lines.
void print(const std::string& file) {
  ifstream in(file);
  size_t line_nr = 1;
  for (string line; getline(in, line);) {
     cout << line_nr << "|" << line << "|\n";
     line_nr++;
  }
}

// Normalises the contents of input the file into the output file 
void normalise(const string& input_fname, const string&){
    ifstream in(input_file);
    ofstream out(output_file);
    for (string line; getline(in, line);) {
        line.erase(0, line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ')+1);
        for (char& c: line) {
            c = toupper(c);
        }
        if (line.length() > 0) {
            out << line << '\n';
        }
    }
} 

int main() {
    	
normalise("p3_test1.txt", "p3_test1_out.txt");
print("p3_test1_out.txt");
    return 0;
}