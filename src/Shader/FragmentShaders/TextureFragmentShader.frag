#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 color;

uniform sampler2D uploadedTexture;

void main() {
    color = texture(uploadedTexture, TexCoord);
}
