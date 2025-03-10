//
// Created by Admin on 1/03/2025.
//

#include "Inspector.h"

#include "Hierarchy.h"

#include "detail/Inspector.inl"

#include <MyScene/core.h>
#include <_deps/imgui/imgui.h>

#include <MyEngine/Engine.h>

#include <MyDP/Reflection/ReflTraits.h>
#include <MyDP/Reflection/VarPtrVisitor.h>
#include <MyDP/Visitor/InfVisitor.h>

using namespace My;
using namespace std;

class Cmpt::Inspector::Viewer_Cmpt : public ReflTraitsVisitor {
 public:
  Viewer_Cmpt() { ReflTraitsIniter::Instance().InitNC(*this); }

 private:
  // obj is used for special visit (not just name and vars)
  virtual void Receive(
      void* obj, std::string_view name,
      const xMap<std::string, std::shared_ptr<VarPtrBase>>& vars) override {
    if (ImGui::CollapsingHeader(name.data())) {
      for (const auto& [name, var] : vars) {
        ImGui::Text(name.data());
        // TODO: edit
      }
    }
  };
};

Cmpt::Inspector::Inspector() = default;

void Cmpt::Inspector::OnStart() {
  viewer_cmpt = new Viewer_Cmpt;
}

void Cmpt::Inspector::OnStop() {
  delete viewer_cmpt;
  viewer_cmpt = nullptr;
}

void Cmpt::Inspector::OnRegist() {
  detail::dynamic_reflection::ReflRegist_Inspector();
}

void Cmpt::Inspector::OnUpdate(const Hierarchy* hierarchy) {
  if (!hierarchy->selected_sobj)
    return;

  Engine::Instance().AddIMGUICommand([this, sobj = hierarchy->selected_sobj]() {
    ImGui::Begin("Inspector");
    ImGui::Text(("name: " + sobj->name).c_str());
    ImGui::Text(
        ("number of children: " + to_string(sobj->children->size())).c_str());
    auto cmpts = sobj->Components();
    ImGui::Text(("number of components: " + to_string(cmpts.size())).c_str());
    for (auto [cmpt, size] : cmpts)
      viewer_cmpt->Visit(cmpt);
    ImGui::End();
  });
}
