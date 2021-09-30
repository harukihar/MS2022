/*==================================================================================================
    MS2022
    [manager.cpp]
    �E�}�l�[�W���[
----------------------------------------------------------------------------------------------------
    2021.09.27 @Author HAYASE SUZUKI
====================================================================================================
    History
        210927 �쐬

/*================================================================================================*/
#include "main.h"
#include "window.h"
#include "manager.h"
#include "renderer.h"
#include "title.h"

CScene* CManager::m_Scene;


void CManager::Init(HINSTANCE hInstance, int nCmdShow) {
    CWindow::Initialize(hInstance);
    CRenderer::Init();
    CWindow::Display(nCmdShow);

    SetScene<CTitle>();

}

void CManager::Uninit() {

    m_Scene->Uninit();
    delete m_Scene;

    CRenderer::Uninit();
}

void CManager::Update() {
    m_Scene->Update();
}

void CManager::Draw() {
    CRenderer::Begin();

    m_Scene->Draw();

    CRenderer::End();
}