#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;

Polynomial::Polynomial()
{
	m_pHead = NULL;
}

Polynomial::Polynomial(string name)
{
	m_sFunctionName = name;
	m_pHead = NULL;
}

Polynomial::~Polynomial()
{
	// ��� ���� �Ҵ� �����
}

// �⺻ ���ϱ� �Լ� (������ Inserting ���)
bool Polynomial::PlusElement(double dCoeffient, int iDegree)
{
	//��ȿ�� �˻�
	if (iDegree > 5 || iDegree < -5 || dCoeffient == 0)
	{
		cout << "Data validation error";
		return false;
	}

	Node* pTemp = new Node;
	pTemp->node_dCoeffient = dCoeffient;
	pTemp->node_iDegree = iDegree;

	// ����Ÿ�� �ȿ� ������ Search�� �� �ʿ䰡 �����ϴ�.
	if (m_pHead == NULL)
	{
		pTemp->node_pNext = NULL;
		m_pHead = pTemp;

		cout << "Insert Success in Head" << endl;
		return true;
	}

	Node* pPos = m_pHead;
	Node* pPreNode = NULL;

	// Plus ������ �����Ƿ� �ϸ� Sorting�� �ڵ����� ����
	while (true)
	{
		if (pPos == NULL)	// ������ �˻� -> �� ������ ��ġ�� ����Ÿ ���� 
		{
			// pPreNode -> pPos(=NULL)
			pTemp->node_pNext = NULL;
			pPreNode->node_pNext = pTemp;

			return true;
		}
		else if (pPos->node_iDegree < pTemp->node_iDegree) // �ܼ� ũ�� �� �� ��ġ ����  
		{ 
			// pPreNode��ġ�� �ֱ�
			if (pPreNode == NULL)
			{
				// pHead -> pTemp -> pPos
				pTemp->node_pNext = pPos;
				m_pHead = pTemp;
			}
			else
			{
				// pPreNode -> pTemp -> pPos
				pTemp->node_pNext = pPos;
				pPreNode->node_pNext = pTemp;
			}
				return true;
		}
		else if (pPos->node_iDegree == pTemp->node_iDegree)
		{
			// pPos ��ġ���� �״�� ������ ����
			// 7.5x5 + 3x5 = 10.5x5
			pPos->node_dCoeffient = pPos->node_dCoeffient + pTemp->node_dCoeffient;
			return true;
		}
		//else if (pPos->node_iDegree > pTemp->node_iDegree)
		//{
		//	// ��� ����.
		//}

		pPreNode = pPos;
		pPos = pPos->node_pNext;
	}

	//return false;
}


void Polynomial::DisplayPolynomial()
{
	cout << m_sFunctionName << " : ";

	// �Լ��� ����ִ� ���
	if (m_pHead == NULL)
	{
		cout << "It's NULL function" << endl;
		return;
	}

	Node* pPos = m_pHead;

	// pPos�� NULL�� �ɶ����� ���
	// m_pHead = data1 -> data2 -> data3 -> data4 -> NULL
	while (true){
		if (pPos->node_iDegree != 0)
		{
			cout << pPos->node_dCoeffient << "X" << pPos->node_iDegree;
		}
		else
		{
			cout << pPos->node_dCoeffient;
		}

		pPos = pPos->node_pNext;

		if (pPos == NULL)
		{
			cout << endl;
			return;
		}
		
		cout << " + ";
	}

}
