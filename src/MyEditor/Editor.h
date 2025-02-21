//
// Created by Admin on 22/02/2025.
//

#pragma once

#include <MyScene/core/core>

namespace My {
class Editor {
 public:
  Read<Editor, SObj*> roamerobj;

  static Editor& Instance() noexcept {
    static Editor instance;
    return instance;
  }

  void SetCamera(SObj* cameraobj);
  void Update();

 private:
  Editor();
  Scene scene{"Editor Scene"};
};
}  // namespace My
