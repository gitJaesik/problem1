#include "Polynomial.h"
#include <iostream>


Polynomial::Polynomial()
{
	m_pHead = NULL;
}


Polynomial::~Polynomial()
{
	// 모든 동적 할당 지우기
}


int Polynomial::InsertData(double dCoeffient, int iDegree)
{
	// To give pNext of last node
	Node* pTemp = new Node;

	pTemp->node_dCoeffient = dCoeffient;
	pTemp->node_iDegree = iDegree;

	if (m_pHead == NULL)
	{
		m_pHead->node_pNext = pTemp;
		pTemp->node_pNext = NULL;
	}

	//search 함수를 사용 후 대입
	Node* InsertPos = (Node*)SearchPreviousIDegree(pTemp);
	
	//검색 실패
	if (InsertPos == NULL)
		return -1;

	pTemp->node_pNext = InsertPos->node_pNext;
	InsertPos->node_pNext = pTemp;

	return 0;
}
void* Polynomial::SearchPreviousIDegree(Node* pTemp)
{
	// 헤드가 NULL인 것을 피하고
	// 헤그가 NULL이 아니라면 Degree를 조사
	// Degree의 범위는 +5 ~ -5
	if (m_pHead == NULL)
	{
		return m_pHead;
	}

	Node* pPos = m_pHead;
	Node* pPreNode = NULL;

	while (pPos != NULL)
	{
		// pHead가 NULL일때, degree가 초기화로 0인가를 조사
		// 데이터의 Validation을 조사하기 위해서는 dCoeffient의 값을 조사하여야 함
		if (pPos->node_iDegree == pTemp->node_iDegree && pPos->node_dCoeffient != 0)
		{
			return pPreNode;
		}

		pPreNode = pPos;
		pPos = pPos->node_pNext;
	}

	return 0;
}
