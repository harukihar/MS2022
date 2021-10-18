/*==================================================================================================
    MS2022
    [gamet.h]
    鐃�E鐃�Q鐃�[鐃緒申
----------------------------------------------------------------------------------------------------
    2021.09.27 @Author HAYASE SUZUKI
====================================================================================================
    History
        210927 鐃曙��

/*================================================================================================*/
#pragma once

#include "scene.h"

#define LAYER 3

//テスト

class CGame : public CScene {
protected:
    std::list<CGameObject*>	m_GameObject[LAYER];

public:
    CGame() {}
    ~CGame() {}

    void Init() {

    }

    void Uninit() {
        for (int i = 0; i < LAYER; i++) {
            for (auto object : m_GameObject[i]) {
                object->Uninit();
                delete object;
            }
            m_GameObject[i].clear();
        }
    }

    void Update() {
        for (int i = 0; i < LAYER; i++) {
            for (auto object : m_GameObject[i]) {
                object->Update();
            }

            m_GameObject[i].remove_if([](auto object) { return object->Destroy(); });
        }
    }

    void Draw() {
        for (int i = 0; i < LAYER; i++) {
            for (auto object : m_GameObject[i]) {
                object->Draw();
            }
        }
    }
};

