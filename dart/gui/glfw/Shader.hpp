#ifndef DART_GUI_GLFW_SHADER_HPP_
#define DART_GUI_GLFW_SHADER_HPP_

#include <string>
#include <Eigen/Dense>

#include "dart/gui/glfw/LoadGlfw.hpp"

namespace dart {

class Shader final
{
public:
  Shader(
      const std::string& vertexShaderFilename = "",
      const std::string& fragmentShaderFilename = "");
  // TODO: remove the default parameters

  ~Shader() = default;

  void bind();

  void unbind();

  GLint getUniformLocation(
      const std::string& variableName, bool errorIfMissing = true) const;

  GLint getAttribLocation(
      const std::string& variableName, bool errorIfMissing = true) const;

  void setFloatUniform(
      const std::string& variableName,
      float value,
      bool errorIfMissing = true) const;

  void setIntUniform(
      const std::string& variableName,
      int value,
      bool errorIfMissing = true) const;

  void setVector2Uniform(
      const std::string& variableName,
      const Eigen::Vector2f& v,
      bool errorIfMissing = true) const;

  void setVector3Uniform(
      const std::string& variableName,
      const Eigen::Vector3f& v,
      bool errorIfMissing = true) const;

  void setVector4Uniform(
      const std::string& variableName,
      const Eigen::Vector4f& v,
      bool errorIfMissing = true) const;

  void setMatrix3x3Uniform(
      const std::string& variableName,
      const float* matrix,
      bool transpose = false,
      bool errorIfMissing = true) const;

  void setMatrix3x3Uniform(
      const std::string& variableName,
      const Eigen::Matrix3f& matrix,
      bool errorIfMissing = true) const;

  void setMatrix4x4Uniform(
      const std::string& variableName,
      const float* matrix,
      bool transpose = false,
      bool errorIfMissing = true) const;

  void setMatrix4x4Uniform(
      const std::string& variableName,
      const Eigen::Matrix4f& matrix,
      bool errorIfMissing = true) const;

  void setMatrix4x4Uniform(
      const std::string& variableName,
      const Eigen::Affine3f& matrix,
      bool errorIfMissing = true) const;

  void setMatrix4x4Uniform(
      const std::string& variableName,
      const Eigen::Isometry3f& matrix,
      bool errorIfMissing = true) const;

  static bool checkOpenGLExtensions();

protected:
  GLuint mProgramObjectID;

  std::string mVertexShaderFilename;

  std::string mFragmentShaderFilename;
};

} // namespace dart

#endif // DART_GUI_GLFW_SHADER_HPP_
