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
	//if (m_pHead == NULL)
	//	return;

	//// ��� ���� �Ҵ� �����
	//Node* pPos = m_pHead;
	//while (pPos)
	//{
	//	// m_pHead = data1 -> data2 -> data3 -> NULL;
	//	// delete data1
	//	// m_pHead = data2 -> data3 -> NULL;
	//	m_pHead = pPos->node_pNext;

	//	delete pPos;

	//	pPos = m_pHead;

	//	// m_pHead == NULL�̸� ����
	//}
}

// �⺻ ���ϱ� �Լ� (������ Inserting ���)
bool Polynomial::PlusElement(double dCoeffient, int iDegree)
{
	//��ȿ�� �˻�
	//if (iDegree > 5 || iDegree < -5 || dCoeffient == 0)
	if (iDegree > 5 || iDegree < -5)
	{
		cout << "Data validation error : " << dCoeffient << "X" << iDegree << " is inserted" << endl;
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

		//cout << "Insert Success in Head" << endl;
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
		if (pPos->node_dCoeffient == 0)
		{
			// Skip ����� 0�� ��Ȳ
		}
		else if (pPos->node_iDegree != 0)
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
		
		if (pPos->node_dCoeffient < 0)
			cout << " ";
		else
			cout << " + ";
	}

}

// m_pHead = data1 -> data2 -> data3 -> NULL; ����
void Polynomial::operator=(const Polynomial& p)
{
	m_pHead = p.m_pHead;
}

//const Polynomial& Polynomial::operator=(const Polynomial& p)
//{
//	m_pHead = p.m_pHead;
//	return *this;
//}

Polynomial Polynomial::operator+(const Polynomial& p)
{
	Polynomial result;

	Node* pPos = m_pHead;
	Node* ppPos = p.m_pHead;

	while (pPos)
	{
		result.PlusElement(pPos->node_dCoeffient, pPos->node_iDegree);
		pPos = pPos->node_pNext;
	}

	while (ppPos)
	{
		result.PlusElement(ppPos->node_dCoeffient, ppPos->node_iDegree);
		ppPos = ppPos->node_pNext;
	}

	return result;
}

Polynomial Polynomial::operator-(const Polynomial& p)
{
	Polynomial result;

	Node* pPos = m_pHead;
	Node* ppPos = p.m_pHead;

	while (pPos)
	{
		result.PlusElement(pPos->node_dCoeffient, pPos->node_iDegree);
		pPos = pPos->node_pNext;
	}

	while (ppPos)
	{
		double minusValue = ppPos->node_dCoeffient*(-1);
		result.PlusElement( minusValue, ppPos->node_iDegree);
		ppPos = ppPos->node_pNext;
	}

	return result;
}

// multiply�� �Լ��� ������ ������ŭ ���� �����Ͽ��� ��
Polynomial Polynomial::operator*(const Polynomial& p)
{
	Polynomial result;

	Node* pPos = m_pHead;
	Node* ppPos = p.m_pHead;

	while (pPos)
	{
		while (ppPos)
		{
			result.PlusElement(pPos->node_dCoeffient * ppPos->node_dCoeffient, pPos->node_iDegree + ppPos->node_iDegree);

			ppPos = ppPos->node_pNext;
		}
		ppPos = p.m_pHead;
		
		pPos = pPos->node_pNext;
	}


	return result;
}

void Polynomial::Derivative()
{
	Polynomial result;

	Node* pPos = m_pHead;
	while (pPos)
	{
		if (pPos->node_iDegree != 0)
			result.PlusElement(pPos->node_iDegree * pPos->node_dCoeffient, pPos->node_iDegree - 1);

		//if (pPos->node_iDegree == -5)


		pPos = pPos->node_pNext;
	}

	*this = result;
}
