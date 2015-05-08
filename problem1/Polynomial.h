#pragma once

#include <iostream>

class Polynomial
{
public:
	struct Node{
		// ����Ÿ ��Ʈ
		double node_dCoeffient;
		int node_iDegree;

		Node* node_pNext;
		Node(){ node_pNext = NULL; }	// ������
	};

	Node* m_pHead;

public:
	Polynomial();
	~Polynomial();
	int InsertData(double dCoeffient, int iDegree);
	void* SearchPreviousIDegree(Node* pTemp);
};

