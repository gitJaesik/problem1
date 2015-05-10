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

	//// 모든 동적 할당 지우기
	//Node* pPos = m_pHead;
	//while (pPos)
	//{
	//	// m_pHead = data1 -> data2 -> data3 -> NULL;
	//	// delete data1
	//	// m_pHead = data2 -> data3 -> NULL;
	//	m_pHead = pPos->node_pNext;

	//	delete pPos;

	//	pPos = m_pHead;

	//	// m_pHead == NULL이면 종료
	//}
}

// 기본 더하기 함수 (유일한 Inserting 기능)
bool Polynomial::PlusElement(double dCoeffient, int iDegree)
{
	//유효성 검사
	//if (iDegree > 5 || iDegree < -5 || dCoeffient == 0)
	if (iDegree > 5 || iDegree < -5)
	{
		cout << "Data validation error : " << dCoeffient << "X" << iDegree << " is inserted" << endl;
		return false;
	}

	Node* pTemp = new Node;
	pTemp->node_dCoeffient = dCoeffient;
	pTemp->node_iDegree = iDegree;

	// 데이타가 안에 없으면 Search를 할 필요가 없습니다.
	if (m_pHead == NULL)
	{
		pTemp->node_pNext = NULL;
		m_pHead = pTemp;

		//cout << "Insert Success in Head" << endl;
		return true;
	}

	Node* pPos = m_pHead;
	Node* pPreNode = NULL;

	// Plus 연산을 순서되로 하면 Sorting이 자동으로 진행
	while (true)
	{
		if (pPos == NULL)	// 끝까지 검색 -> 맨 마지막 위치에 데이타 저장 
		{
			// pPreNode -> pPos(=NULL)
			pTemp->node_pNext = NULL;
			pPreNode->node_pNext = pTemp;

			return true;
		}
		else if (pPos->node_iDegree < pTemp->node_iDegree) // 단순 크기 비교 후 위치 지정  
		{ 
			// pPreNode위치에 넣기
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
			// pPos 위치에서 그대로 덧셈을 진행
			// 7.5x5 + 3x5 = 10.5x5
			pPos->node_dCoeffient = pPos->node_dCoeffient + pTemp->node_dCoeffient;
			return true;
		}
		//else if (pPos->node_iDegree > pTemp->node_iDegree)
		//{
		//	// 계속 진행.
		//}

		pPreNode = pPos;
		pPos = pPos->node_pNext;
	}

	//return false;
}


void Polynomial::DisplayPolynomial()
{
	cout << m_sFunctionName << " : ";

	// 함수가 비어있는 경우
	if (m_pHead == NULL)
	{
		cout << "It's NULL function" << endl;
		return;
	}

	Node* pPos = m_pHead;

	// pPos가 NULL이 될때까지 출력
	// m_pHead = data1 -> data2 -> data3 -> data4 -> NULL
	while (true){
		if (pPos->node_dCoeffient == 0)
		{
			// Skip 계수가 0인 상황
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

// m_pHead = data1 -> data2 -> data3 -> NULL; 복사
void Polynomial::operator=(const Polynomial& p)
{
	m_pHead = p.m_pHead;
}

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

// multiply시 함수를 변수의 갯수만큼 만들어서 복사하여야 함
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
