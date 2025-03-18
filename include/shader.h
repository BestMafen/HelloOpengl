#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    GLuint ID;
    // constructor generates the shader on the fly
    // ------------------------------------------------------------------------
    Shader(const char *vertexPath, const char *fragmentPath, const char *geometryPath = nullptr)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string geometryCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream gShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        gShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexPath);
            if (geometryPath != nullptr)
                gShaderFile.open(geometryPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, gShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            if (geometryPath != nullptr)
                gShaderStream << gShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            if (geometryPath != nullptr)
                gShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            if (geometryPath != nullptr)
                geometryCode = gShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure& e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
        }
        const char *vShaderCode = vertexCode.c_str();
        const char *fShaderCode = fragmentCode.c_str();
        const char *gShaderCode = nullptr;
        if (geometryPath != nullptr)
            gShaderCode = geometryCode.c_str();
        // 2. compile shaders
        GLuint vertex, geometry, fragment;
        // vertex shader
        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, nullptr);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");
        // vertex shader
        if (geometryPath != nullptr)
        {
            geometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geometry, 1, &gShaderCode, nullptr);
            glCompileShader(geometry);
            checkCompileErrors(geometry, "GEOMETRY");
        }
        // fragment Shader
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, nullptr);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");
        // shader Program
        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        if (geometryPath != nullptr)
            glAttachShader(ID, geometry);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");
        // delete the shaders as they're linked into our program now and no longer necessary
        glDeleteShader(vertex);
        if (geometryPath != nullptr)
            glDeleteShader(geometry);
        glDeleteShader(fragment);
    }

    // activate the shader
    // ------------------------------------------------------------------------
    void use() const
    {
        glUseProgram(ID);
    }

    // utility uniform functions
    // ------------------------------------------------------------------------
    void setBool(const std::string& name, const bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<GLint>(value));
    }

    // ------------------------------------------------------------------------
    void setInt(const std::string& name, const GLint value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }

    // ------------------------------------------------------------------------
    void setFloat(const std::string& name, const GLfloat value) const
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }

    void setMatrix4fv(const std::string& name, GLboolean transpose, const GLfloat *value) const
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, transpose, value);
    }

    void setVec3(const std::string& name, GLfloat v0, GLfloat v1, GLfloat v2) const
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), v0, v1, v2);
    }
    
private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    static void checkCompileErrors(const GLuint shader, const std::string& type)
    {
        GLint success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog <<
                    "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog <<
                    "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
};
#endif
