//
// Created by Admin on 1/03/2025.
//

#pragma once

#include <MyScene/core/Cmpt/Component.h>

#include <MyDP/Basic/Read.h>

#include <MyGM/UGM.h>

namespace My {
class SObj;
}  // namespace My

namespace My::Cmpt {
class Hierarchy;

class [[description("SObj's components Viewer")]] Inspector
    : public Component /*, public VarPtrVisitor<Inspector>*/ {
 public:
  Inspector();

  void OnStart();
  void OnUpdate(const Hierarchy* hierarchy);
  void OnStop();

  static void OnRegist();

 protected:
  class Viewer_Cmpt;
  Viewer_Cmpt* viewer_cmpt{nullptr};
};
}  // namespace My::Cmpt
