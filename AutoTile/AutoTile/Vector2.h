// �쐬���F2016.12.12
// �쐬�ҁF��
// �쐬���e�F����x�N�g���N���X
// �Ō�C���F2016.12.12

#pragma once

template<class T>
class Vector2 {
public:
	Vector2():X(0), Y(0) {}
	Vector2(T _x, T _y):X(_x),Y(_y) {}

	~Vector2(){}

	Vector2& operator/(const Vector2& other) {
		return Vector2(X / other.X, Y / other.Y);
	}

	T X;
	T Y;

private:
	
};