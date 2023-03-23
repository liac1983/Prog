#include <iostream>
using namespace std;

struct time_of_day {
  unsigned char h; // hours
  unsigned char m; // minutes
};
struct interval {
  time_of_day start; // start time
  time_of_day end;   // end time
};

//Prints the results
void print(int d, const interval il){
    cout << d << "["
        << (int) il.start.h << ':' << (int) il.start.m << ','
        << (int) il.end.h << ':' << (int) il.end.m << "[\n";
}

// Compar two times of the day
bool earlier_or_equal(time_of_day t1, time_of_day t2){
    return t1.h < t2.h || (t1.h == t2.h && t1.m <= t2.m);
}

//Searches for intervals containing the time of day
int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (earlier_or_equal(a[i].start, t) && !earlier_or_equal(a[i].end,t)){
            //t is in the interval
            c++;
            if(c == 1){
                //first interval found
                u = a[i];
            }else{
                //adjust union interval
                if(earlier_or_equal(a[i].start, u.start)){
                    u.start = a[i].start;
                }
                if (earlier_or_equal(u.end, a[i].end)){
                    u.end = a[i].end;
                }
            }
        }
    }
    if (c == 0){
        u = {t, t };
    }
    return(u.end.h - u.start.h) * 60 + u.end.m - u.start.m;
}

int main(){
	
const int n = 5;
const time_of_day t = { 15, 15 };
interval a[n] { { { 12, 30 }, { 14, 30 } },
                { { 14, 30 }, { 15, 30 } },
                { { 15, 10 }, { 16, 10 } },
                { {  9, 30 }, { 15, 15 } },
                { {  9, 45 }, { 15, 16 } } };
interval u;
int d = search_intervals(t, a, n, u);
print(d, u);
}
