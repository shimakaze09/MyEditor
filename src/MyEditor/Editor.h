//
// Created by Admin on 22/02/2025.
//

#pragma once

#include <MyScene/core.h>

namespace My {
class Editor {
 public:
  Read<Editor, Scene*> scene;

  static Editor& Instance() noexcept {
    static Editor instance;
    return instance;
  }

  void SetCamera(SObj* cameraobj);

  static void OnRegist();

 private:
  Editor();
  ~Editor();
};
}  // namespace My
