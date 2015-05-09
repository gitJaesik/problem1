#pragma once

#include <iostream>
#include <string>

using namespace std;

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

	string m_sFunctionName;

public:
	Polynomial();
	Polynomial(string name);
	//Polynomial(const Polynomial& p);
	~Polynomial();

	// �⺻ ���ϱ� �Լ� (������ Inserting ���)
	bool PlusElement(double dCoeffient, int iDegree);

	// Show Polynomial, �Լ� ���̱�
	void DisplayPolynomial();

	// Polynomial �����ϱ�
	void operator=(const Polynomial& p);
	//const Polynomial& operator=(const Polynomial& p);

	Polynomial operator+(const Polynomial& p);
	Polynomial operator-(const Polynomial& p);

	// multiply�� �Լ��� ������ ������ŭ ���� �����Ͽ��� ��
	Polynomial operator*(const Polynomial& p);

	void Derivative();
};

