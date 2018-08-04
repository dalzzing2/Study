#include <iostream>

using namespace std;

typedef double* ArrayPtr;
class Polynomial
{
public:
	//생성자
	Polynomial();
	Polynomial(const Polynomial& polyObject);
	//계수와 차수
	Polynomial(ArrayPtr coef, int deg);
	//소멸자
	~Polynomial();

	//오버로딩 연산자
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
	ArrayPtr coefficient;		//배열
	int degree;				//차수
};

ArrayPtr coef;

int main()
{
	int n;

	//배열 생성
	cout << "첫번째 다항식의 차수를 입력하세요 : ";
	cin >> n;
	coef = new double[n+1];
	cout << "계수를 입력하세요 : ";
	for (int i = n; i >= 0; i--)
		cin>> coef[i];
	Polynomial p1(coef, n);

	//새로운 배열생성
	cout << "두번째 다항식의 차수를 입력하세요 : ";
	cin >> n;
	coef = new double[n+1];
	cout << "계수를 입력하세요 : ";
	for (int i = n; i >= 0; i--)
		cin>> coef[i];
	Polynomial p2(coef, n);

	cout << endl;
	cout << "첫번째 다항식은 '" << p1 << "' 입니다." << endl;
	cout << "두번째 다항식은 '" << p2 << "' 입니다." << endl;

	
	Polynomial sum;
	Polynomial f_diff;
	Polynomial s_diff;
	Polynomial mul;

	sum = p1 + p2;
	f_diff = p1 - p2;
	s_diff = p2 - p1;
	mul = p1 * p2;
		
		
	cout << endl << "**다항식&다항식**" << endl;
	cout << "p1 + p2 = " << sum << endl;
	cout << "p1 - p2 = " << f_diff << endl;
	cout << "p2 - p1 = " << s_diff << endl;
	cout << "p1 * p2 = " << mul << endl;
	
	cout << endl;

	double input;
	cout << endl << "상수값을 입력하여 주세요. : ";
	cin >> input;

	cout << endl << "**다항식&상수**" << endl;
	cout << "p1 + 상수 = " << (p1 + input) << endl;
	cout << "p2 + 상수 = " << (p2 + input) << endl;
	cout << "p1 - 상수 = " << (p1 - input) << endl;
	cout << "p2 - 상수 = " << (p2 - input) << endl;
	cout << "p1 * 상수 = " << (p1 * input) << endl;
	cout << "p2 * 상수 = " << (p2 * input) << endl;

	cout << endl << endl << "**상수&다항식**" << endl;
	cout << "상수 + p1 = " << (input + p1) << endl;
	cout << "상수 + p2 = " << (input + p2) << endl;
	cout << "상수 - p1 = " << (input - p1) << endl;
	cout << "상수 - p2 = " << (input - p2) << endl;
	cout << "상수 * p1 = " << (input * p1) << endl;
	cout << "상수 * p2 = " << (input * p2) << endl;
	
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
// << 연산자
ostream& operator <<(ostream& outs, const Polynomial& thePoly)
{
	int n = thePoly.degree;
	double c;
	
	//p1과 p2가 같을때
	//가장 큰 차수의 계수가 0이고, 그 이후도 모두 가장 큰 차수의 계수와 값이 똑같다면 결과 0
	for(int i = n; i >= 0; i--){
		if(thePoly.coefficient[n]==0){
			if(thePoly.coefficient[i-1]==thePoly.coefficient[i])
				cout << "0";
				return outs;
		}
	}

	//n이 0보다 크면 x^n 출력
	if (n > 0)
		cout << thePoly.coefficient[n] << "x^" << n;

	//x^ 부분
	for (int i = n - 1; i > 0; i--)
	{
		c = thePoly.coefficient[i];
		if (c > 0)
			outs << " + " << c << "x^" << i;
		else if (c < 0)
			outs << " - " << -1*c << "x^" << i;
	}

	//상수부분
	c = thePoly.coefficient[0];
	if (n == 0)
		outs << c;
	else if (c > 0)
		outs << " + " << c;
	else if (c < 0)
		outs << " - " << -1*c;

	return outs;
}
//연산자 오버로딩 ( + 만 주석처리, 이후는 같은 원리로 동작을 하므로 중요부위를 제외한 주석 생략)
Polynomial operator +(const Polynomial& p1, const Polynomial& p2)
{
	int n1 = p1.degree;
	int n2 = p2.degree;

	int max;
	if(n1>=n2)
		max=n1;
	else if(n1<n2)
		max=n2;
	//새로운 배열 생성 ( 차수가 큰 함수로 배열을 생성하기 위한 max )
	coef = new double[max+1];
	Polynomial p3(coef, max);

	//p1과 p2중 함수가 작은값이 for문을 먼저돌면 쓰레기 값이 들어가므로
	//분리를 해주었음.

	//p1의 차수가 p2보다 클 때
	if(n1>=n2){
		for(int i = n1; i >= 0 ; i--)
		{
			//p2의 값이 쓰레기 값인 동안은 p1의 값만 집어넣음
			if(i>n2)
				p3.coefficient[i] = p1.coefficient[i];
			//p2에도 값이 할당되기 시작할 때, p1과 p2를 같이 더해줌
			else if(i<=n2)
				p3.coefficient[i] = p1.coefficient[i] + p2.coefficient[i];
		}
	}

	//같은 원리
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
//상수+다항식
Polynomial operator +(const double c, const Polynomial& p)
{
	int n1 = p.degree;
	//다항식의 차수가 크므로 다항식 차수롭 배열 생성
	coef = new double[n1+1];
	Polynomial p3(coef, n1);

	// 상수 부위에서만 서로 더해줌
	for(int i=n1; i>=0 ;i--){
		p3.coefficient[i] = p.coefficient[i];
		if(i==0)
			p3.coefficient[i] = p.coefficient[i] + c;
	}

	return p3;
}
//다항식+상수
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

	//다항식의 차수 곱셈은 (계수)X^차수+차수 형식으로 계산됨
	int mul = n1+n2;	//차수
	double sum;

	//곱하기 차수 배열 선언
	coef = new double[mul+1];
	Polynomial p3(coef, mul);

	//배열의 초기화
	for(int i = n1+n2; i >= 0; i--)
		p3.coefficient[i]=0;
	
	//다항식 곱셈에서 쓰레기 값 곱하기를 방지하기 위해 다항식 차수가 큰 것을 먼저 해줌
	if(n1>=n2){
		for(int i = n1; i >= 0 ; i--)
		{
			for(int j = n2; j >=0; j--){
				//sum을 안해줄 경우, p3은 새로새로 초기하 되기 때문에, 초기화 방지를 위해 sum 선언
				//예 : x^+x+1 * x^+x+1 = x^4+x^3+x^+x^3+x^+x+x^+x+1 (중복되는거 누적시키기 위한 sum)
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