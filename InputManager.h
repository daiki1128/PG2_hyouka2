#pragma once
#pragma once
#include <Novice.h>

//これを使えば引数にkeysとpreKeysを入れる必要なし
class InputManager {
public:
    static InputManager& Instance() {
        static InputManager instance;
        return instance;
    }

    void Update();

    //トリガー
    bool IsTrigger(int key) const;

    //プレス
    bool IsPress(int key) const;

    //リリース
    bool IsRelease(int key) const;

private:
    InputManager() = default;

    char keys_[256]{};
    char preKeys_[256]{};
};