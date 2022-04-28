#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "string.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){

    if (argc<3){
        cout<<"Something is wrong\n";
        return 0;
    }
    string input = string(argv[1])+".txt";
    string output = string(argv[2]);
    HuffmanTree treeobj;
    treeobj.createMap(input);
    treeobj.buildTree();
    treeobj.compress(input,output);
    return 0;

}