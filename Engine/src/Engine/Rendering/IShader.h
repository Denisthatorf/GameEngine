#pragma once
#include <string>

class IShader {
public:
    virtual ~IShader() = default;

    virtual void Bind() = 0;
    virtual void Load(const std::string&& vertexShader, const std::string&& fragmentShader) = 0;
};

