#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D ourTexture;
void main()
{

    if (texture(ourTexture,TexCoord).r < 0.1)
        discard;

    FragColor = vec4(0,1,1,1);
};