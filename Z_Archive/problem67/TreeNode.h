#ifndef TREENODE_H
#define TREENODE_H

class TreeNode
{
public:
	TreeNode();
	~TreeNode();
	
	void setWeight(int weight);
	void setMaxWeight(int mWeight);
	void setLeft(TreeNode * l);
	void setRight(TreeNode * r);
	void setNextSibling(TreeNode * n);
	int getWeight();
	int getMaxWeight();
	TreeNode * getLeft();
	TreeNode * getRight();
	TreeNode * getNextSibling();

private:
	int nodeWeight;
	int maxWeight;
	TreeNode * left;
	TreeNode * right;
	TreeNode * nextSibling;
};

#endif
