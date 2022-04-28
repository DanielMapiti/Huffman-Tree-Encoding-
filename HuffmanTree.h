#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanNode.h"
#include <memory>
#include <unordered_map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


class HuffmanTree{
    private:
        shared_ptr<HuffmanNode> root;
        unordered_map<char, int> map;
        priority_queue<HuffmanNode,vector<HuffmanNode>, Compare> pq;
        unordered_map<char, string> codeTable;

    public:
        HuffmanTree();
        ~HuffmanTree();

        void createMap(string inputFile);
        void buildTree();
        void buildCodeTable(HuffmanNode* x,string bit);
        string buffer(string in);
        void compress(string inputFile, string outputFile);

};



#endif