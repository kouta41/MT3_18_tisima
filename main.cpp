﻿#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "LC1B_18_ツシマ_コウタ	";


struct Vector3 {
	float x, y, z;
};
Vector3 v1{ 1.0f,3.0f,-5.0f };
Vector3 v2{ 4.0f,-1.0f,2.0f };
float k = { 4.0f };

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 add;
	add.x = v1.x + v2.x;
	add.y = v1.y + v2.y;
	add.z = v1.z + v2.z;
	return add;
}
//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 subtract;
	subtract.x = v1.x - v2.x;
	subtract.y = v1.y - v2.y;
	subtract.z = v1.z - v2.z;
	return subtract;
}
//スカラー倍
Vector3 Multiply(float scalar, const Vector3& v) {
	Vector3 multiply;
	multiply.x = v.x * scalar;
	multiply.y = v.y * scalar;
	multiply.z = v.z * scalar;
	return multiply;
}
//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float dot;
	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return dot;

}
//長さ(ノルム)
float Length(const Vector3& v) {
	float lenght = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return lenght;
}
//正規化
Vector3 Normalize(const Vector3& v) {
	Vector3 normalize;
	float mag = 1 / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	normalize.x = v.x * mag;
	normalize.y = v.y * mag;
	normalize.z = v.z * mag;
	return normalize;
}




Vector3 resultAdd = Add(v1, v2);
Vector3 resultSubtract = Subtract(v1, v2);
Vector3 resultMultiply = Multiply(k, v1);
float resultDot = Dot(v1, v2);
float resultLength = Length(v1);
Vector3 resultNormalize = Normalize(v2);



static const int kColumWidth = 60;

void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f", vector.x);
	Novice::ScreenPrintf(x + kColumWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColumWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColumWidth * 3, y, "%s", label);
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, resultAdd, " :Add");
		VectorScreenPrintf(0, kColumWidth, resultSubtract, " :Subtract");
		VectorScreenPrintf(0, kColumWidth * 2, resultMultiply, " :Multiply");
		Novice::ScreenPrintf(0, kColumWidth * 3, "%.02f :Dot", resultDot);
		Novice::ScreenPrintf(0, kColumWidth * 4, "%.02f :Length", resultLength);
		VectorScreenPrintf(0, kColumWidth * 5, resultNormalize, " :Nomalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
