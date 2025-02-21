//
// Created by Admin on 22/02/2025.
//

#include "Roamer.h"

#include <_deps/imgui/imgui.h>
#include <MyScene/core/core>

using namespace My;
using namespace std;

void Cmpt::Roamer::OnUpdate(Cmpt::Transform* tsfm) {
  auto& io = ImGui::GetIO();

  auto l2w = tsfm->LocalToWorldMatrix();
  auto forward = (l2w * vecf3{0, 0, -1}).normalize();
  auto right = (l2w * vecf3{1, 0, 0}).normalize();
  vecf3 worldUp{0, 1, 0};

  float dt = io.DeltaTime;
  float dx = io.MouseDelta[0];
  float dy = io.MouseDelta[1];

  // TODO: key enum
  float movespeed = 5.f;
  vecf3 move{0.f};
  if (io.KeysDown['W'])
    move += movespeed * dt * forward;
  if (io.KeysDown['S'])
    move -= movespeed * dt * forward;
  if (io.KeysDown['A'])
    move -= movespeed * dt * right;
  if (io.KeysDown['D'])
    move += movespeed * dt * right;
  if (io.KeysDown['Q'])
    move += movespeed * dt * worldUp;
  if (io.KeysDown['E'])
    move -= movespeed * dt * worldUp;
  tsfm->SetPosition(tsfm->pos.get() + move);

  float rotateSpeed = 0.2f;
  // right button
  if (io.MouseClicked[1] || io.KeysDown['Z']) {
    quatf rx{worldUp, -rotateSpeed * dt * dx};
    quatf ry{right, -rotateSpeed * dt * dy};
    tsfm->SetRotation(rx * ry * tsfm->rot.get());
  }
}
