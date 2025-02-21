//
// Created by Admin on 22/02/2025.
//

#pragma once

#include <MyDP/Basic/Read.h>
#include <MyScene/core/Cmpt/Transform.h>
#include <MyScene/core/Component.h>

namespace My::Cmpt {
class Roamer : public Component {
 public:
  void OnUpdate(Cmpt::Transform* tsfm);
};
}  // namespace My::Cmpt
