# Install script for directory: D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/Debug/assimpd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/Release/assimp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/MinSizeRel/assimp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/RelWithDebInfo/assimp.lib")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.1.1")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/Debug/assimpd.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/Release/assimp.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/MinSizeRel/assimp.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/Build/code/RelWithDebInfo/assimp.dll")
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/anim.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/ai_assert.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/camera.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/color4.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/color4.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/config.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/defs.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/cfileio.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/light.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/material.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/material.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/matrix3x3.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/matrix3x3.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/matrix4x4.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/matrix4x4.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/mesh.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/postprocess.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/quaternion.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/quaternion.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/scene.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/metadata.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/texture.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/types.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/vector2.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/vector2.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/vector3.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/vector3.inl"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/version.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/cimport.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/importerdesc.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/Importer.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/DefaultLogger.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/ProgressHandler.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/IOStream.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/IOSystem.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/Logger.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/LogStream.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/NullLogger.hpp"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/cexport.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/Exporter.hpp"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "assimp-dev")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/Compiler/pushpack1.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/Compiler/poppack1.h"
    "D:/Projects/Coding/3DGE/game-project/3DGE-TeamProject-Structure/assets/imported_libs/ASSIMP/assimp-3.1.1/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

