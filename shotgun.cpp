#include<iostream>
#include<string>
#include<cmath>
using namespace std;

const int MaxLength = 1024;

void get_DNA_parts(char** dna_parts, int num, int* dna_part_length, int target_dna_length); //user input parts of DNA sequence
void print_DNA_parts(char** dna_parts, int num);
void get_target_DNA(char* sequence, int length);
void print_DNA_sequence(char* sequence, int target_dna_length);
void print_DNA_sequence(int* sequence, int length);

char** DNA_spliter(char* total_sequence, int total_length, int split_num);
int* sequence_compare(char** sequences, int part_dna_num, int* part_dna_length, int target_DNA_length);
int* generate_DNA_from_number(int number, int length);// for any decimal number, convert it into a Quaternary(4進位) number and see it as a DNA sequence
char* int_to_char(int* input, int length);
int* char_to_int(char* input, int length);

int main(int argc, char* argv[]){

    int target_DNA_length;
    cout << "How long is the target DNA?"<<endl;
    cin >> target_DNA_length;
    char* target_DNA = new char [target_DNA_length];
    // get_target_DNA(target_DNA, target_DNA_length);

    int part_DNA_number;
    cout << "How many part DNA are there?"<<endl;
    cin >> part_DNA_number;
    cin.ignore();
    char** part_DNA = new char* [part_DNA_number];
    for(int i=0;i<part_DNA_number;i++){
        part_DNA[i] = new char [target_DNA_length];
    }
    //new
    int* part_DNA_length = new int[part_DNA_number];

    get_DNA_parts(part_DNA, part_DNA_number, part_DNA_length, target_DNA_length);
    // print_DNA_parts(part_DNA, part_DNA_number);
        
    target_DNA = int_to_char( sequence_compare(part_DNA, part_DNA_number, part_DNA_length, target_DNA_length), target_DNA_length);
    print_DNA_sequence(target_DNA, target_DNA_length);

    
    // int k,l;
    // cin >> k >>l;
    // int* s = generate_DNA_from_number(k,l);
    
    

    // cout << target_DNA<<endl;

    return 0;
}


// Functions

void get_DNA_parts(char** dna_parts, int num, int* dna_part_length, int target_dna_length){
    cout<<"Please input the part DNA sequences in ATCG:"<<endl;
    for(int i=0;i<num;i++){
        string str;
        getline(cin, str);
        int count = 0;
        for(int j=0;j<str.length();j++){
            dna_parts[i][j] = str[j];
            count++;
        }
        dna_part_length[i] = count;
    }
    return;
}
void print_DNA_parts(char** dna_parts, int num){
    for(int i=0;i<num;i++){
        cout<<dna_parts[i]<<endl;
    }
    return;
}
void get_target_DNA(char* sequence, int length){
    string str;
    cin.ignore();
    cout<<"Please input the target DNA sequence in ATCG:"<<endl;
    getline(cin, str);
    for(int i=0;i<length;i++){
        sequence[i] = str[i];
    }
    return;
}
void print_DNA_sequence(char* sequence, int target_dna_length){
    for(int i=0;i<target_dna_length;i++){
        cout << sequence[i];
    }
    cout<<endl;
    return;
}
void print_DNA_sequence(int* sequence, int length){
    char* char_sequence = int_to_char(sequence, length);
    cout << char_sequence<<endl;
    return;
}
// char** DNA_spliter(char* total_sequence, int total_length, int split_num){
//     return;
// }

int* sequence_compare(char** dna_parts, int part_dna_num, int* part_dna_length, int target_DNA_length){
    
    for(int i=0;i<(int)(pow(4,target_DNA_length));i++){
        bool check = 1;// check whether the guess sequence is right

        int* guess_sequence = generate_DNA_from_number(i, target_DNA_length);
        // print_DNA_sequence(guess_sequence, target_DNA_length);
        
        // check whether each part DNA fit guess sequence
        for(int j=0;j<part_dna_num;j++){
            int* part_dna_int = char_to_int(dna_parts[j], target_DNA_length);
            bool part_dna_fit = 0;

            for(int index_on_guess_sequence = 0; index_on_guess_sequence < target_DNA_length - part_dna_length[j]+1; index_on_guess_sequence++){
                int index_on_part_dna = 0;
                bool check_for_one_part_dna = 1;

                while(part_dna_int[index_on_part_dna] != -1){
                    if(part_dna_int[index_on_part_dna] == guess_sequence[index_on_guess_sequence + index_on_part_dna]){
                        index_on_part_dna++;
                        continue;
                    }
                    else{
                        check_for_one_part_dna = 0;
                        break;
                    }
                }
                if(check_for_one_part_dna){
                    part_dna_fit = 1;
                    break;
                }
                // else if(index_on_guess_sequence + index_on_part_dna == target_DNA_length-1){
                //     part_dna_fit = 0;
                //     break;
                // }
                else{
                    continue;
                }
            }

            if(!part_dna_fit){
                check = 0;
                break;
            }

        }
        if(check){
            return guess_sequence;
        }

    }

    cout<<"NO DNA sequence fit";
    exit(0);

}
// for any decimal number, convert it into a Quaternary(4進位) number and see it as a DNA sequence
int* generate_DNA_from_number(int number, int length){
    // A=0 T=1 C=2 G=3
    if(number>=(int)(pow(4,length)) || number<0){
        cout<<"error generating DNA from number!"<<endl;
    }
    int* sequence = new int[MaxLength];
    for(int i=length-1;i>=0;i--){
        sequence[i] = number%4;
        number = number/4;
    }
    // print for debug
    // for(int i=0;i<length;i++){
    //     cout<<sequence[i]<<" ";
    // }
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
            case -1:
                cout<<"encounter -1"<<endl;
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
        else output[i]=-1;
    }
    return output;
}