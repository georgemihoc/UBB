#include <fstream>
#include <string>
#include <queue>
#define MAX_CHAR 255
using std::string;
using std::vector;

std::ifstream f("date.in");
std::ofstream g("date.out");

struct Nod{
    char data;  //character
    int freq;   //character frequence

    Nod* left, *right; //left and right child

    Nod(char data, int freq){
        this->left = this->right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct Comp{
    bool operator()(const Nod*a, const Nod*b){
        return a->freq > b-> freq;
    }
};

string sir;
int freq[MAX_CHAR];
std::priority_queue<Nod*, vector<Nod*>, Comp> p_queue; //priority queue

void citire(string& sir){
    string citire;
    if(f.is_open()){
        while(!f.eof()){
            std::getline(f, citire);
            sir += citire;
        }
    }
}

void frecventa(const string& str, int freq[]){
    for(int i = 0; i<256; i++){
        freq[i] = 0;
    }
    for(const auto& elem : str){
        freq[int(elem)] ++;
    }
}

void print_codes(Nod* root,  string str){
    if(!root){
        return;
    }
    if(root->data != '$'){
        g << root -> data << ": " << str << '\n';
    }
    print_codes(root->left, str + "0");
    print_codes(root->right, str + "1");
}

void huffman(const string& str, std::priority_queue<Nod*, vector<Nod*>, Comp> pq){
    frecventa(str, freq);
    for(int i = 0; i<256; i++){
        if(freq[i] != 0){
            pq.push(new Nod(char(i), freq[i]));
        }
    }

    while(pq.size() != 1){
        auto left = pq.top();
        pq.pop();

        auto right = pq.top();
        pq.pop();
        auto top = new Nod('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    print_codes(pq.top(), "");
}
int main(){
    citire(sir);
    huffman(sir, p_queue);
    return 0;
}