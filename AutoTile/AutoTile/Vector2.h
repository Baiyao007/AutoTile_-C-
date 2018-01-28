// 作成日：2016.12.12
// 作成者：柏
// 作成内容：自作ベクトルクラス
// 最後修正：2016.12.12

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