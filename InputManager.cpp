#include "InputManager.h"
#include <cstring>

void InputManager::Update() {
    memcpy(preKeys_, keys_, 256);
    Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::IsTrigger(int key) const {
    return keys_[key] && !preKeys_[key];
}

bool InputManager::IsPress(int key) const {
    return keys_[key];
}

bool InputManager::IsRelease(int key) const {
    return !keys_[key] && preKeys_[key];
}