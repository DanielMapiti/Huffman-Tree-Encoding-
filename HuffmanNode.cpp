#include "HuffmanNode.h"

using namespace std;



HuffmanNode::HuffmanNode(){
    alphabet=0;
    frequency=0;
    left=nullptr;
    right=nullptr;
}


HuffmanNode::HuffmanNode(char a, int f, shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r): alphabet(a), frequency(f), left(l), right(r){}

HuffmanNode::HuffmanNode(char a, int f){
    alphabet=a;
    frequency=f;
    left=nullptr;
    right=nullptr;
}

HuffmanNode::~HuffmanNode(){

}



HuffmanNode::HuffmanNode (const HuffmanNode & rhs) //copy constructer
{
	alphabet = rhs.getAlphabet();
	frequency = rhs.getFrequency();
	left = rhs.getLeft();
	right = rhs.getRight();
}

HuffmanNode::HuffmanNode (HuffmanNode && rhs) //move constructer
{
	alphabet = rhs.getAlphabet();
	this->frequency = rhs.getFrequency();
    rhs.setFrequency(-1);
	left = rhs.getLeft();
    rhs.setLeft(nullptr);
	right = rhs.getRight();
    rhs.setRight(nullptr);
}

HuffmanNode& HuffmanNode::operator=(const HuffmanNode & rhs) //Copy Assignment Operators
{
	if(this != &rhs)
	{
		alphabet = rhs.getAlphabet();
		frequency = rhs.getFrequency();
		left = rhs.getLeft();
		right = rhs.getRight();
	}
	return *this; // Return a reference to the current object.

}

HuffmanNode & HuffmanNode::operator=(HuffmanNode && rhs) //Move Assignment Operators
{
	if(this != &rhs)
	{
		alphabet = move(rhs.getAlphabet());
		frequency = rhs.getFrequency();
        rhs.setFrequency(-1);
		left = rhs.getLeft();
        rhs.setLeft(nullptr);
		right = rhs.getRight();
        rhs.setRight(nullptr);

	}

	return *this; // Return a reference to the current object.

}



char HuffmanNode::getAlphabet() const{
    return alphabet;
}

int HuffmanNode::getFrequency() const{
    return frequency;
}

void HuffmanNode::setAlphabet(char a){
    alphabet =a;
}

void HuffmanNode::setFrequency(int f){
    frequency=f;
}

void HuffmanNode::setLeft(shared_ptr<HuffmanNode> l){
	left = move(l);
}

void HuffmanNode::setRight(shared_ptr<HuffmanNode> r){
	right = move(r);
}

shared_ptr<HuffmanNode> HuffmanNode::getLeft() const{
    return left;
}
shared_ptr<HuffmanNode> HuffmanNode::getRight() const{
    return right;
}
HuffmanNode* HuffmanNode::getLeftp() {
    return left.get();
}
HuffmanNode* HuffmanNode::getRightp() {
    return right.get();
}

HuffmanNode::HuffmanNode(shared_ptr<HuffmanNode> l, shared_ptr<HuffmanNode> r){
	left = l;
	right = r;
	alphabet = '\0';
	frequency = l->getFrequency() + r->getFrequency();
}
