#version 330

varying vec2 texCoord0;

uniform sampler2D diffuse;

void main()
{
    gl_FragColor = vec4(0.0, 0.2, 0.5, 1.0);
}