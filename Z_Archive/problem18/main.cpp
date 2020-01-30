#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::ifstream;

const int MAX_CHARS_PER_LINE = 2048;
const int MAX_TOKENS_PER_LINE = 150;
const char* const DELIMITER = " ";

int main() 
{
	TreeNode * rootNode = new TreeNode();
	ifstream fin;
	fin.open("triangle.txt");
	static int lineNum = 0;
	while (!fin.eof())
	{
		char buf[MAX_CHARS_PER_LINE];
		static TreeNode * lastTreeNodes[MAX_TOKENS_PER_LINE]={};
		fin.getline(buf, MAX_CHARS_PER_LINE);

		int n = 0;

		const char * token[MAX_TOKENS_PER_LINE] = {};

		token[0] = strtok(buf, DELIMITER);

		if (token[0])
		{
			for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
			{
				token[n] = strtok(0, DELIMITER);
				if (!token[n]) break;
			}
		}

		if (lineNum == 0)
		{
			rootNode->setWeight(atoi(token[0]));
			rootNode->setMaxWeight(atoi(token[0]));
			lastTreeNodes[0] = rootNode;
		}
		else
		{
			// Process tokens
			for (int i = 0; i < n - 1; i++) // n = #of tokens
			{
				//cout << i << " / " << n - 1 << endl;
				TreeNode * newTreeNode = new TreeNode();
				newTreeNode->setWeight(atoi(token[i]));
				newTreeNode->setMaxWeight(
					atoi(token[i]));

				// Set left
				lastTreeNodes[i]->setLeft(newTreeNode);

				// Set right (except right-most)
				if (i != 0)
				{
					lastTreeNodes[i-1]->setRight(
						lastTreeNodes[i]->
						getLeft());
				}

				// Set right for rightmost
				if (i == n-2)
				{
					TreeNode * newTreeNode2 = 
						new TreeNode();
					newTreeNode2->setWeight(
						atoi(token[i+1]));
					newTreeNode2->setMaxWeight(
						atoi(token[i+1]));
					lastTreeNodes[i]->setRight(
						newTreeNode2);
					lastTreeNodes[i+1] = lastTreeNodes[i]->getRight();
				}
				//lastTreeNodes[i] = lastTreeNodes[i]->getLeft();
			}
			// Reset the lastTreeNodes.
			for (int i = 0; i < n-1; i++)
			{
				lastTreeNodes[i] = lastTreeNodes[i]->getLeft();
				if (!lastTreeNodes[i+1])
				{
					break;
				}
			}

			// Set siblings
			for (int i = 0; i < MAX_TOKENS_PER_LINE; i++)
			{
				if (lastTreeNodes[i+1])
				{
					lastTreeNodes[i]->setNextSibling
						(lastTreeNodes[i+1]);
				}
				else
				{
					break;
				}
			}
		}
		lineNum++;
	}
///*
	while (1)
	{
		static TreeNode * currNode = rootNode;
		if (currNode->getLeft())
		{
			cout << currNode->getWeight() << endl;
			currNode = currNode->getLeft();
		}
		else
		{
			cout << currNode->getWeight() << endl;
			break;
		}
	}
//*/

	// Now, do the real analysis.
	// Should run in nlog(n) time....
	TreeNode * currLeftMost = rootNode;
	TreeNode * currNode = currLeftMost;
	for (int i = 0; i < lineNum - 2; i++)
	{
		while(currNode)
		{
			cout << currNode->getWeight() << endl;
			int candidateLeftMax = currNode->getMaxWeight()
				+ currNode->getLeft()->getWeight();
			if (candidateLeftMax >
				currNode->getLeft()->getMaxWeight())
			{
				currNode->getLeft()->setMaxWeight(
					candidateLeftMax);
			}
			//cout << currNode->getRight() << endl;
			int candidateRightMax = currNode->getMaxWeight()
				+ currNode->getRight()->getWeight();
			if (candidateRightMax >
				currNode->getRight()->getMaxWeight())
			{
				currNode->getRight()->setMaxWeight(
					candidateRightMax);
			}
			currNode = currNode->getNextSibling();
		}
		if (currLeftMost)
		{
			currLeftMost = currLeftMost->getLeft();
			currNode = currLeftMost;
		}
		if (i == lineNum - 3)
		{
			int finalVal = 0;
			while (currNode)
			{
				cout << currNode->getMaxWeight() << endl;
				if (currNode->getMaxWeight() > finalVal)
				{
					finalVal = currNode->
						getMaxWeight();
				}
				currNode = currNode->getNextSibling();
			}
			cout << "Answer: " << finalVal << endl;
		}
	}
}
