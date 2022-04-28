#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>

using namespace std;



class HuffmanNode{
    private:
        char alphabet;
        int frequency;
        shared_ptr<HuffmanNode> left;
        shared_ptr<HuffmanNode> right;

    public:

        HuffmanNode();
        ~HuffmanNode();
        HuffmanNode(char a, int f);
        HuffmanNode(char a, int f, shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r);
        HuffmanNode(const HuffmanNode & rhs);
        HuffmanNode(HuffmanNode && rhs);
        HuffmanNode & operator=(const HuffmanNode & rhs);
        HuffmanNode & operator=(HuffmanNode && rhs);
        HuffmanNode(shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r);
        

        //Get and set
        char getAlphabet() const;
        int getFrequency() const;
        shared_ptr<HuffmanNode> getLeft() const;
        shared_ptr<HuffmanNode> getRight() const;
        void setAlphabet(char a);
        void setFrequency(int f);
        void setRight(shared_ptr<HuffmanNode> r);
        void setLeft(shared_ptr<HuffmanNode> l);
        HuffmanNode* getLeftp() ;
        HuffmanNode* getRightp() ;

  
};

class Compare {
    public:
        bool operator()(const HuffmanNode a, const HuffmanNode b){
           
            return (a.getFrequency() >= b.getFrequency() ? true:false);
        }
};

#endif