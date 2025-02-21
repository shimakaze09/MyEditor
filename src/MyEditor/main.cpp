//
// Created by Admin on 22/02/2025.
//

// dear imgui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)

#include <MyEngine/Engine.h>
#include <MyEngine/SceneMngr.h>

#include "Editor.h"

#include <string>

using namespace My;
using namespace std;

int main(int, char**) {
  Scene scene("scene");

  auto [sobj0, tsfm0, camera] = scene.CreateSObj<Cmpt::Camera>("sobj0");
  auto [sobj1, tsfm1, geo1, mat1] =
      scene.CreateSObj<Cmpt::Geometry, Cmpt::Material>("sobj1");
  auto [sobj2, tsfm2, geo2, mat2] =
      scene.CreateSObj<Cmpt::Geometry, Cmpt::Material>("sobj2");
  auto [sobj3, tsfm3, geo3, mat3] =
      scene.CreateSObj<Cmpt::Geometry, Cmpt::Material>("sobj3");
  auto [sobj4, tsfm4, light4] = scene.CreateSObj<Cmpt::Light>("sobj4");

  geo1->SetPrimitive(new Sphere);
  geo2->SetPrimitive(new Square);
  geo3->SetPrimitive(new TriMesh(TriMesh::Type::Cube));
  auto brdf1 = new stdBRDF;
  auto brdf2 = new stdBRDF;
  auto brdf3 = new stdBRDF;
  string albedo_path = "../data/textures/rusted_iron/albedo.png";
  string roughness_path = "../data/textures/rusted_iron/roughness.png";
  string metalness_path = "../data/textures/rusted_iron/metallic.png";
  string normal_path = "../data/textures/rusted_iron/normal.png";
  brdf1->albedo_texture =
      ResourceMngr<Image>::Instance().GetOrCreate(albedo_path, albedo_path);
  brdf1->roughness_texture = ResourceMngr<Image>::Instance().GetOrCreate(
      roughness_path, roughness_path);
  brdf1->metalness_texture = ResourceMngr<Image>::Instance().GetOrCreate(
      metalness_path, metalness_path);
  brdf1->normal_map =
      ResourceMngr<Image>::Instance().GetOrCreate(normal_path, normal_path);
  brdf2->albedo_texture =
      ResourceMngr<Image>::Instance().GetOrCreate(albedo_path, albedo_path);
  brdf2->roughness_texture = ResourceMngr<Image>::Instance().GetOrCreate(
      roughness_path, roughness_path);
  brdf2->metalness_texture = ResourceMngr<Image>::Instance().GetOrCreate(
      metalness_path, metalness_path);
  brdf2->normal_map =
      ResourceMngr<Image>::Instance().GetOrCreate(normal_path, normal_path);
  brdf3->albedo_texture =
      ResourceMngr<Image>::Instance().GetOrCreate(albedo_path, albedo_path);
  brdf3->roughness_texture = ResourceMngr<Image>::Instance().GetOrCreate(
      roughness_path, roughness_path);
  brdf3->metalness_texture = ResourceMngr<Image>::Instance().GetOrCreate(
      metalness_path, metalness_path);
  brdf3->normal_map =
      ResourceMngr<Image>::Instance().GetOrCreate(normal_path, normal_path);
  mat1->SetMaterial(brdf1);
  mat2->SetMaterial(brdf2);
  mat3->SetMaterial(brdf3);

  tsfm0->SetPosition({0, 0, 8});
  tsfm1->SetPosition({-4, 0, 0});
  tsfm1->SetScale({2.f});
  tsfm2->SetRotation({vecf3{1, 0, 0}, to_radian(45.f)});
  tsfm3->SetPosition({4, 0, 0});
  tsfm3->SetScale({1, 2, 1});
  tsfm3->SetRotation({vecf3{1, 2, 1}.normalize(), to_radian(45.f)});
  camera->Init(to_radian(60.f), 1280 / static_cast<float>(720));

  light4->light = new PointLight{100.f, {0.9f, 0.9f, 1.f}};
  tsfm4->SetPosition({0, 4, 0});

  Editor::Instance().SetCamera(sobj0);
  SceneMngr::Instance().Active(&scene, Editor::Instance().roamerobj);

  Engine::Instance().Init("Ubpa@2020 UEditor v0.0.1");

  // Main loop
  Engine::Instance().Loop([&]() { Editor::Instance().Update(); });

  // Cleanup
  Engine::Instance().CleanUp();

  return 0;
}
