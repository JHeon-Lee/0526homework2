#include <iostream>

using namespace std;

#pragma region 단항 연산자
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	// 결과확인을 위한 출력 연산자 오버로딩
	friend ostream& operator << (ostream& out, const Vector& v)
	{
		out << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
		return out;
	}

	// 단항 +
	Vector operator+()
	{
		// return Vector{ x, y, z };
		return *this;
	}

	// 단항 -
	Vector operator-()
	{
		return Vector{ -x, -y, -z };
	}

	// 이항 + Vector
	Vector operator+(const Vector& rhs)
	{
		return Vector{ x + rhs.x,y + rhs.y,z + rhs.z };
	}

	// 이항 - Vector
	Vector operator-(const Vector& rhs)
	{
		return Vector{ x - rhs.x,y - rhs.y,z - rhs.z };
	}

	// 이항 * Vector
	Vector operator*(const Vector& rhs)
	{
		return Vector{ x * rhs.x,y * rhs.y,z * rhs.z };
	}

	// 이항 % Vector
	Vector operator%(const Vector& rhs)
	{
		return Vector{ x % rhs.x,y % rhs.y,z % rhs.z };
	}

	// 이항 * 정수
	Vector operator*(const int& rhs)
	{
		return Vector{ x * rhs,y * rhs,z * rhs };
	}

	// 전위 증가
	Vector& operator++()
	{
		x += 1;
		y += 1;
		z += 1;
		return *this;
	}

	// 전위 감소
	Vector& operator--()
	{
		x -= 1;
		y -= 1;
		z -= 1;
		return *this;
	}

	// 후위 증가
	Vector& operator++(int) // 여기서 int는 전위/후위 연산자의 구분용이고 특별한 의미는 없음
	{
		Vector temp(x, y, z);

		x += 1;
		y += 1;
		z += 1;
		return temp;
	}

	// 후위 감소
	Vector& operator--(int)
	{
		Vector temp(x, y, z);

		x -= 1;
		y -= 1;
		z -= 1;
		return temp;
	}

private:
	int x;
	int y;
	int z;
};

#pragma endregion

int main()
{
	Vector vector(1, 2, 3);
	Vector vector2(4, 5, 6);

	cout << +vector << -vector << endl;

	cout << vector + vector2 << vector - vector2 << vector * vector2
		<< vector % vector2 << vector * 3 << endl;

	cout << ++vector;
	cout << vector++;
	cout << vector << endl;

	cout << --vector2;
	cout << vector2--;
	cout << vector2 << endl;

	return 0;
}