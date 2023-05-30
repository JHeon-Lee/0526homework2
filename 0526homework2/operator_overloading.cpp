#include <iostream>

using namespace std;

#pragma region ���� ������
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	// ���Ȯ���� ���� ��� ������ �����ε�
	friend ostream& operator << (ostream& out, const Vector& v)
	{
		out << "(" << v.x << ", " << v.y << ", " << v.z << ")" << endl;
		return out;
	}

	// ���� +
	Vector operator+()
	{
		// return Vector{ x, y, z };
		return *this;
	}

	// ���� -
	Vector operator-()
	{
		return Vector{ -x, -y, -z };
	}

	// ���� + Vector
	Vector operator+(const Vector& rhs)
	{
		return Vector{ x + rhs.x,y + rhs.y,z + rhs.z };
	}

	// ���� - Vector
	Vector operator-(const Vector& rhs)
	{
		return Vector{ x - rhs.x,y - rhs.y,z - rhs.z };
	}

	// ���� * Vector
	Vector operator*(const Vector& rhs)
	{
		return Vector{ x * rhs.x,y * rhs.y,z * rhs.z };
	}

	// ���� % Vector
	Vector operator%(const Vector& rhs)
	{
		return Vector{ x % rhs.x,y % rhs.y,z % rhs.z };
	}

	// ���� * ����
	Vector operator*(const int& rhs)
	{
		return Vector{ x * rhs,y * rhs,z * rhs };
	}

	// ���� ����
	Vector& operator++()
	{
		x += 1;
		y += 1;
		z += 1;
		return *this;
	}

	// ���� ����
	Vector& operator--()
	{
		x -= 1;
		y -= 1;
		z -= 1;
		return *this;
	}

	// ���� ����
	Vector& operator++(int) // ���⼭ int�� ����/���� �������� ���п��̰� Ư���� �ǹ̴� ����
	{
		Vector temp(x, y, z);

		x += 1;
		y += 1;
		z += 1;
		return temp;
	}

	// ���� ����
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