#include "HuffmanTree.h"
#include "HuffmanNode.h"
#include <unordered_map>
#include <iostream>
#include <fstream>

using namespace std;

HuffmanTree::HuffmanTree(){
    root=nullptr;
}

HuffmanTree::~HuffmanTree()=default;

void HuffmanTree::createMap(string inputFile ){
    ifstream ifs(inputFile.c_str());
    if(ifs.is_open()){
        char character;
        while (ifs.get(character))
        {
            if (map.find(character)!=map.end()){
                map.at(character) +=1;
                
            }
            else{
                map.insert({character, 1});
            }
        }
        ifs.close();
      //  for(auto element: map){
        //    cout<<element.first<<" : "<<element.second<<endl;
        //}
        
    }
    else{
        cout<<"Unable to open file.\n";
    }
}

void HuffmanTree::buildTree(){
    for(auto& n: map){
        pq.push(HuffmanNode(n.first,n.second,nullptr,nullptr));
    }
    while ((int)pq.size()>1)
    {

		shared_ptr<HuffmanNode> l(new HuffmanNode(pq.top().getAlphabet(), pq.top().getFrequency(), pq.top().getLeft(), pq.top().getRight()));
		pq.pop();
		shared_ptr<HuffmanNode> r(new HuffmanNode(pq.top().getAlphabet(), pq.top().getFrequency(), pq.top().getLeft(), pq.top().getRight()));
		pq.pop();
		HuffmanNode p = HuffmanNode(l, r);
		pq.push(p);
    }

    HuffmanNode root=HuffmanNode(pq.top());
    shared_ptr<HuffmanNode>root_ptr(new HuffmanNode(root));
    buildCodeTable(root_ptr.get(),"");
    
}

void HuffmanTree::buildCodeTable(HuffmanNode* x, string bit){
    if(x){buildCodeTable(x->getLeftp(),bit+"0");
    if(x->getAlphabet()!=0){codeTable[x->getAlphabet()]=bit;}
    buildCodeTable(x->getRightp(),bit+"1");
    }
}

string HuffmanTree::buffer(string in){
    string b="";
    ifstream ifs(in);
    while (ifs.is_open()){
        b+=codeTable.at(ifs.get());
    }ifs.close();
    return b;   
}

void HuffmanTree::compress(string inputFile, string outputFile){
    unsigned int chars,bits;
    ofstream ofs;ofs.open(outputFile+".hdr");
    ifstream ifs(inputFile);
    if(ifs.is_open()){
        char c;
        while(ifs.get(c)){
            chars++;
            string b=codeTable[c].c_str();
            bits+=b.length();
        }ifs.close();


    }else{
        cout<<"Unable to open file: "<<inputFile<<endl;
    }

    if(ofs.is_open()){
        ofs<<"Size: "<<codeTable.size()<<endl;
    
    for(auto n:codeTable){ofs<<n.first<<": "<<n.second<<endl;}
    ofs.close();}
    else{cout<<"Unable to open file: "<<outputFile<<endl;}
}

