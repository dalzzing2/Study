#include <iostream>

using namespace std;

typedef double* ArrayPtr;
class Polynomial
{
public:
	//������
	Polynomial();
	Polynomial(const Polynomial& polyObject);
	//����� ����
	Polynomial(ArrayPtr coef, int deg);
	//�Ҹ���
	~Polynomial();

	//�����ε� ������
	Polynomial& operator =(const Polynomial& rtSide);
	friend ostream& operator <<(ostream& outs, const Polynomial& thePoly);
	friend Polynomial operator +(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator +(const double c, const Polynomial& p);
	friend Polynomial operator +(const Polynomial& p, const double c);
	friend Polynomial operator -(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator -(const double c, const Polynomial& p);
	friend Polynomial operator -(const Polynomial& p, const double c);
	friend Polynomial operator *(const Polynomial& p1, const Polynomial& p2);
	friend Polynomial operator *(const double c, const Polynomial& p);
	friend Polynomial operator *(const Polynomial& p, const double c);

	double& operator[] (int index) { return coefficient[index]; }

private:
	ArrayPtr coefficient;		//�迭
	int degree;				//����
};

ArrayPtr coef;

int main()
{
	int n;

	//�迭 ����
	cout << "ù��° ���׽��� ������ �Է��ϼ��� : ";
	cin >> n;
	coef = new double[n+1];
	cout << "����� �Է��ϼ��� : ";
	for (int i = n; i >= 0; i--)
		cin>> coef[i];
	Polynomial p1(coef, n);

	//���ο� �迭����
	cout << "�ι�° ���׽��� ������ �Է��ϼ��� : ";
	cin >> n;
	coef = new double[n+1];
	cout << "����� �Է��ϼ��� : ";
	for (int i = n; i >= 0; i--)
		cin>> coef[i];
	Polynomial p2(coef, n);

	cout << endl;
	cout << "ù��° ���׽��� '" << p1 << "' �Դϴ�." << endl;
	cout << "�ι�° ���׽��� '" << p2 << "' �Դϴ�." << endl;

	
	Polynomial sum;
	Polynomial f_diff;
	Polynomial s_diff;
	Polynomial mul;

	sum = p1 + p2;
	f_diff = p1 - p2;
	s_diff = p2 - p1;
	mul = p1 * p2;
		
		
	cout << endl << "**���׽�&���׽�**" << endl;
	cout << "p1 + p2 = " << sum << endl;
	cout << "p1 - p2 = " << f_diff << endl;
	cout << "p2 - p1 = " << s_diff << endl;
	cout << "p1 * p2 = " << mul << endl;
	
	cout << endl;

	double input;
	cout << endl << "������� �Է��Ͽ� �ּ���. : ";
	cin >> input;

	cout << endl << "**���׽�&���**" << endl;
	cout << "p1 + ��� = " << (p1 + input) << endl;
	cout << "p2 + ��� = " << (p2 + input) << endl;
	cout << "p1 - ��� = " << (p1 - input) << endl;
	cout << "p2 - ��� = " << (p2 - input) << endl;
	cout << "p1 * ��� = " << (p1 * input) << endl;
	cout << "p2 * ��� = " << (p2 * input) << endl;

	cout << endl << endl << "**���&���׽�**" << endl;
	cout << "��� + p1 = " << (input + p1) << endl;
	cout << "��� + p2 = " << (input + p2) << endl;
	cout << "��� - p1 = " << (input - p1) << endl;
	cout << "��� - p2 = " << (input - p2) << endl;
	cout << "��� * p1 = " << (input * p1) << endl;
	cout << "��� * p2 = " << (input * p2) << endl;
	
	return 0;
}

Polynomial::Polynomial()
{
	degree = 0;
	coefficient = new double[degree+1];
	coefficient[0] = 0;
}

Polynomial::Polynomial(const Polynomial& polyObject)
{
	degree = polyObject.degree;
	coefficient = new double[degree+1];
	for (int i = degree; i >= 0; i--)
		coefficient[i] = polyObject.coefficient[i];
}

Polynomial::Polynomial(ArrayPtr coef, int deg)
{
	degree = deg;
	coefficient = new double[degree+1];
	for (int i = 0; i <= degree; i++)
		coefficient[i] = coef[i];
}

Polynomial::~Polynomial()
{
	delete [] coefficient;
}
// << ������
ostream& operator <<(ostream& outs, const Polynomial& thePoly)
{
	int n = thePoly.degree;
	double c;
	
	//p1�� p2�� ������
	//���� ū ������ ����� 0�̰�, �� ���ĵ� ��� ���� ū ������ ����� ���� �Ȱ��ٸ� ��� 0
	for(int i = n; i >= 0; i--){
		if(thePoly.coefficient[n]==0){
			if(thePoly.coefficient[i-1]==thePoly.coefficient[i])
				cout << "0";
				return outs;
		}
	}

	//n�� 0���� ũ�� x^n ���
	if (n > 0)
		cout << thePoly.coefficient[n] << "x^" << n;

	//x^ �κ�
	for (int i = n - 1; i > 0; i--)
	{
		c = thePoly.coefficient[i];
		if (c > 0)
			outs << " + " << c << "x^" << i;
		else if (c < 0)
			outs << " - " << -1*c << "x^" << i;
	}

	//����κ�
	c = thePoly.coefficient[0];
	if (n == 0)
		outs << c;
	else if (c > 0)
		outs << " + " << c;
	else if (c < 0)
		outs << " - " << -1*c;

	return outs;
}
//������ �����ε� ( + �� �ּ�ó��, ���Ĵ� ���� ������ ������ �ϹǷ� �߿������ ������ �ּ� ����)
Polynomial operator +(const Polynomial& p1, const Polynomial& p2)
{
	int n1 = p1.degree;
	int n2 = p2.degree;

	int max;
	if(n1>=n2)
		max=n1;
	else if(n1<n2)
		max=n2;
	//���ο� �迭 ���� ( ������ ū �Լ��� �迭�� �����ϱ� ���� max )
	coef = new double[max+1];
	Polynomial p3(coef, max);

	//p1�� p2�� �Լ��� �������� for���� �������� ������ ���� ���Ƿ�
	//�и��� ���־���.

	//p1�� ������ p2���� Ŭ ��
	if(n1>=n2){
		for(int i = n1; i >= 0 ; i--)
		{
			//p2�� ���� ������ ���� ������ p1�� ���� �������
			if(i>n2)
				p3.coefficient[i] = p1.coefficient[i];
			//p2���� ���� �Ҵ�Ǳ� ������ ��, p1�� p2�� ���� ������
			else if(i<=n2)
				p3.coefficient[i] = p1.coefficient[i] + p2.coefficient[i];
		}
	}

	//���� ����
	else if(n1<n2){
		for(int i = n2; i >= 0 ; i--)
		{
			if(i>n1)
				p3.coefficient[i] = p2.coefficient[i];
			else if(i<=n1)
				p3.coefficient[i] = p1.coefficient[i] + p2.coefficient[i];
		}
	}
	return p3;
}
//���+���׽�
Polynomial operator +(const double c, const Polynomial& p)
{
	int n1 = p.degree;
	//���׽��� ������ ũ�Ƿ� ���׽� ������ �迭 ����
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	// ��� ���������� ���� ������
	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = p.coefficient[i];
		if(i==0)
			p3.coefficient[i] = p.coefficient[i] + c;
	}

	return p3;
}
//���׽�+���
Polynomial operator +(const Polynomial& p, const double c)
{
	int n1 = p.degree;
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = p.coefficient[i];
		if(i==0)
			p3.coefficient[i] = p.coefficient[i] + c;
	}
	return p3;
}

// -
Polynomial operator -(const Polynomial& p1, const Polynomial& p2)
{
	int n1 = p1.degree;
	int n2 = p2.degree;
	int max;
	if(n1>=n2)
		max=n1;
	else if(n1<n2)
		max=n2;
	coef = new double[max+1];
	Polynomial p3(coef, max);

	if(n1>=n2){
		for(int i = n1; i >= 0 ; i--)
		{
			if(i>n2)
				p3.coefficient[i] = p1.coefficient[i];
			else if(i<=n2)
				p3.coefficient[i] = p1.coefficient[i] - p2.coefficient[i];
		}
	}

	else if(n1<n2){
		for(int i = n2; i >= 0 ; i--)
		{
			if(i>n1)
				p3.coefficient[i] = -p2.coefficient[i];
			else if(i<=n1)
				p3.coefficient[i] = -p2.coefficient[i] + p1.coefficient[i];
		}
	}
	return p3;
}
Polynomial operator -(const double c, const Polynomial& p)
{
	int n1 = p.degree;
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = -p.coefficient[i];
		if(i==0)
			p3.coefficient[i] = +c - p.coefficient[i];
	}
	return p3;
}
Polynomial operator -(const Polynomial& p, const double c)
{
	int n1 = p.degree;
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = p.coefficient[i];
		if(i==0)
			p3.coefficient[i] = p.coefficient[i] - c;
	}
	return p3;
}
// *
Polynomial operator *(const Polynomial& p1, const Polynomial& p2)
{
	int n1 = p1.degree;
	int n2 = p2.degree;

	//���׽��� ���� ������ (���)X^����+���� �������� ����
	int mul = n1+n2;	//����
	double sum;

	//���ϱ� ���� �迭 ����
	coef = new double[mul+1];
	Polynomial p3(coef, mul);

	//�迭�� �ʱ�ȭ
	for(int i = n1+n2; i >= 0; i--)
		p3.coefficient[i]=0;
	
	//���׽� �������� ������ �� ���ϱ⸦ �����ϱ� ���� ���׽� ������ ū ���� ���� ����
	if(n1>=n2){
		for(int i = n1; i >= 0 ; i--)
		{
			for(int j = n2; j >=0; j--){
				//sum�� ������ ���, p3�� ���λ��� �ʱ��� �Ǳ� ������, �ʱ�ȭ ������ ���� sum ����
				//�� : x^+x+1 * x^+x+1 = x^4+x^3+x^+x^3+x^+x+x^+x+1 (�ߺ��Ǵ°� ������Ű�� ���� sum)
				sum = p1.coefficient[i]*p2.coefficient[j];
				p3.coefficient[i+j] = p3.coefficient[i+j] + sum;
			}
		}
	}
	else if(n1<n2){
		for(int i = n2; i >= 0 ; i--)
		{
			for(int j = n1; j >=0; j--){
				sum = p1.coefficient[j]*p2.coefficient[i];
				p3.coefficient[i+j] = p3.coefficient[i+j] + sum;
			}
		}
	}
	return p3;
}
Polynomial operator *(const double c, const Polynomial& p)
{
	int n1 = p.degree;
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = c * p.coefficient[i];
	}
	return p3;
}
Polynomial operator *(const Polynomial& p, const double c)
{
	int n1 = p.degree;
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = c * p.coefficient[i];
	}
	return p3;
}

Polynomial& Polynomial::operator =(const Polynomial& rtSide)
{
	if(this == &rtSide)
		return *this;
	else{
		degree = rtSide.degree;
		//coefficient = rtSide.coefficient;
		delete []coefficient;
		coefficient = new double[degree+1];
		
		for(int i = degree; i>=0; i--)
			coefficient[i] = rtSide.coefficient[i];
		return *this;
	}
}