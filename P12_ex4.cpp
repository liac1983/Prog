#include <map>
#include <list>
#include <string>
#include <iostream>
#include <climits>
using namespace std;

string cat_keys(list<map<string, unsigned >> lst) {
    unsigned minvalue = UINT_MAX;
    string result;
    for(auto currmap: lst) {
        for(auto kv: currmap) {
            if(kv.second<minvalue) {
                minvalue = kv.second;
                result="";
                for(auto kv: currmap) {
                    result.append(kv.first);
                }
            }
        }
    }
    return result;
}

int main() {
    list<map<string, unsigned>> m2 = {
  { {"s1", 13}, {"s2", 2} } };
    cout << cat_keys(m2) << endl;
    return 0;
}