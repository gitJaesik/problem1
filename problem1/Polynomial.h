#pragma once

#include <iostream>
#include <string>

using namespace std;

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

	string m_sFunctionName;

public:
	Polynomial();
	Polynomial(string name);
	//Polynomial(const Polynomial& p);
	~Polynomial();

	// 기본 더하기 함수 (유일한 Inserting 기능)
	bool PlusElement(double dCoeffient, int iDegree);

	// Show Polynomial, 함수 보이기
	void DisplayPolynomial();

	// Polynomial 복사하기
	void operator=(const Polynomial& p);
	//const Polynomial& operator=(const Polynomial& p);

	Polynomial operator+(const Polynomial& p);
	Polynomial operator-(const Polynomial& p);

	// multiply시 함수를 변수의 갯수만큼 만들어서 복사하여야 함
	Polynomial operator*(const Polynomial& p);

	void Derivative();
};

