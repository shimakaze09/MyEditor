//
// Created by Admin on 22/02/2025.
//

#include "Editor.h"
#include "GenScene.h"

#include <MyEngine/Engine.h>
#include <MyEngine/SceneMngr.h>
#include <MyScene/core.h>

using namespace My;
using namespace std;

int main(int, char**) {
  Engine::Instance().Init("My@2025 MyEditor v0.0.2");
  Editor::OnRegist();

  auto scene = GenScene(0);

  Editor::Instance().SetCamera(scene->root->GetSObjInTreeWith<Cmpt::Camera>());

  SceneMngr::Instance().Insert(scene);
  SceneMngr::Instance().Insert(Editor::Instance().scene);

  SceneMngr::Instance().Active(
      scene, Editor::Instance().scene->root->GetSObjInTreeWith<Cmpt::Camera>());

  Engine::Instance().Loop();

  Engine::Instance().CleanUp();

  delete scene;

  return 0;
}
