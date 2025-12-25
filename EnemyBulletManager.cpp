#include "EnemyBulletManager.h"
#include <algorithm>

void EnemyBulletManager::Update() {
	for (auto& bullet : bullets_) {
		bullet.Update();
	}

	// 死んだ弾を削除
	bullets_.erase(
		std::remove_if(
			bullets_.begin(),
			bullets_.end(),
			[](const EnemyBullet& b) { return !b.IsAlive(); }
		),
		bullets_.end()
	);
}

void EnemyBulletManager::Draw(const Matrix3x3& worldToScreen) const {
	for (const auto& bullet : bullets_) {
		bullet.Draw(worldToScreen);
	}
}

void EnemyBulletManager::Spawn(const Vector2& startPos) {
	Vector2 velocity{ -8.0f, 0.0f };
	bullets_.emplace_back(startPos, velocity);
}

void EnemyBulletManager::CheckCollisionWithPlayer(Player& player) {
	if (!player.IsAlive()) return;

	for (auto& bullet : bullets_) {
		if (!bullet.IsAlive()) continue;

		Vector2 bPos = bullet.GetPos();
		Vector2 pPos = player.GetPos();

		bool hitX = std::abs(bPos.x - pPos.x) < (bullet.GetHitWidth() + player.GetHitWidth()) * 0.5f;

		bool hitY = std::abs(bPos.y - pPos.y) < (bullet.GetHitHeight() + player.GetHitHeight()) * 0.5f;

		if (hitX && hitY) {
			bullet.Kill();
			player.Damage(1);
			break;
		}
	}
}