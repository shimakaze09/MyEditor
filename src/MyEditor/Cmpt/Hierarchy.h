//
// Created by Admin on 1/03/2025.
//

#pragma once

#include <MyScene/core/Cmpt/Component.h>

#include <MyDP/Basic/Read.h>

namespace My {
class SObj;
}

namespace My::Cmpt {
class [[description("Multi-Scene Viewer")]] Hierarchy : public Component {
 public:
  Read<Hierarchy, SObj*> selected_sobj;

  Hierarchy();

  void OnUpdate();

  static void OnRegist();

 private:
  void View_SObj(SObj* sobj);

  int base_flags;  // ImGuiTreeNodeFlags
};
}  // namespace My::Cmpt
