#version 330 core

out vec4 fragColor;

in vec3 texCoord;

uniform sampler2D texture1;

void main() {
    fragColor = texture(texture1, texCoord);
}