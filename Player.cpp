#include "Player.h"
#include "InputManager.h"
#include "Resources.h"

Player::Player(const Vector2& startPos) {
	pos_ = startPos;
	width_ = 64.0f;
	height_ = 64.0f;
	hitWidth_ = 50.0f;
	hitHeight_ = 30.0f;
	speed_ = 5.0f;
	isAlive_ = true;
	shootRequested_ = false;
	animFrame_ = 0;
	animTimer_ = 0;
	maxHp_ = 5;
	hp_ = maxHp_;
}

void Player::Update() {

	if (!isAlive_) return;

	const float kGroundY = 650.0f;

	shootRequested_ = false;

	Vector2 move{ 0.0f, 0.0f };

	if (InputManager::Instance().IsPress(DIK_W)) {
		move.y -= speed_;
	}

	if (InputManager::Instance().IsPress(DIK_A)) {
		move.x -= speed_;
	}

	if (InputManager::Instance().IsPress(DIK_S)) {
		move.y += speed_;
	}

	if (InputManager::Instance().IsPress(DIK_D)) {
		move.x += speed_;
	}

	if (move.x != 0.0f || move.y != 0.0f) {
		Matrix3x3 translate = MakeTranslateMatrix(move);
		pos_ = Transform(pos_, translate);
	}

	float playerBottom = pos_.y + height_ / 2.0f;
	if (playerBottom > kGroundY) {
		pos_.y = kGroundY - height_ / 2.0f;
	}

	if (InputManager::Instance().IsTrigger(DIK_SPACE)) {
		shootRequested_ = true;
	}

	bool isMoving = (move.x != 0.0f || move.y != 0.0f);

	if (isMoving) {
		animTimer_++;
		if (animTimer_ >= kAnimInterval) {
			animTimer_ = 0;
			animFrame_ = (animFrame_ + 1) % 3;
		}
	} else {
		animFrame_ = 0;
	}

}

void Player::Draw(const Matrix3x3& worldToScreen) const {
	if (!isAlive_) return;

	Vector2 screenPos = Transform(pos_, worldToScreen);

	Novice::DrawSprite(
		static_cast<int>(screenPos.x - width_ / 2.0f),
		static_cast<int>(screenPos.y - height_ / 2.0f),
		graphHandlePlayer[animFrame_],
		2.0f,
		2.0f,
		0.0f,
		WHITE
	);
}

bool Player::IsShootRequested() const {
	return shootRequested_;
}

Vector2 Player::GetMuzzlePosition() const {
	return { pos_.x + width_ / 2.0f, pos_.y };
}

void Player::Kill() {
	isAlive_ = false;
}

void Player::Damage(int value) {
	hp_ -= value;
	if (hp_ < 0) {
		hp_ = 0;
	}
}

bool Player::IsAlive() const {
	return hp_ > 0;
}

int Player::GetHP() const {
	return hp_;
}

int Player::GetMaxHP() const {
	return maxHp_;
}