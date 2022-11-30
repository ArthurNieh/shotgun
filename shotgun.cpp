#include<iostream>

using namespace std;

const int MaxLength = 1024;

char** DNA_spliter(char* total_sequence, int total_length, int split_num){

}
int* sequence_compare(int** sequences){

}
int* generate_DNA_from_number(int number, int length){
    // A=0 T=1 C=2 G=3
    int* sequence = new int[MaxLength];
    for(int i=length-1;i>=0;i--){
        sequence[i] = number%4;
        number = number/4;
    }
    // print for debug
    for(int i=0;i<length;i++){
        cout<<sequence[i]<<" ";
    }
    return sequence;
}
char* int_to_char(int* input, int length){
    char* output = new char[MaxLength];
    for(int i=0;i<length;i++){
        switch(input[i]%4){
            case 0:
                output[i] = 'A';
                break;
            case 1:
                output[i] = 'T';
                break;
            case 2:
                output[i] = 'C';
                break;
            case 3:
                output[i] = 'G';
                break;
            default :
                cout<<"error"<<endl;
                break;
        } 
    }
    return output;
}
int* char_to_int(char* input, int length){
    int* output = new int[MaxLength];
    for(int i=0;i<length;i++){
        if(input[i]=='A') output[i]=0;
        else if(input[i]=='T') output[i]=1;
        else if(input[i]=='C') output[i]=2;
        else if(input[i]=='G') output[i]=3;
        else cout<<"error char to int"<<endl;
    }
    return output;
}

int main(int argc, char* argv[]){

    // int target_DNA_length;
    // cin >> target_DNA_length;
    // char* target_DNA = new char [target_DNA_length];

    // cin>>target_DNA;
    int k,l;
    cin >> k >>l;
    int* s = generate_DNA_from_number(k,l);
    cout<<endl;
    

    // cout << target_DNA<<endl;

    return 0;
}
