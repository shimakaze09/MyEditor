/*
    Generated by My::UScene_parser
    Any changes to this file will be overwritten by the next CMake run
    ----
    Usage:
        #include "this-file" // in cpp
*/

#include <MyDP/Reflection/Reflection.h>

#include <MyScene/core/SObj.h>

namespace My::Cmpt::detail::dynamic_reflection {
void ReflRegist_Inspector() {
  Reflection<Inspector>::Instance()  // name : class My::Cmpt::Inspector
      .Regist("description", "SObj's components Viewer");
  if constexpr (std::is_base_of_v<Component, Inspector>) {
    Reflection<Inspector>::Instance().RegistConstructor([](SObj* sobj) {
      if constexpr (std::is_base_of_v<Component, Inspector>) {
        if constexpr (My::detail::SObj_::IsNecessaryCmpt<Inspector>)
          return sobj->Get<Inspector>();
        else
          return sobj->GetOrAttach<Inspector>();
      };
    });
  }
}
}  // namespace My::Cmpt::detail::dynamic_reflection
