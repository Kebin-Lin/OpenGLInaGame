#include "pch.h"
#include "../FoundryUtil.h"
#include "OpenGLShader.h"
#include "glad/glad.h"

// Can use perfect forwarding so only one definition is needed
namespace Foundry {
    OpenGLShader::OpenGLShader(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) {
        std::string vertexCode;
        std::ifstream vertexSource{vertexShaderFile};

        if (!vertexSource.is_open()) {
            FOUNDRY_LOG("ERROR: Failed to open vertex shader file!");
        }

        std::stringstream vertexTemp;
        vertexTemp << vertexSource.rdbuf();
        vertexCode = vertexTemp.str();
        const char* ansiVertex{vertexCode.c_str()};

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &ansiVertex, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        // check for linking errors
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            FOUNDRY_LOG("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
            FOUNDRY_LOG(infoLog);
        }

        // Fragment Shader Setup
        std::string fragmentCode;
        std::ifstream fragmentSource{fragmentShaderFile};

        if (!fragmentSource.is_open()) {
            FOUNDRY_LOG("ERROR: Failed to open fragment shader file!");
        }

        std::stringstream fragmentTemp;
        fragmentTemp << fragmentSource.rdbuf();
        fragmentCode = fragmentTemp.str();
        const char* ansiFragment{fragmentCode.c_str()};

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &ansiFragment, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            FOUNDRY_LOG("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
            FOUNDRY_LOG(infoLog);
        }

        // Set up shader program and link vertex + fragment shaders
        mShaderProg = glCreateProgram();
        glAttachShader(mShaderProg, vertexShader);
        glAttachShader(mShaderProg, fragmentShader);
        glLinkProgram(mShaderProg);
        // check for linking errors
        glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
            FOUNDRY_LOG("ERROR::SHADER::PROGRAM::LINKING_FAILED");
            FOUNDRY_LOG(infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    OpenGLShader::OpenGLShader(std::string&& vertexShaderFile, std::string&& fragmentShaderFile) {
        std::string vertexCode;
        std::ifstream vertexSource{vertexShaderFile};

        if (!vertexSource.is_open()) {
            FOUNDRY_LOG("ERROR: Failed to open vertex shader file!");
        }

        std::stringstream vertexTemp;
        vertexTemp << vertexSource.rdbuf();
        vertexCode = vertexTemp.str();
        const char* ansiVertex{vertexCode.c_str()};

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &ansiVertex, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        // check for linking errors
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            FOUNDRY_LOG("ERROR::SHADER::VERTEX::COMPILATION_FAILED");
            FOUNDRY_LOG(infoLog);
        }

        // Fragment Shader Setup
        std::string fragmentCode;
        std::ifstream fragmentSource{fragmentShaderFile};

        if (!fragmentSource.is_open()) {
            FOUNDRY_LOG("ERROR: Failed to open fragment shader file!");
        }

        std::stringstream fragmentTemp;
        fragmentTemp << fragmentSource.rdbuf();
        fragmentCode = fragmentTemp.str();
        const char* ansiFragment{fragmentCode.c_str()};

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &ansiFragment, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            FOUNDRY_LOG("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED");
            FOUNDRY_LOG(infoLog);
        }

        // Set up shader program and link vertex + fragment shaders
        mShaderProg = glCreateProgram();
        glAttachShader(mShaderProg, vertexShader);
        glAttachShader(mShaderProg, fragmentShader);
        glLinkProgram(mShaderProg);
        // check for linking errors
        glGetProgramiv(mShaderProg, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(mShaderProg, 512, NULL, infoLog);
            FOUNDRY_LOG("ERROR::SHADER::PROGRAM::LINKING_FAILED");
            FOUNDRY_LOG(infoLog);
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void OpenGLShader::activate() {
        glUseProgram(mShaderProg);
    }

    void OpenGLShader::provideFloatValues(const std::string& valueName, const std::vector<float>& values) {
        activate();

        GLint location{glGetUniformLocation(mShaderProg, valueName.c_str())};

        switch(values.size()) {
            case 1:
                glUniform1f(location, values[0]);
                break;
            case 2:
                glUniform2f(location, values[0], values[1]);
                break;
            case 3:
                glUniform3f(location, values[0], values[1], values[2]);
                break;
            case 4:
                glUniform4f(location, values[0], values[1], values[2], values[3]);
                break;
            default:
                FOUNDRY_LOG("ERROR: Shader values must be vectors of size 1 to 4");
        }
    }

    void OpenGLShader::provideFloatValues(std::string&& valueName, std::vector<float>&& values) {
        activate();

        GLint location{glGetUniformLocation(mShaderProg, valueName.c_str())};
        
        switch(values.size()) {
            case 1:
                glUniform1f(location, values[0]);
                break;
            case 2:
                glUniform2f(location, values[0], values[1]);
                break;
            case 3:
                glUniform3f(location, values[0], values[1], values[2]);
                break;
            case 4:
                glUniform4f(location, values[0], values[1], values[2], values[3]);
                break;
            default:
                FOUNDRY_LOG("ERROR: Shader values must be vectors of size 1 to 4");
        }
    }
}