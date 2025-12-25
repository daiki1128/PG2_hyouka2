#include "Bullet.h"
#include "Novice.h"
#include "Resources.h"

Bullet::Bullet(const Vector2& startPos, const Vector2& velocity) {
	pos_ = startPos;
	velocity_ = velocity;
	width_ = 64.0f;
	height_ = 64.0f;
	hitWidth_ = 64.0f;
	hitHeight_ = 30.0f;
	isAlive_ = true;
}

void Bullet::Update() {
	if (!isAlive_) return;

	Matrix3x3 translate = MakeTranslateMatrix(velocity_);
	pos_ = Transform(pos_, translate);

	if (pos_.x > 1280.0f) {
		isAlive_ = false;
	}
}

void Bullet::Draw(const Matrix3x3& worldToScreen) const {
	if (!isAlive_) return;

	Vector2 screenPos = Transform(pos_, worldToScreen);

	Novice::DrawSprite(
		static_cast<int>(screenPos.x - width_ / 2.0f),
		static_cast<int>(screenPos.y - height_ / 2.0f),
		graphHandlePlayerBullet,
		2.0f,
		2.0f,
		0.0f,
		WHITE
	);
}

bool Bullet::IsAlive() const {
	return isAlive_;
}

void Bullet::Kill() {
	isAlive_ = false;
}

const Vector2& Bullet::GetPos() const {
	return pos_;
}