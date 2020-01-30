#include <stdio.h>

#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode() 
{
	left = 0;
	right = 0;
	nextSibling = 0;
	nodeWeight = 0;
	maxWeight = 0;
}

TreeNode::~TreeNode()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

void TreeNode::setWeight(int weight)
{
	nodeWeight = weight;
}

void TreeNode::setMaxWeight(int mWeight)
{
	maxWeight = mWeight;
}

void TreeNode::setLeft(TreeNode * l)
{
	left = l;
}

void TreeNode::setRight(TreeNode * r)
{
	right = r;
}

void TreeNode::setNextSibling(TreeNode * n)
{
	nextSibling = n;
}

int TreeNode::getWeight()
{
	return nodeWeight;
}

int TreeNode::getMaxWeight()
{
	return maxWeight;
}

TreeNode * TreeNode::getLeft()
{
	return left;
}

TreeNode * TreeNode::getRight()
{
	return right;
}

TreeNode * TreeNode::getNextSibling()
{
	return nextSibling;
}
