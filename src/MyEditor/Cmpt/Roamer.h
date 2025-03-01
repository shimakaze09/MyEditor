//
// Created by Admin on 1/03/2025.
//

#pragma once

#include <MyDP/Basic/Read.h>
#include <MyScene/core/Cmpt/Component.h>
#include <MyScene/core/Cmpt/Transform.h>

namespace My::Cmpt {
class L2W;
class Position;
class Rotation;

class Roamer : public Component {
 public:
  float move_speed = 5.f;
  float rotate_speed = 0.1f;

  void OnUpdate(CmptTag::LastFrame<Cmpt::L2W> l2w, Position* pos,
                Rotation* rot);

  static void OnRegist();
};
}  // namespace My::Cmpt
