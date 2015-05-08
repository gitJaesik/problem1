#pragma once

#include <iostream>

class Polynomial
{
public:
	struct Node{
		// 데이타 파트
		double node_dCoeffient;
		int node_iDegree;

		Node* node_pNext;
		Node(){ node_pNext = NULL; }	// 생성자
	};

	Node* m_pHead;

public:
	Polynomial();
	~Polynomial();
	int InsertData(double dCoeffient, int iDegree);
	void* SearchPreviousIDegree(Node* pTemp);
};

