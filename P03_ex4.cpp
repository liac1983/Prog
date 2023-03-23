#include <iostream>
using namespace std;

// Codifica os inteiros dentro da string
void int_to_string(int n, char str[], int& pos){
    int d = 0;  // digitos em formato decimal representados em n
    for (int i = n; i != 0; i = i / 10){
        d++;
    }
    for (int i = d, j = n; i > 0; i--){
        str[pos + i - 1] = '0' + j % 10;
        j = j / 10;
    }
    pos = pos + d;
}

// RLE endoding for n repetitions of char c
void rleEncodeAux(int n, char c, char rle[], int& pos){
    if (n == 0){
        return;
    }
    int_to_string(n, rle, pos);
    rle[pos] = c;pos++;
}

//RLE codifica a C-string
void rleEncode(const char str[], char rle[]){
    int i = 0;
    int j = 0;
    char c= 0;
    int n = 0;
    while (str[i] != '\0'){
        if (str[i] == c){
            n++;
        } else {
            rleEncodeAux(n, c, rle, j);
            n = 1;
            c = str[i];
        }
        i++;
    }
    rleEncodeAux(n, c, rle, j);
    rle[j] = '\0';
}

int main(){
	
    char rle[3 + 1] = { -1, -1, -1, -1 };
rleEncode("xxxxxxxxxxxxxxxxxxxx", rle);
cout << rle << endl;
}

