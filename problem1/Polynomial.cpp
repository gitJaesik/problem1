#include "Polynomial.h"
#include <iostream>


Polynomial::Polynomial()
{
	m_pHead = NULL;
}


Polynomial::~Polynomial()
{
	// ��� ���� �Ҵ� �����
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

	//search �Լ��� ��� �� ����
	Node* InsertPos = (Node*)SearchPreviousIDegree(pTemp);
	
	//�˻� ����
	if (InsertPos == NULL)
		return -1;

	pTemp->node_pNext = InsertPos->node_pNext;
	InsertPos->node_pNext = pTemp;

	return 0;
}
void* Polynomial::SearchPreviousIDegree(Node* pTemp)
{
	// ��尡 NULL�� ���� ���ϰ�
	// ��װ� NULL�� �ƴ϶�� Degree�� ����
	// Degree�� ������ +5 ~ -5
	if (m_pHead == NULL)
	{
		return m_pHead;
	}

	Node* pPos = m_pHead;
	Node* pPreNode = NULL;

	while (pPos != NULL)
	{
		// pHead�� NULL�϶�, degree�� �ʱ�ȭ�� 0�ΰ��� ����
		// �������� Validation�� �����ϱ� ���ؼ��� dCoeffient�� ���� �����Ͽ��� ��
		if (pPos->node_iDegree == pTemp->node_iDegree && pPos->node_dCoeffient != 0)
		{
			return pPreNode;
		}

		pPreNode = pPos;
		pPos = pPos->node_pNext;
	}

	return 0;
}
